#include<string>
#include<iostream>
#include"PLAYERNODE.h"
using namespace std;


playerNode::playerNode() {

	cout << "input username!" << endl;
	cin >> username;
	score = NULL;
	nextP = NULL;
}



