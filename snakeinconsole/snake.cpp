#include "Snake.h"

Snake::Snake(size_t t_lenght, Rotate rot) : length(t_lenght), snakeRot(rot)
{
	coord.resize(t_lenght);
}

void Snake::ClearSnake(Field& field)
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

void Snake::DrawSnake(Field& field)
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

int Snake::getLengthOfSnake() { return length; }

void Snake::EatingFood(Food* food)
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

bool Snake::canEatFood(Food* food)
{
	for (size_t i = 0; i < length; i++)
	{
		if (coord[i].x == food->getX() && coord[i].y == food->getY()) return true;
	}
	return false;
}

bool Snake::checkSelfCollision()
{
	for (size_t i = 1; i < length; i++)
	{
		if (coord[0].x == coord[i].x && coord[0].y == coord[i].y) return true;
	}
	return false;
}

bool Snake::IsOutOfField(const Field& field)
{
	if (coord[0].x == 0 || coord[0].x == (Field::sizeX - 1) || coord[0].y == 0 || coord[0].y == (Field::sizeY - 1)) return true;
	return false;
}

void Snake::move(Field& field)
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

void Snake::ToStartValues()
{
	int offSetOfX = 0;
	for (size_t i = 0; i < length; offSetOfX++, i++)
	{
		coord[i].x = Field::sizeX / 2 - offSetOfX;
		coord[i].y = Field::sizeY / 2;
	}
	snakeRot = Rotate::UP;
}

