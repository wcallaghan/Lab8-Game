// structure definitions and function prototypes maze navigation assignment
// Mikhail Nesterenko
// 10/21/2022

#include <cstdlib>
#include <ctime>
#include<string>

#ifndef MAZE_HPP_
#define MAZE_HPP_

const int mazeSize = 4; // maze is mazeSize * mazeSize
const int numWalls = 8;  // number of internal walls

//
// data structures definitions
//

struct Room {
    int x;  // 1 through mazeSize
    char y; // 'a' through mazeSize
};

const Room startRoom = { 1, 'a' };
const Room cheeseRoom = { mazeSize, 'a' + mazeSize - 1 };

// internal wall or next move
struct RoomPair {
    Room one;
    Room two;
};

//
// initialization functions
//
int RandNum();  //generate a random number

void clearWalls(RoomPair[]); // places every RoomPair to connect two non-existing rooms
                         // where x-coordinate is -1
                         // and y-coordinate is '*' (a star) to signify
                         // that the wall is not built yet

const RoomPair pickWall(); // generates a random wall

bool matchRoom(const Room&, const Room&); // returns true if the two rooms are the same
bool matchPair(const RoomPair&, const RoomPair&); // returns true if two pairs of 
                                                  // adjacent rooms are the same, 
                                                  // returns false otherwise, 
                                                  // uses matchRoom()
                                                  // note that r1|r2 matches r2|r1

int checkMaze(const RoomPair[], const RoomPair); // returns the index of
                                      // element of the array of RoomPair (walls) that 
                                      // separates RoomPair, returns -1 if none do
                                      // uses matchPair()
void build(RoomPair[]); // places internal walls in random locations of the maze

//
// display functions
//
void printRoom(const Room&); // prints the location of the room
void printPair(const RoomPair&); // prints the locations of the adjacent rooms
void printMaze(const RoomPair[]); // prints the locations of all the internal walls of the maze
                              // uses printPair

//
// game functions
//
const Room nextMove(const Room& currentRoom); // asks the user for the room to move
char getAnswer(string);                                             // adjacent to currentRoom

// note that checkMaze() and matchRoom() are also  used in the game

#endif // MAZE_HPP_#pragma once
