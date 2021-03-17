#pragma once

#include "ReturnCodes.h"
#include "GameStructs.h"
#include "logfile.h"

#include <vector>

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

	/// <summary>
	/// This function splits a given string with an optionally given delimiter and puts the resulting words into a vector.
	/// </summary>
	/// <param name="text">The string to split.</param>
	/// <param name="container">The vector that shall contain the splitted string such that every element of the vector is one word.</param>
	/// <param name="delimiter">The character the function will split the string at.</param>
	/// <returns><c>INVALID_ARGUMENT</c> if the given string is empty, <c>OK</c> otherwise.</returns>
	static RESULT splitString(std::string text, std::vector<std::string>& container, char delimiter = ' ');
};

