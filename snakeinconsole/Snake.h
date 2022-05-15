#ifndef _SNAKE
#define _SNAKE
#include "rotate.h"
#include "block.h"
#include <deque>
#include "field.h"
#include "Food.h"

class Snake
{
private:
	std::deque<block> coord;
	Rotate snakeRot;
	size_t length; 
public:
	Snake(size_t t_lenght, Rotate rot);
	void ToStartValues();
	void clearOldPosition_Move_DrawSnake(Field& field);
	bool IsOutOfField(const Field& field);
	bool checkSelfCollision();
	bool canEatFood(Food* food);
	void EatingFood(Food* food);
	int getLengthOfSnake();
private:
	void DrawSnake(Field& field);
	void ClearSnake(Field& field);
	
};
#endif



