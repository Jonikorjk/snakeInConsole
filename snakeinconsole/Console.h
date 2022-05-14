#ifndef __CONSOLE
#define __CONSOLE

#include <Windows.h>
class Console
{
public:
	void setCursor(int x, int y)
	{
		COORD position;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		position.X = x;
		position.Y = y;
		SetConsoleCursorPosition(hConsole, position);
	}

	void disableViewOfCursor()
	{
		CONSOLE_CURSOR_INFO curs = { 0 };
		curs.dwSize = sizeof(curs);
		curs.bVisible = FALSE;
		::SetConsoleCursorInfo(::GetStdHandle(STD_OUTPUT_HANDLE), &curs);
	}
};
#endif 

