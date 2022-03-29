#ifndef __ROOM_H__
#define __ROOM_H__

#include <string>
#include <random>
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief define the class of Room
 *
 */

class Room
{
private:
    typedef struct door // define the struct of the door
    {
        Room *west;
        Room *east;
        Room *north;
        Room *south;
    } Door;
    int num;     // the number of the room
    string name; // the name of the room
    bool princess, monster, lobby;
    // whether the room has princess, monsters, and lobby

protected:
    Door *roomdoor; // the door of the room

public:
    Room(int num, string name, bool princess = false,
         bool monster = false, bool lobby = false);
    virtual ~Room() { delete roomdoor; } // destructor

private:
    Room *toNorth() { return roomdoor->north; }; // go to the north
    Room *toSouth() { return roomdoor->south; }; // go to the south
    Room *toEast() { return roomdoor->east; };   // go to the east
    Room *toWest() { return roomdoor->west; };   // go to the west

protected:
    Room *inputMessage();
    virtual void printMessage();

public:
    bool hasPrincess() { return princess; };             // whether the room has princess
    bool hasMonster() { return monster; };               // whether the room has monsters
    bool isLobby() { return lobby; };                    // whether the room is lobby
    void setNorth(Room *x) { roomdoor->north = x; }      // set the north door
    void setSouth(Room *x) { roomdoor->south = x; }      // set the south door
    void setEast(Room *x) { roomdoor->east = x; }        // set the east door
    void setWest(Room *x) { roomdoor->west = x; }        // set the west door
    bool NorthOpen() { return roomdoor->north != NULL; } // whether the north door is open
    bool SouthOpen() { return roomdoor->south != NULL; } // whether the south door is open
    bool EastOpen() { return roomdoor->east != NULL; }   // whether the east door is open
    bool WestOpen() { return roomdoor->west != NULL; }   // whether the west door is open
    virtual Room *play();
    virtual void End() {}
    void outputHelp();
};

#endif
