#include "Food.h"

Food::Food(int x, int y)
{
	coordinates.x = x;
	coordinates.y = y;
}

Food::~Food() 
{
}

int Food::getX() const { return coordinates.x; }
int Food::getY() const { return coordinates.y; }

void Food::DrawFood(Field& field)
{
	field(coordinates.x, coordinates.y) = '$';
}
