#pragma once
#include<string>
using namespace std;

class playerNode {

private:
	string username;
	int score;
	playerNode* nextP;

public:
	playerNode();
	string getUsername() {
		return username;
	}
	playerNode* getNextP() {
		return nextP;
	}
	int getscore() {
		return score;
	}
	void setNext(playerNode* _next) {
		nextP = _next;
	}
	void setscore(int _score) {
		score = _score;
	}
};