//
//  ChutesAndLaddersGame.cpp
//

#include <iostream>
#include <string>

#include "ChutesAndLaddersGame.hpp"
#include "GameBoard.hpp"
#include "Player.hpp"

using namespace std;


ChutesAndLaddersGame::ChutesAndLaddersGame(int nPlayers) : winner("no winner") {
	player1 = Player("obama");
	player2 = Player("Modi");

	playersQueue.enqueue(player1);
	playersQueue.enqueue(player2);
}


ChutesAndLaddersGame::~ChutesAndLaddersGame() {
   while (!playersQueue.empty())
	   playersQueue.dequeue();
}


void ChutesAndLaddersGame::resetGame() {
	
	while (!playersQueue.empty())
		playersQueue.dequeue();

	player1.setPostion(0);
	player2.setPostion(0);

	playersQueue.enqueue(player1);
	playersQueue.enqueue(player2);
}


void ChutesAndLaddersGame::playGame() {
	
	while (true) {
		// Get next player
		Player player = playersQueue.front();
		playersQueue.dequeue();
		
		// Make it move
		int newPosition = player.rollDieAndMove();
		newPosition = gameBoard.checkChutesLadders(newPosition);

		playersQueue.enqueue(player);

		// Stop if player wins
		if (newPosition == WINNING_POSITION)
		{
			winner = player.getName();
			cout << "Winner: " << player.getName() << endl;
			break;
		}
	}
}
