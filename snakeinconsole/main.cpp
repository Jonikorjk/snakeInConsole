#include "menu.h"

bool gameManager::gameOver = false;
int Field::sizeX = 50;
int Field::sizeY = 30;


int main()
{
    Menu menu(EASY);
    menu.startGame();
}