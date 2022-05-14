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
	Field()
	{
		field.resize(sizeX);
		for (size_t i = 0; i < field.size(); i++)
		{
			field[i].resize(sizeY);
		}
	}
	void fillField(char ch)
	{
		for (size_t i = 0; i < field.size(); i++)
		{
			for (size_t j = 0; j < field[i].size(); j++)
			{
				if (i == 0 || j == 0 || i == field.size() - 1 || j == field[i].size() - 1)
				{
					field[i][j] = ch;
				}
				else field[i][j] = ' ';
			}
		}
	}
	static int getSizeX() { return sizeX; }
	static int getSizeY() { return sizeY; }
	void drawField()
	{
		cnsl.disableViewOfCursor();
		cnsl.setCursor(0, 0);
		for (size_t i = 0; i < field[i].size(); i++)
		{
			for (size_t j = 0; j < field.size(); j++)
			{
				cout << field[j][i] << ' ';
			}
			cout << endl;
		}
	
	}
	char& operator()(int row, int col) { return field.at(row).at(col); }
};

#endif 


