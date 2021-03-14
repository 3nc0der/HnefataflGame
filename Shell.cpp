#include "Shell.h"

#include <iostream>

Shell::Shell()
{
	LOG->writeToLog("New shell instance is created...", LOG_COLOR::GREEN);
	controller = new BoardController();
	running = true;
}

Shell::~Shell()
{
	LOG->writeToLog("Shell instance is deleted...", LOG_COLOR::PURPLE);
	delete controller;
}

RESULT Shell::execute()
{
	LOG->writeToLog("Shell instance executes program.", LOG_COLOR::CYAN);

	while (running)
	{
		std::string command;

		getline(std::cin, command);
		if (command.empty())
		{
			LOG->writeToLog("Command was empty.", LOG_COLOR::YELLOW);
		}

		RESULT res = parseCommand(command);
		if (res == RESULT::INVALID_ARGUMENT)
		{
			LOG->writeToLog("Invalid argument.", LOG_COLOR::YELLOW);
		}
		else if (res == RESULT::ERR)
		{
			LOG->writeToLog("Error occurred while parsing the command.", LOG_COLOR::WHITE, true);
			running = false;
		}
		else if (res == RESULT::ABORTED)
		{
			LOG->writeToLog("User quited the game.", LOG_COLOR::BLUE);
			running = false;
		}
	}

	std::cout << controller->getBoardString() << std::endl;
	return RESULT::OK;
}

RESULT Shell::parseCommand(std::string command)
{
	// move command, undo command, level command, print command, switch command, new game command, reset command, help command, tutorial command, quit command
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
