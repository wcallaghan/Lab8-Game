#include"maze.hpp"
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

using std::cout; using std::cin; using std::endl;
string firstQuestion = "Do you want to see the maze? yes: 'y' or no: 'n'";
string secondQuestion = "Would you like to move the mouse? Yes: 'y' or No: 'n'";
string exitClause = "To quit enter 'q'.";
int main() {
	srand(time(nullptr));

	char answer = getAnswer(firstQuestion);

	while (answer != 'q') {

		//bulid maze
		Room currentRoom = startRoom;
		Room Maze[mazeSize * mazeSize];


		//create walls
		RoomPair Walls[numWalls];
		clearWalls(Walls);
		build(Walls);

		//add walls to maze
		for (int i = 0; i < numWalls; ++i) {
			int* firstWallX = &Walls[i].one.x;
			int* secondWallX = &Walls[i].two.x;
			char* firstWallY = &Walls[i].one.y;
			char* secondWallY = &Walls[i].two.y;

			Maze[i].x = *firstWallX;
			Maze[i + 1].x = *secondWallX;

			Maze[i].y = *firstWallY;
			Maze[i + 1].y = *secondWallY;
		}


		//add starting and cheese room
		Maze[0] = startRoom;
		Maze[15] = cheeseRoom;

		if (answer == 'y') { // print maze if user asks
			printMaze(Walls);
		}

		//start game
		bool win = 0;
		while (!win) {

			cout << "The mouse is in ";
			printRoom(currentRoom);

			char affirmation = getAnswer(secondQuestion);
			Room temp;
			RoomPair pairs;
			if (affirmation == 'y') {
				temp = currentRoom;
				pairs.one = temp;
				
				if (currentRoom.x > 0 && currentRoom.y > 96 || currentRoom.x < 4 && currentRoom.y < 100)
					nextMove(currentRoom);
				pairs.two = currentRoom;
				if (checkMaze(Walls, pairs) != -1) {
					cout << "WALL" << endl;
					currentRoom = temp; //set position to room before moving
				}

				if (matchRoom(currentRoom, cheeseRoom))
					win = 1;
			}
		}
	}
}
char getAnswer(string question) {
	char answer;
	cout << question << endl;
	cout << exitClause << endl;
	cin >> answer;
	return answer;
}