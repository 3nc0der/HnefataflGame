#include "Piece.h"

RESULT Piece::moveTo(Tile dest)
{
	tile = dest;
}

Tile Piece::getPosition()
{
	return tile;
}

const Color Piece::getColor()
{
	return color;
}
