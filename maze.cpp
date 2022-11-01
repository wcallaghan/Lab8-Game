#include"Maze.hpp"
#include<iostream>
using namespace std;

void clearWalls(RoomPair r[]) {
	for (int i = 0; i < mazeSize; ++i) {
		r[i].one.x = -1; r[i].two.x = -1;
		r[i].one.y = '*'; r[i].two.y = '*';
	}

}
const RoomPair pickwall() {
	bool selected = 0;
	int random = RandNum();

	//pick a random first room
	RoomPair adjacentRooms;
	adjacentRooms.one.x = random;

	random = RandNum();	//new random number

	switch (random) {
	case 1:
		adjacentRooms.one.y = 97;
		break;
	case 2:
		adjacentRooms.one.y = 98;
		break;
	case 3:
		adjacentRooms.one.y = 99;
		break;
	case 4:
		adjacentRooms.one.y = 100;
		break;
	}

	//find adjacent room
	while (!selected) {

		int direction = RandNum();	// random direction
		char tmp = adjacentRooms.one.y; //placeholder for y coordinate

		switch (direction) {
		case 1: //left
			adjacentRooms.two.x = (adjacentRooms.one.x - 1 > 0) ? adjacentRooms.one.x - 1 : adjacentRooms.one.x;
			adjacentRooms.two.y = adjacentRooms.one.y;
			selected = 1;
			break;
		case 2: //right
			adjacentRooms.two.x = (adjacentRooms.one.x + 1 <= mazeSize) ? adjacentRooms.one.x + 1 : adjacentRooms.one.x;
			adjacentRooms.two.y = adjacentRooms.one.y;
			selected = 1;
			break;
		case 3: //up
			adjacentRooms.two.y = (adjacentRooms.one.y > 97) ? --tmp : adjacentRooms.one.y;
			adjacentRooms.two.x = adjacentRooms.one.x;
			selected = 1;
			break;
		case 4: //down
			adjacentRooms.two.y = (adjacentRooms.one.y < 100) ? ++tmp : adjacentRooms.one.y;
			adjacentRooms.two.x = adjacentRooms.one.x;
			selected = 1;
			break;
		}
	}//end loop

	return adjacentRooms;
}
bool matchRoom(const Room& one, const Room& two) {

	return (one.x == two.x && one.y == two.y);
}
bool matchPair(const RoomPair& r1, const RoomPair& r2) {

	return (matchRoom(r1.one, r1.two) && matchRoom(r2.one, r2.two));
}
int RandNum() {
	srand(time(nullptr)); return rand() % 4 + 1;
}
int checkMaze(const RoomPair walls[], const RoomPair rooms) {
	for (int i = 0; i < numWalls; ++i) {
		if (matchPair(walls[i], rooms))
			return 1;
		else
			return 0;
	}

}
void build(RoomPair rooms[]) {
	int builtWalls = 0;

	while (builtWalls < numWalls) {
		RoomPair walls = pickwall();
		if (checkMaze(rooms, walls) == 1) {
			rooms[builtWalls] = walls;
			++builtWalls;
		}

	}

}
void printRoom(const Room& r) {
	cout << r.x << r.y;
}
void printPair(const RoomPair& rp) {
	printRoom(rp.one);
	cout << "|";
	printRoom(rp.two);
}
void printMaze(RoomPair walls[]) {
	for (int i = 0; i < numWalls; ++i) {
		printPair(walls[i]);
	}
}
Room nextMove(Room CurrentLocation) {
	char direction;
	Room newLocation;
	cout << "Which way do you want to move? Up: u Down: d Left: l Right: r" << endl;
	cin >> direction;
	char tmp = CurrentLocation.y;
	switch (direction) {
	case 117:
		newLocation.x = CurrentLocation.x - 1;
		newLocation.y = CurrentLocation.y;
		break;
	case 100:
		newLocation.x = CurrentLocation.x + 1;
		newLocation.y = CurrentLocation.y;
		break;
	case 108:
		newLocation.x = CurrentLocation.x;
		newLocation.y = --tmp;
		break;
	case 114:
		newLocation.x = CurrentLocation.x;
		newLocation.y = ++tmp;
		break;
	}

	return newLocation;
}
