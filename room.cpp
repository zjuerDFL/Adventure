#include "room.h"
#include <string>
#include <random>
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Construct a new Room:: Room object
 *
 * @param num the number of the room
 * @param name the name of the room
 * @param princess whether the room has princess
 * @param monster whether the room has monsters
 * @param lobby whether the room is Lobby
 */

Room::Room(int num, string name, bool princess,
           bool monster, bool lobby)
    : num(num), name(name), princess(princess),
      monster(monster), lobby(lobby), roomdoor(new Door())
{
    roomdoor->north = NULL;
    roomdoor->south = NULL;
    roomdoor->east = NULL;
    roomdoor->west = NULL;
    // set all the doors to NULL
}

/**
 * @brief play in the room
 *
 * @return Room* the next room to go
 */

Room *Room::play()
{
    Room::printMessage();
    return (inputMessage());
}

/**
 * @brief print the message of the room
 *
 */

void Room::printMessage()
{
    int numOfDoors = NorthOpen() + SouthOpen() + EastOpen() + WestOpen();
    // count the number of the doors
    cout << endl;
    cout << "Welcome to the " << name << "." << endl;
    if (numOfDoors > 1)
        cout << "There are " << numOfDoors << " exits: " << endl;
    else if (numOfDoors == 1)
        cout << "There is " << numOfDoors << " exit: " << endl;
    else
        cout << "There are no exits." << endl;

    int count = numOfDoors;

    if (NorthOpen())
    {
        count--;
        if (count)
            cout << "up, ";
        else if (!count && numOfDoors == 1)
            cout << "up.";
        else
            cout << "and up.";
    }
    if (SouthOpen())
    {
        count--;
        if (count)
            cout << "down, ";
        else if (!count && numOfDoors == 1)
            cout << "down.";
        else
            cout << "and down.";
    }
    if (EastOpen())
    {
        count--;
        if (count)
            cout << "east, ";
        else if (!count && numOfDoors == 1)
            cout << "east.";
        else
            cout << "and east.";
    }
    if (WestOpen())
    {
        count--;
        if (count)
            cout << "west, ";
        else if (!count && numOfDoors == 1)
            cout << "west.";
        else
            cout << "and west.";
    }
    cout << endl;
    // output the specific doors
}

/**
 * @brief input what the player choose to do
 *
 * @return Room* the next room to go
 */

Room *Room::inputMessage()
{
    while (1)
    {
        cout << "Enter your command:" << endl;
        cout << "(in the form of \"go <direction>\")" << endl;
        string strgo;
        cin >> strgo;
        if (strgo != "go")
        {
            if (strgo == "quit")
            {
                cout << "*********************************************************" << endl;
                cout << "You have chosen to quit the game." << endl;
                cout << "*********************************************************" << endl;
                exit(0);
                // exit the game
            }
            if (strgo == "help")
            {
                outputHelp();
                continue;
                // output the help message
            }
            cout << "That is not a valid command." << endl
                 << endl;
            continue;
        }
        string input;
        cin >> input;
        // input the command
        if (input == "east")
        {
            if (EastOpen())
                return (toEast());
            else
            {
                cout << "You can't go that way." << endl
                     << endl;
                continue;
            }
        }
        else if (input == "west")
        {
            if (WestOpen())
                return (toWest());
            else
            {
                cout << "You can't go that way." << endl
                     << endl;
                continue;
            }
        }
        else if (input == "up")
        {
            if (NorthOpen())
                return (toNorth());
            else
            {
                cout << "You can't go that way." << endl
                     << endl;
                continue;
            }
        }
        else if (input == "down")
        {
            if (SouthOpen())
                return (toSouth());
            else
            {
                cout << "You can't go that way." << endl
                     << endl;
                continue;
            }
        }
        else
        {
            cout << "That is not a valid command." << endl
                 << endl;
            continue;
        }
    }
}

/**
 * @brief output the help message
 *
 */

void Room::outputHelp()
{
    cout << "*********************************************************" << endl;
    cout << "You have chosen to view the help menu." << endl;
    cout << "*********************************************************" << endl;
    cout << "The commands you can use are:" << endl;
    cout << "go <direction>" << endl;
    cout << "quit" << endl;
    cout << "help" << endl;
    cout << "*********************************************************" << endl
         << endl;
}