#include "Shell.h"

#include <iostream>

Shell::Shell()
{
	controller = BoardController();
}

Shell::~Shell()
{
}

RESULT Shell::execute()
{
	std::cout << controller.getBoardString() << std::endl;
}

RESULT Shell::parseCommand()
{
	return RESULT();
}

RESULT Shell::moveCommand()
{
	return RESULT();
}

RESULT Shell::undoCommand()
{
	return RESULT();
}

RESULT Shell::levelCommand()
{
	return RESULT();
}
