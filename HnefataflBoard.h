#pragma once

#include "Board.h"

/// <summary>
/// A class for the game itself.
/// An instance of this class represents an active instance of the game.
/// </summary>
class HnefataflBoard : public Board
{
	public:

		/// <summary>
		/// Creates a new instance of an Hnefatafl game.
		/// </summary>
		HnefataflBoard();

		/// <summary>
		/// Deletes this instance of an Hnefatafl game.
		/// </summary>
		~HnefataflBoard();

		/// <summary>
		/// Executes a human move.
		/// </summary>
		/// <param name="rowFrom">The row the piece to be moved stands on.</param>
		/// <param name="colFrom">The column the piece to be moved stands on.</param>
		/// <param name="rowTo">The row the piece to be moved will be moved to.</param>
		/// <param name="colTo">The column the piece to be moved will be moved to.</param>
		/// <returns>A new Board instance with the given move made.</returns>
		Board move(Move move);

		/// <summary>
		/// Executes a machine move.
		/// </summary>
		/// <returns>A new Board instance with the move made the machine determined to be the best.</returns>
		Board machineMove();

		/// <summary>
		/// Sets the machine level to the given value.
		/// This value describes how many moves the machine will calculate into the future.
		/// </summary>
		/// <param name="level">The value the machine level should be set to.</param>
		void setMachineDifficulty(int level);

		/// <summary>
		/// A getter for the player who won.
		/// </summary>
		/// <returns>The winning player, if the game was won. Otherwise <c>NOBODY</c>.</returns>
		Player getWinner();

		/// <summary>
		/// Will determine if the game is over or still running.
		/// </summary>
		/// <returns>True if the game is over (<c>WON</c> or <c>TIE</c>). False if any other game state is set.</returns>
		bool isOver();

		/// <summary>
		/// A getter for the current game state.
		/// </summary>
		/// <returns>The game state currently set.</returns>
		GameState getGameState();
};

