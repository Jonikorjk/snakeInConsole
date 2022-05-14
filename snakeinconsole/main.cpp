#include "field.h"
#include "snake.h"
#include <Windows.h>
#include <random>
#include <ctime>
#include "gameManager.h"
#include "Food.h"


bool gameManager::gameOver = false;
int Field::sizeX = 100;
int Field::sizeY = 50;


void Event()
{
    if (GetAsyncKeyState(VK_SPACE))
    {
        system("pause");
    }
}

int main()
{
    int lengthOfSnake = 3;

    srand(static_cast<unsigned int>(time(NULL)));

	Field field;
	field.fillField('#');

    Snake snake(lengthOfSnake, UP);
    snake.ToStartValues();

    Food* food = new Food(rand() % Field::getSizeX(), rand() % Field::getSizeY());

    while (!gameManager::getStatusAboutGameOver())
    {
        Event();
        food->DrawFood(field);
        snake.move(field);
        field.drawField();
        //if(snake.checkSelfCollision()) gameManager::ChangeStatusAboutGameOverToTrue();
        if (snake.canEatFood(food))
        {
            snake.EatingFood(food);
            food = new Food(rand() % Field::getSizeX(), rand() % Field::getSizeY());
        }
        if (snake.IsOutOfField(field)) gameManager::ChangeStatusAboutGameOverToTrue();
    }
}