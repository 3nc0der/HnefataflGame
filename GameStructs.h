#pragma once

#include "Color.h"
#include "TileType.h"

#include <string>

/// <summary>
/// The size of the game board in rows/columns.
/// </summary>
static const int BOARD_SIZE = 11;

struct Position
{
	/// <summary>
	/// The two coordinates the position needs to be described.
	/// </summary>
	unsigned short row, col;
};

/// <summary>
/// Overloads the equals operator for the Position struct.
/// </summary>
/// <param name="lhp">The left argument.</param>
/// <param name="rhp">The right argument.</param>
/// <returns>True if every member is equal, false otherwise.</returns>
bool operator==(Position lhp, Position rhp)
{
	if (lhp.row == rhp.row && lhp.col == rhp.col)
	{
		return true;
	}

	return false;
}

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

	/// <summary>
	/// Getter for the row and column the move shall end on.
	/// </summary>
	/// <returns>The <c>rowTo</c> and <c>colTo</c> values packed in a position.</returns>
	Position getDestination();

	/// <summary>
	/// Getter for the row and column the move is started on.
	/// </summary>
	/// <returns>The <c>rowFrom</c> and <c>colFrom</c> values packed in a position.</returns>
	Position getSource();

	/// <summary>
	/// Calculates the length of a move.
	/// As the pieces cannot move diagonally this is a single value.
	/// The value will always be positive as this calculates the length not the direction.
	/// </summary>
	/// <returns>The length of this move as single, positive value.</returns>
	unsigned short getDistance();

	/// <summary>
	/// Gives a quick idea about in what direction the move is heading.
	/// </summary>
	/// <returns>A position, which can be interpreted so that the value 1 means the column/row is getting bigger and -1 means they're getting smaller.
	/// Also only one member of the position will be set to something other than 0 as the pieces can't move diagonally.</returns>
	Position getDirection();
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
	/// The color of the piece standing on this tile.
	/// If the tile is not occupied at the moment, the color is set to NONE.
	/// </summary>
	Color occupiedBy;

	/// <summary>
	/// The type of this tile.
	/// </summary>
	TileType tileType;

	/// <summary>
	/// Packs the row and col member of the tile into a Position instance.
	/// </summary>
	/// <returns>The position of the tile as instance of the Position struct.</returns>
	Position getPosition();

	/// <summary>
	/// Converts the tile into a string for better readability.
	/// </summary>
	/// <returns>A string representation of the tile.</returns>
	std::string toString();
};
