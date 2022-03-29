#ifndef __ROOMPLUS_H__
#define __ROOMPLUS_H__

#include "room.h"
#include <string>
#include <random>
#include <iostream>
#include <vector>

/**
 * @brief define the class of Lobby
 *
 */

class Lobby : public Room
{
public:
    Lobby(int num);
    ~Lobby() { delete roomdoor; };
    void End();
};

/**
 * @brief define the class of the princess's room
 *
 */

class Room_Princess : public Room
{
public:
    Room_Princess(int num, string name);
    ~Room_Princess() { delete roomdoor; };
    Room *play();

private:
    void printMessage();
};

/**
 * @brief define the class of the monster's room
 *
 */

class Room_Monster : public Room
{
public:
    Room_Monster(int num, string name);
    ~Room_Monster() { delete roomdoor; };
    Room *play();

private:
    void printMessage();
};

#endif