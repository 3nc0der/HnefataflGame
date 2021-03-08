#pragma once

/// <summary>
/// An enum class for the every possible positioning of a piece.
/// The values are encoded by one-hot-encoding and can therefore be combined using the binary or operator.
/// </summary>
enum class Positioning
{
	/// <summary>
	/// The piece is fully blocked by other pieces and can't move at all.
	/// </summary>
	BLOCKED = 0b00001,

	/// <summary>
	/// The piece can move, but in only one direction.
	/// </summary>
	HALF_BLOCKED = 0b00010,

	/// <summary>
	/// The piece stands on a tile right next to the konakis tile.
	/// </summary>
	NEXT_TO_KONAKIS = 0b00100,

	/// <summary>
	/// The piece stands next to a corner tile.
	/// </summary>
	NEXT_TO_CORNER = 0b01000,

	/// <summary>
	/// The piece stands on an edge tile.
	/// </summary>
	ON_EDGE = 0b10000,

	/// <summary>
	/// The piece is currently isolated, meaning there is no other piece in a 1 tile ring around this piece.
	/// </summary>
	ISOLATED = 0b100000,

	/// <summary>
	/// The piece is currently being threatened, meaning it can be taken the next move of the opponent.
	/// </summary>
	THREATENED = 0b1000000
};
