#ifndef _SNAKE
#define _SNAKE
#include "rotate.h"
#include "block.h"
#include <deque>
#include "field.h"
#include "Food.h"


// length snake must be => 2

class Snake
{
private:
	std::deque<block> coord;
	Rotate snakeRot;
	size_t length; 
	
public:
	Snake(size_t t_lenght, Rotate rot) : length(t_lenght), snakeRot(rot)
	{
		coord.resize(t_lenght);
	}
	void ToStartValues()
	{
		int offSetOfY = 0;
		for (size_t i = 0; i < length; offSetOfY++, i++)
		{
			coord[i].x = Field::sizeX/2;
			coord[i].y = Field::sizeY/2 - offSetOfY;
			if (i == 0) coord[i].changeBoolIsHeadToTrue();
			if (i == length - 1) coord[i].changeBoolIsTailToTrue();
			
		}
		snakeRot = Rotate::UP;
	}
	void move(Field& field)
	{
		ClearSnake(field);

		if (GetAsyncKeyState('W') && snakeRot != DOWN)	snakeRot = UP;
		if (GetAsyncKeyState('A') && snakeRot != RIGHT) snakeRot = LEFT;
		if (GetAsyncKeyState('S') && snakeRot != UP)	snakeRot = DOWN;
		if (GetAsyncKeyState('D') && snakeRot != LEFT)	snakeRot = RIGHT;

		// Передаём координаты так, чтобы блоки под индексами 1 и 0 имели одинаковые координаты, чтобы в будущем поменять координаты у головы
		for (size_t i = length - 1; i > 0; i--)
		{
			coord[i] = coord[i - 1];
		}

		switch (snakeRot)
		{
		// The x-axis looks right. So right is right, left is left.
		case LEFT:
			coord[0].x--;
			break;

		case RIGHT:
			coord[0].x++;
			break;

		// The y-axis looks down. This means that up is down and down is up
		case DOWN:
			coord[0].y++;
			break;
		case UP:
			coord[0].y--;
			break;
		}
		DrawSnake(field);
	}

	bool IsOutOfField(const Field& field)
	{
		if (coord[0].x == 0 || coord[0].x == (Field::sizeX - 1) || coord[0].y == 0 || coord[0].y == (Field::sizeY - 1)) return true;
		return false;
	}

	bool checkSelfCollision()
	{
		for (size_t i = 2; i < length; i++)
		{
			if (coord[0].x == coord[i].x && coord[0].y == coord[i].y) return true;
		}
		return false;
	}

	bool canEatFood(Food* food)
	{
		for (size_t i = 0; i < length; i++)
		{
			if (coord[i].x == food->getX() && coord[i].y == food->getY()) return true;
		}
		return false;
	}

	void EatingFood(Food* food)
	{
		length++;
		coord.push_front(block());
		if (snakeRot == UP)
		{
			coord[0].x = coord[1].x;
			coord[0].y = coord[1].y - 1;
		}
		else if (snakeRot == DOWN)
		{
			coord[0].x = coord[1].x;
			coord[0].y = coord[1].y + 1;
		}
		else if (snakeRot == LEFT)
		{
			coord[0].x = coord[1].x - 1;
			coord[0].y = coord[1].y;
		}
		else if (snakeRot == RIGHT)
		{
			coord[0].x = coord[1].x + 1;
			coord[0].y = coord[1].y;
		}
		food->~Food();
	}

private:
	void DrawSnake(Field& field)
	{
		field(coord[0].x, coord[0].y) = 'o';
		if (length > 1)
		{
			for (size_t i = 1; i < length; i++)
			{
				field(coord[i].x, coord[i].y) = '-';
			}
		}
	}
	void ClearSnake(Field& field)
	{
		field(coord[0].x, coord[0].y) = ' ';
		if (length > 1)
		{
			for (size_t i = 1; i < length; i++)
			{
				field(coord[i].x, coord[i].y) = ' ';
			}
		}
	}
	
};
#endif



