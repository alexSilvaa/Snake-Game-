#include<string>
#include<iostream>
#include"PLAYERNODE.h"
#include"LINKEDLIST.h"
using namespace std;

linkedList::linkedList() {

	first = NULL;
	last = NULL;
}

void linkedList::addPlayer(string, int x) {
	playerNode* newPlayer = new playerNode();
	newPlayer->setscore(x);

	if (last == NULL) {
		last = first = newPlayer;
	}
	else {
		last->setNext(newPlayer);
		last = newPlayer;
	}
	length++;
	/*string answer;
	string answer2;
	
	
		/*cout << "Would you like to play again?   yes/no" << endl;
	cin >> answer;

	if (answer == "no") {
		cout << "Would a different player like to play?  yes/no" << endl;
		cin >> answer2;
		if (answer2 == "yes") {
			playerNode* newPlayer = new playerNode();
			
		}
		else
			system("cls");
	}
	else*/

}

void linkedList::printAll() {
	playerNode* current;
	current = first;
	
	while (current != NULL) {
		cout << "Player: " << current->getUsername() << endl;
		cout << "Score: " << current->getscore() << endl;
	
		current = current->getNextP();
	}
	cout << endl;
}

