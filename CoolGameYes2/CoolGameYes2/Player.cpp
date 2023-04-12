#include "Player.h"

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
	// Read input from the user, should be in windows.h
	// Return new positions
	return { 0, 0 };
}

std::pair<int, int> Player::GetPosition()
{
	return { xPos, yPos };
}

std::pair<int, int> Player::GetOldPosition()
{
	return { oldX, oldY };
}
