#include "room.h"
#include "map.h"
#include "roomplus.h"
#include <string>
#include <random>
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Construct a new Map:: Map object
 *
 * @param level the chosen level
 * @param test whether the game is in test mode
 */

Map::Map(int level, bool test) : roomNum(level * 7), mapLevel(level), test(test)
{
    int where_pri;
    int where_mon;
    if (!test) // if the game is in normal mode
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, roomNum - 1);
        /**
         *  generate a random number between 1 and roomNum - 1
         *  to determine the location of the princess and monster
         *  and make sure they are not in the Lobby
         */
        where_pri = dis(gen);
        while ((where_mon = dis(gen)) == where_pri);
        // make sure the princess and monster are not in the same room
    }
    else // if the game is in test mode
    {
        where_pri = roomNum - 1; // the princess is always in the last room
        where_mon = 1;           // the monster is always in the first room
    }
    roomList.push_back(new Lobby(0)); // the first room is the lobby
    for (int i = 1; i < roomNum; i++) // generate other rooms
    {
        bool princess = false, monster = false, lobby = false;
        string append = "";
        if (i == where_pri) // if the room is the princess's room
            roomList.push_back(new Room_Princess(i, "Room " + to_string(i)));
        else if (i == where_mon) // if the room is the monster's room
            roomList.push_back(new Room_Monster(i, "Room " + to_string(i)));
        else // if the room is a normal room
            roomList.push_back(new Room(i, "Room " + to_string(i)));
    }

    if (mapLevel == 1) // create the map of level 1
    {
        roomList[0]->setNorth(roomList[3]);
        roomList[3]->setSouth(roomList[0]);

        roomList[4]->setNorth(roomList[0]);
        roomList[0]->setSouth(roomList[4]);

        roomList[1]->setNorth(roomList[2]);
        roomList[2]->setSouth(roomList[1]);

        roomList[5]->setNorth(roomList[6]);
        roomList[6]->setSouth(roomList[5]);

        roomList[2]->setEast(roomList[3]);
        roomList[3]->setWest(roomList[2]);

        roomList[1]->setEast(roomList[0]);
        roomList[0]->setWest(roomList[1]);

        roomList[0]->setEast(roomList[6]);
        roomList[6]->setWest(roomList[0]);

        roomList[4]->setEast(roomList[5]);
        roomList[5]->setWest(roomList[4]);
    }
    else if (mapLevel == 2) // create the map of level 2
    {
        roomList[12]->setNorth(roomList[13]);
        roomList[13]->setSouth(roomList[12]);

        roomList[13]->setNorth(roomList[0]);
        roomList[0]->setSouth(roomList[13]);

        roomList[0]->setNorth(roomList[1]);
        roomList[1]->setSouth(roomList[0]);

        roomList[1]->setNorth(roomList[2]);
        roomList[2]->setSouth(roomList[1]);

        roomList[5]->setNorth(roomList[4]);
        roomList[4]->setSouth(roomList[5]);

        roomList[4]->setNorth(roomList[3]);
        roomList[3]->setSouth(roomList[4]);

        roomList[11]->setNorth(roomList[8]);
        roomList[8]->setSouth(roomList[11]);

        roomList[8]->setNorth(roomList[10]);
        roomList[10]->setSouth(roomList[8]);

        roomList[6]->setEast(roomList[5]);
        roomList[5]->setWest(roomList[6]);

        roomList[5]->setEast(roomList[12]);
        roomList[12]->setWest(roomList[5]);

        roomList[4]->setEast(roomList[13]);
        roomList[13]->setWest(roomList[4]);

        roomList[3]->setEast(roomList[0]);
        roomList[0]->setWest(roomList[3]);

        roomList[0]->setEast(roomList[7]);
        roomList[7]->setWest(roomList[0]);

        roomList[7]->setEast(roomList[8]);
        roomList[8]->setWest(roomList[7]);

        roomList[8]->setEast(roomList[9]);
        roomList[9]->setWest(roomList[8]);
    }
    else if (mapLevel == 3) // create the map of level 3
    {
        roomList[0]->setNorth(roomList[1]);
        roomList[1]->setSouth(roomList[0]);

        roomList[1]->setNorth(roomList[2]);
        roomList[2]->setSouth(roomList[1]);

        roomList[7]->setNorth(roomList[12]);
        roomList[12]->setSouth(roomList[7]);

        roomList[8]->setNorth(roomList[10]);
        roomList[10]->setSouth(roomList[8]);

        roomList[11]->setNorth(roomList[8]);
        roomList[8]->setSouth(roomList[11]);

        roomList[15]->setNorth(roomList[11]);
        roomList[11]->setSouth(roomList[15]);

        roomList[19]->setNorth(roomList[15]);
        roomList[15]->setSouth(roomList[19]);

        roomList[18]->setNorth(roomList[19]);
        roomList[19]->setSouth(roomList[18]);

        roomList[16]->setNorth(roomList[14]);
        roomList[14]->setSouth(roomList[16]);

        roomList[17]->setNorth(roomList[16]);
        roomList[16]->setSouth(roomList[17]);

        roomList[4]->setNorth(roomList[3]);
        roomList[3]->setSouth(roomList[4]);

        roomList[5]->setNorth(roomList[4]);
        roomList[4]->setSouth(roomList[5]);

        roomList[3]->setEast(roomList[0]);
        roomList[0]->setWest(roomList[3]);

        roomList[0]->setEast(roomList[7]);
        roomList[7]->setWest(roomList[0]);

        roomList[7]->setEast(roomList[8]);
        roomList[8]->setWest(roomList[7]);

        roomList[8]->setEast(roomList[9]);
        roomList[9]->setWest(roomList[8]);

        roomList[6]->setEast(roomList[5]);
        roomList[5]->setWest(roomList[6]);

        roomList[5]->setEast(roomList[13]);
        roomList[13]->setWest(roomList[5]);

        roomList[13]->setEast(roomList[14]);
        roomList[14]->setWest(roomList[13]);

        roomList[14]->setEast(roomList[15]);
        roomList[15]->setWest(roomList[14]);

        roomList[1]->setEast(roomList[12]);
        roomList[12]->setWest(roomList[1]);

        roomList[12]->setEast(roomList[10]);
        roomList[10]->setWest(roomList[12]);

        roomList[16]->setEast(roomList[19]);
        roomList[19]->setWest(roomList[16]);

        roomList[17]->setEast(roomList[18]);
        roomList[18]->setWest(roomList[17]);

        roomList[18]->setEast(roomList[20]);
        roomList[20]->setWest(roomList[18]);
    }
}

/**
 * @brief play in the current map
 *
 */

void Map::play()
{
    Room *currentRoom = roomList[0];    // start in the first room
    while (!currentRoom->hasPrincess()) // while the princess is not in the room
    {
        currentRoom = (currentRoom->play()); // go to the next room
        if (currentRoom == NULL)             // in case the player is in a room that doesn't exist
            exit(0);                         // exit the game
        if (currentRoom->hasMonster())       // encounter a monster
        {
            currentRoom->play(); // fight the monster
            exit(0);             // exit the game
        }
    }

    // after the loop, the player has found the princess
    // what he is going to do is to find the lobby

    while (!currentRoom->isLobby()) // while the player is not in the lobby
    {
        currentRoom = (currentRoom->play()); // go to the next room
        if (currentRoom == NULL)             // in case the player is in a room that doesn't exist
            exit(0);                         // exit the game
        if (currentRoom->hasMonster())       // encounter a monster
        {
            currentRoom->play(); // fight the monster
            exit(0);             // exit the game
        }
    }
    currentRoom->End(); // the player has found the lobby, go to the end of the current level
}