#pragma once

#include "Player.h"
#include "GameState.h"

/*
* A fully virtual class, that can be used to communicate with instances of the game.
*/
class Board
{
	public:

		// The size of the game board in rows/columns.
		static const int SIZE = 11;

		// Executes a human move.
		virtual void move() = 0;

		// Executes a machine move.
		virtual void machineMove() = 0;

		// Returns the winning player.
		virtual Player getWinner() = 0;

		// Returns true if the game is over (Won or tie)
		virtual bool isOver() = 0;

		// Returns the game state the instance of the game is currently in.
		virtual GameState getGameState() = 0;
};
