#pragma once

#include "Player.h"
#include "GameState.h"

/// <summary>
/// A fully virtual class, that can be used to communicate with instances of the game.
/// </summary>
class Board
{
	public:

		/// <summary>
		/// The size of the game board in rows/columns.
		/// </summary>
		static const int SIZE = 11;

		/// <summary>
		/// Executes a human move.
		/// </summary>
		/// <param name="rowFrom">The row the piece to be moved stands on.</param>
		/// <param name="colFrom">The column the piece to be moved stands on.</param>
		/// <param name="rowTo">The row the piece to be moved will be moved to.</param>
		/// <param name="colTo">The column the piece to be moved will be moved to.</param>
		/// <returns>A new Board instance with the given move made.</returns>
		virtual Board move(int rowFrom, int colFrom, int rowTo, int colTo) = 0;

		/// <summary>
		/// Executes a machine move.
		/// </summary>
		/// <returns>A new Board instance with the move made the machine determined to be the best.</returns>
		virtual Board machineMove() = 0;

		/// <summary>
		/// Sets the machine level to the given value.
		/// This value describes how many moves the machine will calculate into the future.
		/// </summary>
		/// <param name="level">The value the machine level should be set to.</param>
		virtual void setMachineDifficulty(int level) = 0;

		/// <summary>
		/// A getter for the player who won.
		/// </summary>
		/// <returns>The winning player, if the game was won. Otherwise <c>NOBODY</c>.</returns>
		virtual Player getWinner() = 0;

		/// <summary>
		/// Will determine if the game is over or still running.
		/// </summary>
		/// <returns>True if the game is over (<c>WON</c> or <c>TIE</c>). False if any other game state is set.</returns>
		virtual bool isOver() = 0;

		/// <summary>
		/// A getter for the current game state.
		/// </summary>
		/// <returns>The game state currently set.</returns>
		virtual GameState getGameState() = 0;
};
