#include"maze.hpp"
#include<iostream>
#include<string>

using std::cout; using std::cin; using std::endl;

int main() {
	string firstQuestion = "Do you want to see the maze? yes: 'y' or no: 'n'";
	string exitClause = "To quit enter 'q'.";
	cout << exitClause <<endl;
	char answer = getAnswer(firstQuestion);

	while (answer != 'q') {

		//bulid maze
		Room startRoom, currentRoom, cheeseRoom;
		
		if (answer == 'y') { // print maze if user asks
		
		}

		//start game
		bool win = 0;
		while (!win) {
			Room startRoom, currentRoom, cheeseRoom;
			
			cout << "The mouse is in ";
			printRoom(currentRoom);
			string secondQuestion = "Would you like to move the mouse? Yes: 'y' or No: 'n'";
			char affirmation = getAnswer(secondQuestion);
			if (affirmation == 'y') {
				
			}
		}
		
	
	}

	
}
char getAnswer(const string question) {
	char answer;
	cout << question<< endl;
	cin >> answer;
	return answer;
}