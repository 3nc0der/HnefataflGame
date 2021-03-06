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
	/// Deep clones the given board and creates a new copy of the same board by that.
	/// </summary>
	/// <param name="hb">The board instance to copy from.</param>
	HnefataflBoard(HnefataflBoard& hb);

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
	HnefataflBoard* move(Move move);

	/// <summary>
	/// Executes a machine move.
	/// </summary>
	/// <returns>A new Board instance with the move made the machine determined to be the best.</returns>
	HnefataflBoard* machineMove();

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
	list<Piece>* getHumanPieces();

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

	/// <summary>
	/// Creates a string to represent the board in text form.
	/// </summary>
	/// <returns>The string representing the board.</returns>
	std::string toString();

private:

	/// <summary>
	/// Validates a given move in a way that if anything with the move is wrong, meaning the move can't be made, this function will fail to validate it.
	/// </summary>
	/// <param name="move">The move to validate.</param>
	/// <returns>True if the move is valid, meaning it can be made on the board. False otherwise.</returns>
	bool validateMove(Move move);

	/// <summary>
	/// Asserts a given move. Meaning that if the move is invalid due to a parameter being out of bounds this function asserts it.
	/// </summary>
	/// <param name="move">The move to assert.</param>
	/// <returns>True if the move is invalid. False otherwise.</returns>
	bool assertMove(Move move);

	/// <summary>
	/// Tells whether a given tile is empty or occupied.
	/// </summary>
	/// <param name="pos">The tiles position on the board.</param>
	/// <returns>True if the tile is occupied with anything. False otherwise.</returns>
	bool isTileOccupied(Position pos);

	/// <summary>
	/// Quick way to receive the current players color.
	/// </summary>
	/// <returns>The color of the current player.</returns>
	Color getCurrentPlayersColor();

	/// <summary>
	/// Searches the current players piece list for a piece standing at the given position.
	/// </summary>
	/// <param name="pos">The position to search a piece at.</param>
	/// <returns>The piece, if one was found at the position. A nullptr otherwise.</returns>
	Piece* getCurrentPlayersPieceAt(Position pos);

	/// <summary>
	/// Asserts the given position and takes the tile at the position from the gameBoard array.
	/// Basically an easy access function for the gameBoard array.
	/// </summary>
	/// <param name="pos">The position the wanted tile sits at.</param>
	/// <returns>The tile at the given position from the gameBoard array.</returns>
	Tile getTileAt(Position pos);

	/// <summary>
	/// The game board.
	/// Each slot in the array represents one tile on the board.
	/// </summary>
	Tile gameBoard[BOARD_SIZE][BOARD_SIZE];

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
	/// The pieces the human controls.
	/// </summary>
	list<Piece> humanPieces;

	/// <summary>
	/// The pieces the machine controls.
	/// </summary>
	list<Piece> machinePieces;
};

