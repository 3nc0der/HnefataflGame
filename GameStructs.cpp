#include "GameStructs.h"

Position Move::getDestination()
{
	Position pos;
	pos.col = colTo;
	pos.row = rowTo;

	return pos;
}

Position Move::getSource()
{
	Position pos;
	pos.col = colFrom;
	pos.row = rowFrom;

	return pos;
}

unsigned short Move::getDistance()
{
	if (colTo != colFrom)
	{
		return (colFrom - colTo) < 0 ? (colTo - colFrom) : (colFrom - colTo);
	}
	else if (rowTo != rowFrom)
	{
		return (rowFrom - rowTo) < 0 ? (rowTo - rowFrom) : (rowFrom - rowTo);
	}
	else
	{
		return 0;
	}
}

std::string Tile::toString()
{
	switch (tileColor)
	{
		case Color::NONE:
		{
			return " ";
		}
		case Color::WHITE:
		{
			return "W";
		}
		case Color::BLACK:
		{
			return "B";
		}
		case Color::KONAKIS:
		{
			return "K";
		}
		default:
		{
			return "#";
		}
	}
}