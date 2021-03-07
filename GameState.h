#pragma once

/* 
* An enum class for the state of the game.
* Is updated everytime the game state may change and can be used to determine how the game behaves in different states.
*/
enum class GameState
{
	MENU = 0,
	RUNNING,
	WON,
	TIE,
	PAUSE
};
