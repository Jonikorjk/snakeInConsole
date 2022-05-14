#ifndef _MENU
#define _MENU
#include "Difficulty.h"
#include "field.h"
#include "snake.h"
#include <Windows.h>
#include <random>
#include <ctime>
#include "gameManager.h"
#include "Food.h"
#include <iostream>
using namespace std;


class Menu
{
private:
	Difficulty gameDif;
    void Event();

public: 
    Menu(Difficulty dif);
    int Speed();
    void startGame();
};

#endif // !_MENU


