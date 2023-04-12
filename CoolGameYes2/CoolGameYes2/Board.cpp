#include <iostream>
#include "Board.h"

Board::Board(int mapWidth, int mapHeight, int screenWidth, int screenHeight, Player* player)
{
	this->width = mapWidth;
	this->height = mapHeight;
	mapSize = mapWidth * mapHeight;
	map = new char[mapSize];

	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	screenSize = screenWidth * screenHeight;

	playerPtr = player;

	for (int i = 0; i < mapSize; i++)
	{
		int x;
		int y;
		GetCoordinates(i, x, y);

		if (x == 0 || x == mapWidth - 1)
		{
			map[i] = '@';
		}
		else if (y == 0 || y == mapHeight - 1)
		{
			map[i] = '@';
		}
		else
		{
			map[i] = ' ';
		}
	}
}

Board::~Board()
{
	delete[] map;
}

void Board::Update()
{
	auto oldPos = playerPtr->GetOldPosition();
	int oldIndex = 0;
	GetIndex(oldPos.first, oldPos.second, oldIndex);
	map[oldIndex] = ' ';

	auto playerPos = playerPtr->GetPosition();
	int index = 0;
	GetIndex(playerPos.first, playerPos.second, index);
	map[index] = playerChar;
	playerChar = playerChar == 'P' ? 'R' : 'P';
}

void Board::Draw()
{
	auto playerPos = playerPtr->GetPosition();
	auto startCoordinates = std::pair<int, int>(playerPos.first - screenWidth / 2, playerPos.second - screenHeight / 2);
	auto startIndex = 0;
	GetIndex(startCoordinates.first, startCoordinates.second, startIndex);

	for (int i = startIndex; i < screenSize; i++)
	{
		std::cout << map[i];
		if (i % screenWidth == screenWidth - 1)
			std::cout << std::endl;
	}
}

void Board::GetCoordinates(int index, int& out_x, int& out_y)
{
	out_x = index % width;
	out_y = (index - out_x) / width;
}

void Board::GetIndex(int x, int y, int& out_index)
{
	out_index = y * width + x;
}
