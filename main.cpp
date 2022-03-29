#include "room.h"
#include "map.h"
#include "roomplus.h"
#include <string>
#include <random>
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief print the help message
 *
 */

void printHint()
{
    cout << "*********************************************************" << endl;
    cout << "This is a CLI game of \"The Maze\"." << endl;
    cout << "You are in a maze of rooms." << endl;
    cout << "At the beginning of the game, you are in the Lobby." << endl;
    cout << "You can move to the north, south, east, or west." << endl;
    cout << "One of the rooms has a monster." << endl;
    cout << "One of the rooms has a princess." << endl;
    cout << "You goal is to find the room where" << endl;
    cout << "the princess is prisoned and take her leave." << endl;
    cout << "The only way to leave is to get into the Lobby." << endl;
    cout << "When you get to the monster's room, you fail." << endl;
    cout << "You can only take one step at a time." << endl;
    cout << "There are 3 levels of difficulty." << endl;
    cout << "The game will be over when you win all 3 levels" << endl;
    cout << "You can also type \"help\" to see the commands." << endl;
    cout << "Good luck!" << endl;
    cout << "*********************************************************" << endl;
    cout << endl;
    return;
}

/**
 * @brief print the success message
 *
 */

void success()
{
    cout << "*********************************************************" << endl;
    cout << "You have won all 3 levels!" << endl;
    cout << "Thank you for playing!" << endl;
    cout << "*********************************************************" << endl;
    return;
}

/**
 * @brief the main function
 *
 * @return int
 */

int main()
{
    printHint();       // print the hint
    bool test = false; // test mode
    while (1)
    {
        cout << "Do you want to enter the game with test mood? (y/n)" << endl;
        string mood;
        cin >> mood;
        if (mood == "y") // if yes, enter test mode
        {
            test = true;
            cout << "You are now in the test mood" << endl;
            cout << "The location of the princess and the monster is fixed" << endl;
            cout << "You can input what is written" << endl;
            cout << "in the textfile \"test.txt\" to test the game" << endl;
            break;
        }
        else if (mood == "n") // if no, enter normal mode
        {
            test = false;
            cout << "You are now in the normal mood" << endl;
            cout << "The location of the princess and the monster is random" << endl;
            cout << "Enjoy your game!" << endl;
            break;
        }
        else // if input is not y or n, print error message
        {
            cout << "Please input \"y\" or \"n\"" << endl;
        }
    }

    for (int i = 1; i <= 3; i++) // loop for 3 levels
    {
        cout << "*********************************************************" << endl;
        cout << "Level " << i << endl;
        Map map(i, test); // create a map
        map.play();       // play the game
    }
    success(); // print success message
    return 0;
}