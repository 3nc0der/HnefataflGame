#include "Piece.h"

RESULT Piece::moveTo(Tile &dest)
{
	RESULT res = Utils::validateTile(dest);

	if (res == RESULT::OK)
	{
		tile = dest;
		dest.occupiedBy = color;
	}
	
	return res;
}

Tile Piece::getPosition()
{
	return tile;
}

Color Piece::getColor()
{
	return color;
}

bool Piece::getIsKonakis()
{
	return isKonakis;
}
