#pragma once

#include "Player.h"
#include "GameState.h"

/// <summary>
/// A struct for a single move.
/// </summary>
struct Move
{
	/// <summary>
	/// The row the piece currently stands on and the row the piece shall be moved to.
	/// </summary>
	unsigned short rowFrom, rowTo;

	/// <summary>
	/// The column the piece currently stands on and the column the piece shall be moved to.
	/// </summary>
	unsigned short colFrom, colTo;
};

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
	/// Creates a new copy of the board on which the move will be executed.
	/// </summary>
	/// <param name="rowFrom">The row the piece to be moved stands on.</param>
	/// <param name="colFrom">The column the piece to be moved stands on.</param>
	/// <param name="rowTo">The row the piece to be moved will be moved to.</param>
	/// <param name="colTo">The column the piece to be moved will be moved to.</param>
	/// <returns>A new Board instance with the given move made.</returns>
	virtual Board move(Move move) = 0;

	/// <summary>
	/// Executes a machine move.
	/// Creates a new copy of the board on which the move will be executed.
	/// </summary>
	/// <returns>A new Board instance with the move made the machine determined to be the best.</returns>
	virtual Board machineMove() = 0;

	/// <summary>
	/// Resets the board to the state before the last human move. Leaves this board untouched as a new copy is created.
	/// </summary>
	/// <returns>The reseted board.</returns>
	virtual Board undo() = 0;

	/// <summary>
	/// Sets the machine level to the given value.
	/// This value describes how many moves the machine will calculate into the future.
	/// </summary>
	/// <param name="level">The value the machine level should be set to.</param>
	virtual void setMachineDifficulty(int level) = 0;

	/// <summary>
	/// Getter for the machine difficulty; i. e. the maximum depth of the game tree.
	/// </summary>
	/// <returns>The value of the machine level.</returns>
	virtual int getMachineDifficulty() = 0;

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

	/// <summary>
	/// Sets the given game state.
	/// </summary>
	/// <param name="gameState">The new game state the game shall be in.</param>
	virtual void setGameState(GameState gameState) = 0;
};
