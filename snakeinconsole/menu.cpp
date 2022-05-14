#include "menu.h"


Menu::Menu(Difficulty dif) : gameDif(dif) 
{
}

void Menu::Event()
{
    if (GetAsyncKeyState(VK_SPACE))
    {
        cout << "pause" << endl;
        system("pause");
        cout << "resume" << endl;
    }
}

int Menu::Speed()
{
	if (gameDif == EASY) return 80;
	if (gameDif == MEDIUM) return 40;
	if (gameDif == HARD) return 10;
	if (gameDif == MONSTER) return 0;
}

void Menu::startGame()
{

    srand(static_cast<unsigned int>(time(NULL)));

    int lengthOfSnake = 3;

    Field field;
    field.fillField('#');

    Snake snake(lengthOfSnake, RIGHT);
    snake.ToStartValues();

    Food* food = new Food((rand() % (Field::getSizeX() - 3)) + 1, (rand() % (Field::getSizeY() - 3)) + 1);
    bool firstIt = true;
    while (!gameManager::getStatusAboutGameOver() || snake.getLengthOfSnake() >= (Field::getSizeX() - 1) * (Field::getSizeY() - 1))
    {
        Sleep(Speed());
        if (firstIt)
        {
            system("pause");
            firstIt = false;
        }
        Event();
        food->DrawFood(field);
        snake.move(field);
        field.drawField();
        if (snake.checkSelfCollision()) gameManager::ChangeStatusAboutGameOverToTrue();
        if (snake.canEatFood(food))
        {
            snake.EatingFood(food);
            food = new Food((rand() % (Field::getSizeX() - 3)) + 1, (rand() % (Field::getSizeY() - 3)) + 1);
        }
        if (snake.IsOutOfField(field)) gameManager::ChangeStatusAboutGameOverToTrue();
    }
    if (snake.getLengthOfSnake() >= (Field::getSizeX() - 1) * (Field::getSizeY() - 1)) cout << "YOU WIN!" << endl;
    else cout << "You lose" << endl;
    cout << "SCORE: " << snake.getLengthOfSnake() - 3;
}