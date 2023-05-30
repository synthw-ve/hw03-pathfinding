#ifndef _pathfinding_H_
#define _pathfinding_H_

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class pathfinding {
private:
	static const unsigned int ROWS = 20;
	static const unsigned int COLS = 40;
	static const unsigned int PROBABILITY = 15;
	unsigned int x;
	unsigned int y;
	unsigned int end_x;
	unsigned int end_y;
	bool _generation[ROWS][COLS];
	bool random_value();
	float get_dist(int x, int y);

public:
	pathfinding();
	short next_generation();
	void draw();
};

#endif