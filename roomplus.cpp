#include "room.h"
#include "roomplus.h"
#include <string>
#include <random>
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Construct a new Lobby:: Lobby object
 *
 * @param num the number of the room
 */

Lobby::Lobby(int num)
    : Room(num, "Lobby", false, false, true) {}

/**
 * @brief Construct a new Room_Princess::Room_Princess object
 *
 * @param num the number of the room
 * @param name the name of the room
 */

Room_Princess::Room_Princess(int num, string name)
    : Room(num, name + " (Princess Room)", true, false, false) {}

/**
 * @brief Construct a new Room_Monster::Room_Monster object
 *
 * @param num the number of the room
 * @param name the name of the room
 */

Room_Monster::Room_Monster(int num, string name)
    : Room(num, name + " (Monster Room)", false, true, false) {}

/**
 * @brief play in the monster's room
 *
 * @return Room* return NULL as the player is dead
 */

Room *Room_Monster::play()
{
    printMessage();
    return NULL;
}

/**
 * @brief pirnt message of the monster's room
 *
 */

void Room_Monster::printMessage()
{
    cout << "*********************************************************" << endl;
    cout << "You have encountered a monster!" << endl;
    cout << "***************** Fighting with monster *****************" << endl;
    cout << "You are killed by the monster." << endl;
    cout << "*********************** Game Over ***********************" << endl;
}

/**
 * @brief print the message of the princess's room
 *
 */

void Room_Princess::printMessage()
{
    cout << "*********************************************************" << endl;
    cout << "You have found the princess!" << endl;
    cout << "Congratulations!" << endl;
    cout << "Now you need to go back to the Lobby" << endl;
    cout << "with the princess to get out of this maze." << endl;
    cout << "Be careful about the monster!" << endl;
    cout << "Good luck!" << endl;
}

/**
 * @brief play in the princess's room
 *
 * @return Room*
 */

Room *Room_Princess::play()
{
    printMessage();
    return (Room::play());
}

/**
 * @brief print message when win the current level
 *
 */

void Lobby::End()
{
    cout << "*********************************************************" << endl;
    cout << "You wins in this level!" << endl;
    cout << "Congratulations!" << endl;
    return;
}