#pragma once

/// <summary>
/// An enum class for the players. Each player is represented by one color.
/// </summary>
enum class Player
{
	/// <summary>
	/// The white player.
	/// </summary>
	WHITE = 0,

	/// <summary>
	/// The black player.
	/// </summary>
	BLACK = 1,

	/// <summary>
	/// No player.
	/// Is used when the game needs to describe neither the white player nor the black player.
	/// </summary>
	NOBODY = 2
};

