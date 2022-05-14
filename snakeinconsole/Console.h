#ifndef __CONSOLE
#define __CONSOLE
#include <Windows.h>

class Console
{
public:
	void setCursor(int x, int y);
	void disableViewOfCursor();
};
#endif 
