#include <iostream>
#include <windows.h>

#include "Game.h"

int main()
{
	std::cout << "Hello CoolGameYes2!" << std::endl;

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	Game* gamePtr = new Game(columns, rows, columns, rows);

	while (true)
		gamePtr->Update();

	delete gamePtr;
	return 0;
}
