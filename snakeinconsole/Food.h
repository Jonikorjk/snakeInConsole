#ifndef _FOOD
#define _FOOD
#include "field.h"

class Food
{
private:
	block coordinates;

public:
	Food(int x, int y);
	~Food();
	int getX() const;
	int getY() const;
	void DrawFood(Field& field);
};
#endif // !_FOOD




