#pragma once
#include<iostream>
#include <iostream>
#include <locale>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <random>
#include <set>

using namespace std;

class Cube {
public:
	vector<vector<char>> faces;

	Cube();
	
	void randomize();
	void loadFromFile(const string& filename);
	void print();
	bool checkRows();
	void changeFace();
}; 