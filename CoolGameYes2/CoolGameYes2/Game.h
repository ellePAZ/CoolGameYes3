#pragma once
#include "Board.h"

class Game
{
private:
	Board* _boardPtr;
	Player* _playerPtr;

public:
	Game(int width, int height, int screenWidth, int screenHeight);
	~Game();

	void Update();
};

