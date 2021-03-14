#include "Shell.h"

#include <iostream>

Shell::Shell()
{
	LOG->writeToLog("New shell instance is created...", LOG_COLOR::GREEN);
	controller = new BoardController();
}

Shell::~Shell()
{
	LOG->writeToLog("Shell instance is deleted...", LOG_COLOR::PURPLE);
	delete controller;
}

RESULT Shell::execute()
{
	LOG->writeToLog("Shell instance executes program.", LOG_COLOR::CYAN);
	std::cout << controller->getBoardString() << std::endl;
	return RESULT::OK;
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
