#pragma once
#include "Player.h"

class Board
{
private:
	int width;
	int height;
	int mapSize;

	int screenWidth;
	int screenHeight;
	int screenSize;

	char* map;

	Player* playerPtr;

	char playerChar;
public:
	Board(int mapWidth, int mapHeight, int screenWidth, int screenHeight, Player* playerPtr);
	~Board();

	void Update();
	void Draw();

private:
	void GetCoordinates(int index, int& x, int& y);
	void GetIndex(int x, int y, int& index);
};

