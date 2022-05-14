#ifndef _GAMEMANAGER
#define _GAMEMANAGER

class gameManager
{
private:
	static bool gameOver;

public:
	static void ChangeStatusAboutGameOverToTrue() { gameOver = true; }
	static bool getStatusAboutGameOver() { return gameOver; }
};

#endif