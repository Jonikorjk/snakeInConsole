#ifndef _FIELD
#define _FIELD
#include <vector>
#include "block.h"
#include <iostream>
#include "Console.h"
using namespace std;

class Field
{
	friend class Snake;
private:
	Console cnsl;
	vector<vector<char>> field;
	static int sizeX, sizeY;

public:
	Field();
	void fillField(char ch);
	static int getSizeX() { return sizeX; }
	static int getSizeY() { return sizeY;}
	void drawField();
	char& operator()(int row, int col);
};

#endif 


