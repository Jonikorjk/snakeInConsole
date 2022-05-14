#ifndef _FOOD
#define _FOOD
#include "field.h"



class Food
{
private:
	block coordinates;

public:
	Food(int x, int y)  
	{
		coordinates.x = x;
		coordinates.y = y;
	}
	
	int getX() const { return coordinates.x; }
	int getY() const { return coordinates.y; }

	~Food() {}

	void DrawFood(Field& field)
	{
		field(coordinates.x, coordinates.y) = '$';
	}
};


#endif // !_FOOD




