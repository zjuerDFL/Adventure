#ifndef __MAP_H__
#define __MAP_H__

#include "room.h"
#include "roomplus.h"
#include <string>
#include <random>
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief define the map of the game
 *
 */

class Map
{
private:
    int roomNum;  // the number of the room in the map
    int mapLevel; // the level of the map
    int test;     // whether it is test mood
    vector<Room *> roomList;
    // roomList to store all the rooms in the map

public:
    Map(int level, bool test);
    ~Map() // destructor
    {
        roomList.clear();
        // delete all the rooms in the map
    };
    void play(void);
};

#endif