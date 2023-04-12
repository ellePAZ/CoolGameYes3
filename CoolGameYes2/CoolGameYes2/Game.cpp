#include <windows.h>
#include "Game.h"

Game::Game(int mapWidth, int mapHeight, int screenWidth, int screenHeight)
{
	_playerPtr = new Player(mapWidth / 2, mapHeight / 2);
	_boardPtr = new Board(mapWidth, mapHeight, screenWidth, screenHeight, _playerPtr);

	system("CLS");
	_boardPtr->Update();
	_boardPtr->Draw();
}

Game::~Game()
{

}

void Game::Update()
{
	auto input = _playerPtr->CheckInput();
	if (input.first == 0 && input.second == 0)
		return;

	system("CLS");
	_boardPtr->Update();
	_boardPtr->Draw();
	_playerPtr->UpdateOldPosition();
}
