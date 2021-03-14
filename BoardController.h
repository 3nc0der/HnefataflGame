#pragma once

#include "Observer.h"
#include "HnefataflBoard.h"

/// <summary>
/// A class for the controller of the board.
/// The instance can be used to execute moves on the game instance and to update the view.
/// </summary>
class BoardController : public Observer
{
public:

	/// <summary>
	/// Creates a new BoardController instance.
	/// </summary>
	BoardController();

	/// <summary>
	/// Deletes this BoardController instance.
	/// </summary>
	~BoardController();

	/// <summary>
	/// Temporary function to print out the board.
	/// </summary>
	/// <returns>The board model as string.</returns>
	std::string getBoardString();

	/// <summary>
	/// Resets the board to the state before the last human move. Leaves this board untouched as a new copy is created.
	/// </summary>
	/// <returns>The reseted board.</returns>
	RESULT undo();

private:

	/// <summary>
	/// Implements what happens when the observed classes notify this observer.
	/// </summary>
	void update();

	/// <summary>
	/// The instance of the game.
	/// </summary>
	HnefataflBoard *game;

	/// <summary>
	/// Every human move is added to the stack.
	/// This is used to implement the undo functionality.
	/// </summary>
	stack<HnefataflBoard*> moveStack;
};

