#pragma once

/// <summary>
/// An enum class for the state of the game.
/// Is updated every time the game state may change and can be used to determine how the game behaves in different states.
/// </summary>
typedef enum class GameState
{
	/// <summary>
	/// The game is currently in the menu.
	/// </summary>
	MENU = 0,

	/// <summary>
	/// The game is currently running. (There`s an active game going on.)
	/// </summary>
	RUNNING,

	/// <summary>
	/// One of the players won the game.
	/// </summary>
	WON,

	/// <summary>
	/// No player won, but the game is over though.
	/// </summary>
	TIE,

	/// <summary>
	/// The player paused the game.
	/// </summary>
	PAUSE
}STATE;
