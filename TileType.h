#pragma once

/// <summary>
/// An enum class for the type of one tile.
/// Can be useful as with different tile types there are different move options and rules.
/// </summary>
enum class TileType
{
	/// <summary>
	/// A normal tile, everyone can move on them and they don't have special rules connected with them.
	/// </summary>
	NORMAL = 0,

	/// <summary>
	/// The tile right in the middle of the board. Only the king can move onto this tile 
	/// and if he stands right next to it, he may be captured only by three warriors.
	/// </summary>
	KONAKIS,

	/// <summary>
	/// One of the four tiles in the corners of the board.
	/// A warrior may not move onto these and can be captured by one enemy warrior if he stands right next to it.
	/// </summary>
	CORNER
};
