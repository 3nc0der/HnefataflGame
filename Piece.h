#pragma once

#include "ReturnCodes.h"
#include "Color.h"
#include "TileType.h"
#include "Positioning.h"
#include "Utils.h"

/// <summary>
/// A class for the pieces of the game.
/// This is an abstract class as it will be implemented by the special piece classes.
/// </summary>
class Piece
{
public:

	/// <summary>
	/// Updates the position of this piece to the given coordinates.
	/// </summary>
	/// <param name="dest">The tile this piece shall move to.</param>
	/// <returns>A member of the ReturnCode enum.</returns>
	RESULT moveTo(Tile &dest);

	/// <summary>
	/// Getter for the tile this piece is standing on.
	/// </summary>
	/// <returns>The tile this piece keeps occupied at the moment.</returns>
	Tile getPosition();

	/// <summary>
	/// Getter for the pieces color.
	/// </summary>
	/// <returns>The color of this piece.</returns>
	Color getColor();

	/// <summary>
	/// Getter for the <c>isKonakis</c> member.
	/// </summary>
	/// <returns>True if the piece is the konakis, false otherwise.</returns>
	bool getIsKonakis();

private:

	/// <summary>
	/// This member tells whether this piece is the konakis piece or not.
	/// Due to the fact that there's only one konakis piece, this may only be true for one piece only.
	/// </summary>
	bool isKonakis;

	/// <summary>
	/// The pieces color.
	/// </summary>
	Color color;

	/// <summary>
	/// The tile this piece is standing on at the moment.
	/// </summary>
	Tile tile;

	/// <summary>
	/// A value from the Positioning enum class.
	/// Can be combined values;
	/// as a piece can be threatened and be standing on a corner and therefore also on an edge tile.
	/// </summary>
	Positioning positioning;
};

