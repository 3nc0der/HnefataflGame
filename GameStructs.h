#pragma once

#include "Color.h"
#include "TileType.h"

/// <summary>
/// The size of the game board in rows/columns.
/// </summary>
static const int SIZE = 11;

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
/// A struct to model one tile.
/// </summary>
struct Tile
{
	/// <summary>
	/// The point this tile can be found.
	/// </summary>
	unsigned short row, col;

	/// <summary>
	/// The color of this tile.
	/// </summary>
	Color tileColor;

	/// <summary>
	/// The type of this tile.
	/// </summary>
	TileType tileType;
};
