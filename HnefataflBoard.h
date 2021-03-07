#pragma once

#include "Board.h"

class HnefataflBoard : public Board
{
	public:

		// Creates a new instance of an Hnefatafl game.
		HnefataflBoard();

		// Deletes this game instance.
		~HnefataflBoard();

		/// <summary>
		/// Executes a human move on the board.
		/// 
		/// </summary>
		Board move();

		Board machineMove();

		/// <inheritdoc/>
		void setMachineDifficulty(int level);

		Player getWinner();

		bool isOver();

		GameState getGameState();
};

