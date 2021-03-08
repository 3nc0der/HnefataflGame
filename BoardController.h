#pragma once

#include "Observer.h"

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
	/// Implements what happens when the observed classes notify this observer.
	/// </summary>
	void update();
};

