#pragma once
#include<utility>

class Player
{
private:
	int oldX = 0;
	int oldY = 0;

	int xPos = 0;
	int yPos = 0;

public:
	Player(int xPos, int yPos);
	~Player();

	std::pair<int, int> CheckInput();

	std::pair<int, int> GetPosition();
	std::pair<int, int> GetOldPosition();
};

