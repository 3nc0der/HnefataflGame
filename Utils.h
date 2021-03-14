#pragma once

#include "ReturnCodes.h"
#include "GameStructs.h"

#define ABS(x) {if (x < 0) { -(x); } else { x; }}

/// <summary>
/// A utility class which only consists out of static functions and has no members.
/// The class will hold functions that are likely to be useful everywhere and that many classes need access to.
/// </summary>
class Utils
{
public:

	/// <summary>
	/// The function will check a given tile, if the tile position would be out of bounds.
	/// </summary>
	/// <param name="tile">The tile that will be checked and validated.</param>
	/// <returns>A member of the ReturnCodes enum.</returns>
	static RESULT validateTile(Tile tile);
};

