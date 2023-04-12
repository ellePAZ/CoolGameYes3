#include <windows.h>
#include "Game.h"

Game::Game(int mapWidth, int mapHeight, int screenWidth, int screenHeight)
{
	_playerPtr = new Player(mapWidth / 2, mapHeight / 2);
	_boardPtr = new Board(mapWidth, mapHeight, screenWidth, screenHeight, _playerPtr);
}

Game::~Game()
{

}

void Game::Update()
{
	// Update player input
	// If !input, return;
	system("CLS");
	_boardPtr->Update();
	_boardPtr->Draw();
}
