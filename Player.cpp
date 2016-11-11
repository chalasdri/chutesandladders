//
//  Player.cpp
//

#include "Player.hpp"


Player& Player::operator=(const Player& p) {
	position = p.position;
	playerName = p.playerName;
	die = p.die;

	return *this;
}


int Player::rollDieAndMove() {
	die.roll();
	int steps = die.getFaceValue();

	// Stay put if beyond board
	if (position + steps > 100)
		return position;

	position += steps;

	return position;
}