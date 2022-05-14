#ifndef _BLOCK
#define _BLOCK


class block
{
private:
	bool isHead, isTail;

public:
	int x, y;

	block() { isHead = false; isTail = false; }

	void changeBoolIsHeadToTrue() { isHead = true; }
	void changeBoolIsTailToTrue() { isHead = true; }

	bool getIsHead() { return isHead; }
	bool getIsTail() { return isTail; }

};

#endif 



