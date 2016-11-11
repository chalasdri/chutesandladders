//
//  ChutesAndLaddersGame.hpp
//

#pragma once

#include <stdio.h>
#include <string>

#include "ArrayQueue.h"
#include "Player.hpp"
#include "GameBoard.hpp"

using namespace std;


const int MIN_NUMBER_OF_PLAYERS = 2;

class ChutesAndLaddersGame {
public:
  
   ChutesAndLaddersGame(int nPlayers = MIN_NUMBER_OF_PLAYERS);

   
   ~ChutesAndLaddersGame();
   
   
   long getNumberOfPlayers() {
	   return playersQueue.size();
   }

   string getWinner() { return winner; }
   
   
   void resetGame();
   
   
   void playGame();
private:
   const int WINNING_POSITION = 100;
   
   string winner;       
   GameBoard gameBoard;

   
   Player player1;
   Player player2;
   ArrayQueue<Player> playersQueue;
};
