#include "Player.h"
#include <conio.h>

Player::Player(int x, int y) :
xPos (x),
yPos (y),
oldX (x),
oldY (y)
{

}

Player::~Player()
{

}

std::pair<int, int> Player::CheckInput()
{
	int a, b;
	int verticalInput = 0;
	int horizontalInput = 0;
	a = _getch();
	switch (a = _getch())
	{
	case 72: verticalInput = -1; break;
	case 80: verticalInput = 1; break;
	case 75: horizontalInput = -1; break;
	case 77: horizontalInput = 1; break;
	}

	xPos += horizontalInput;
	yPos += verticalInput;

	return { verticalInput, horizontalInput };
}

std::pair<int, int> Player::GetPosition()
{
	return { xPos, yPos };
}

std::pair<int, int> Player::GetOldPosition()
{
	return { oldX, oldY };
}

void Player::UpdateOldPosition()
{
	oldX = xPos;
	oldY = yPos;
}
