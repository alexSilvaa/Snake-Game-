#pragma once
#include"PLAYERNODE.h"
#include<string>
#include<iostream>
using namespace std;

class linkedList {

private:
	playerNode* last;
	playerNode* first;
	int length;

public:
	linkedList();
	void printAll();
	void addPlayer(string, int);
	
};