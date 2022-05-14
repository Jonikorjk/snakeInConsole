#include "field.h"

Field::Field()
{
	field.resize(sizeX);
	for (size_t i = 0; i < field.size(); i++)
	{
		field[i].resize(sizeY);
	}
}

void Field::fillField(char ch)
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

void Field::drawField()
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


char& Field::operator()(int row, int col) { return field.at(row).at(col); }