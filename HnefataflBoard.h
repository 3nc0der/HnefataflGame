#pragma once

#include "Board.h"
#include "Observable.h"

#include <stack>

using namespace std;

/// <summary>
/// A class for the game itself.
/// An instance of this class represents an active instance of the game.
/// </summary>
class HnefataflBoard : public Board, public Observable
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
	Board* move(Move move);

	/// <summary>
	/// Executes a machine move.
	/// </summary>
	/// <returns>A new Board instance with the move made the machine determined to be the best.</returns>
	Board* machineMove();

	/// <summary>
	/// Resets the board to the state before the last human move. Leaves this board untouched as a new copy is created.
	/// </summary>
	/// <returns>The reseted board.</returns>
	Board* undo();

	/// <summary>
	/// Sets the machine level to the given value.
	/// This value describes how many moves the machine will calculate into the future.
	/// </summary>
	/// <param name="level">The value the machine level should be set to.</param>
	void setMachineDifficulty(int level);

	/// <summary>
	/// Getter for the machine difficulty; i. e. the maximum depth of the game tree.
	/// </summary>
	/// <returns>The value of the machine level.</returns>
	int getMachineDifficulty();

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

	/// <summary>
	/// Sets the given game state.
	/// </summary>
	/// <param name="gameState">The new game state the game shall be in.</param>
	void setGameState(GameState gameState);

	/// <summary>
	/// Getter for the machine pieces list. Note that you will receive a pointer to the list.
	/// </summary>
	/// <returns>A pointer to the machine pieces list.</returns>
	list<Piece>* getMachinePieces();

	/// <summary>
	/// Getter for the human pieces list. Note that you will receive a pointer to the list.
	/// </summary>
	/// <returns>A pointer to the human pieces list.</returns>
	list<Piece> getHumanPieces();

	/// <summary>
	/// Getter for the machines color.
	/// </summary>
	/// <returns>The machines color.</returns>
	const Color getMachineColor();

	/// <summary>
	/// Getter for the humans color.
	/// </summary>
	/// <returns>The humans color.</returns>
	const Color getHumanColor();

	/// <summary>
	/// Getter for the current player.
	/// </summary>
	/// <returns>The player who's turn it is.</returns>
	Player getCurrentPlayer();

	/// <summary>
	/// Getter for the next player.
	/// </summary>
	/// <returns>The player who's turn it will be next turn.</returns>
	Player getNextPlayer();

private:

	/// <summary>
	/// The current state of the game.
	/// </summary>
	GameState gameState;

	/// <summary>
	/// The player that moves on this instance.
	/// And the player that moves on the instance derived from this one.
	/// </summary>
	Player currentPlayer, nextPlayer;

	/// <summary>
	/// The color of the human/machine.
	/// </summary>
	const Color humanColor, machineColor;

	/// <summary>
	/// The level of the machine. This is the maximum depth of the game tree, the machine uses to determine the best move.
	/// </summary>
	int machineLevel;

	/// <summary>
	/// Every human move is added to the stack.
	/// This is used to implement the undo functionality.
	/// </summary>
	stack<Board> moveStack;

	/// <summary>
	/// The pieces the human controls.
	/// </summary>
	list<Piece> humanPieces;

	/// <summary>
	/// The pieces the machine controls.
	/// </summary>
	list<Piece> machinePieces;
};

