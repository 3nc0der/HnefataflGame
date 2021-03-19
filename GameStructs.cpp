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

Position Move::getDirection()
{
	if (colTo != colFrom)
	{
		return { 0, (colTo - colFrom) / getDistance() };
	}
	else if (rowTo != rowFrom)
	{
		return { (rowTo - rowFrom) / getDistance() , 0 };
	}
	else
	{
		return { 0, 0 };
	}
}

Position Tile::getPosition()
{
	Position pos = { row, col };

	return pos;
}

std::string Tile::toString()
{
	switch (occupiedBy)
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
