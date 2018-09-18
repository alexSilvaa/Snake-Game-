#include <iostream>
#include <conio.h>
#include<Windows.h>
#include"LINKEDLIST.h"
#include"PLAYERNODE.h"
#include<fstream>
using namespace std;

int start();
void startMap();
void updateMap();
void printMap();
void direction(char keyboard);
void move(int x, int y);
void generator();
void gameover();
char getMapValue(int value);


const int width = 20;
const int height = 20;
const int area = width * height;

int map[400];
int firstx, firsty, direc;
int food = 3;

bool run;

int main()
{
	string line;
	fstream datafile;
	datafile.open("board.txt", ios::in);
	if (!datafile) {
		cout << "opening error" << endl;
	}
	else {
		while (getline(datafile, line)) {
			cout << line << "\n";
		}
		datafile.close();
	}
	

	playerNode* p0;
	linkedList l1;
	string name;
	
	int players;

	int score;
	cout << "Enter number of players." << endl;
	cin >> players;
	
	for (int i = 0; i < players; i++) {
		
	    score  = start();

		l1.addPlayer(name, score );
		food = food - score;
	}
	

	l1.printAll();

	
	;
	system("pause");
	

	return 0;
}


int start()
{
	// Initialize the map
	startMap();
	run = true;
	while (run) {
		// If a key is pressed
		if (_kbhit()) {
			// Change to direction determined by key pressed
			direction(_getch());
		}
		                 // Upate the map
		updateMap();

		                   // Clear the screen
		gameover();

		                  // Print the map
		printMap();

		                // wait 0.3 seconds
		Sleep(300);
	}

	                                             // Print out game over text
	    cout << "\t\t!!!Game over!" << endl;
		cout << "\t\tYour score is: " << food - 3 << endl;
		
	
	                            // Stop console from closing instantly
	cin.ignore();
	return food -3;
}

                                   // Changes snake direction from input
void direction(char keyboard) {

	switch (keyboard) {

	case 'g':                      //right
		if (direc != 3) direc = 0;
		break;
	case 'f':                       //left
		if (direc != 5) direc = 1;
		break;
	case 't':                      //up
		if (direc != 2) direc = 2;
		break;
	case 'v':                      //down
		if (direc != 4) direc = 3;
		break;
	
	}
}

                               // Moves snake head to new location
void move(int x, int y) {
	                           // determine new head position
	int newx = firstx + x;
	int newy = firsty + y;

	// Check if there is food at location
	if (map[newx + newy * width] == -2) {
		// Increase food value (body length)
		food++;

		// Generate new food on map
		generator();
	}

	// Check location is free
	else if (map[newx + newy * width] != 0) {
		run = false;
	}

	// Move head to new location
	firstx = newx;
	firsty = newy;
	map[firstx + firsty * width] = food + 1;

}

// Clears screen
void gameover() {
	// Clear the screen

	system("cls");
}

// Generates new food on map
void generator() {
	int x = 0;
	int y = 0;
	do {
		// Generate random x and y values within the map
		x = rand() % (width - 2) + 1;
		y = rand() % (height - 2) + 1;
	}
	// If location is not free try again
	while (map[x + y* width] != 0); 

		// Place new food
		map[x + y * width] = -2;
}
	
	

// Updates the map
void updateMap() {
	// Move in direction indicated
	switch (direc) {
	case 0: move(0, 1);
		break;
	case 1: move(0, -1);
		break;
	case 2: move(-1, 0);
		break;
	case 3: move(1, 0);
		break;
	}

	// Reduce snake values on map by 1
	for (int i = 0; i < area; i++) {
		if (map[i] > 0) map[i]--;
	}
}

// Initializes map
void startMap()
{
	// Places the initual head location in middle of map
	firstx = width / 2;
	firsty = height / 2;
	map[firstx + firsty * width] = 1;

	// Places top and bottom walls 
	for (int x = 0; x < width; ++x) {
		map[x] = -1;
		map[x + (height - 1) * width] = -1;
	}

	// Places left and right walls
	for (int y = 0; y < height; y++) {
		map[0 + y * width] = -1;
		map[(width - 1) + y * width] = -1;
	}

	// Generates first food
	generator();
}

// Prints the map to console
void printMap()
{
	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			// Prints the value at current x,y location
		cout << getMapValue(map[x + y * width]);
		}
		// Ends the line for next x value
		cout << endl;
	}
}

// Returns graphical character for display from map value
char getMapValue(int value)
{
	// Returns a part of snake body
	if (value > 0) return 'o';

	switch (value) {
		// Return wall
	case -1: return '#';
		// Return food
	case -2: return '@';
	
	}
}