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
	std::vector<std::string> commandParts;

	RESULT res = Utils::splitString(command, commandParts);
	if (res != RESULT::OK)
	{
		return res;
	}

	if (commandParts[0] == "m" || commandParts[0] == "move")
	{
		commandParts.erase(commandParts.begin());

		res = moveCommand(commandParts);
	}
	else if (commandParts[0] == "u" || commandParts[0] == "undo")
	{
		res = undoCommand();
	}
	else if (commandParts[0] == "p" || commandParts[0] == "print")
	{
		res = printCommand();
	}
	else if (commandParts[0] == "l" || commandParts[0] == "level")
	{
		commandParts.erase(commandParts.begin());

		res = levelCommand(commandParts);
	}
	else if (commandParts[0] == "s" || commandParts[0] == "switch")
	{
		res = switchCommand();
	}
	else if (commandParts[0] == "n" || commandParts[0] == "new")
	{
		res = newCommand();
	}
	else if (commandParts[0] == "r" || commandParts[0] == "reset")
	{
		res = resetCommand();
	}
	else if (commandParts[0] == "h" || commandParts[0] == "help")
	{
		helpCommand();
	}
	else if (commandParts[0] == "t" || commandParts[0] == "tutorial")
	{
		tutorialCommand();
	}
	else if (commandParts[0] == "q" || commandParts[0] == "quit")
	{
		return RESULT::ABORTED;
	}
	else
	{
		LOG->writeToLog("No valid command detected.", LOG_COLOR::YELLOW);
		std::cout << "No valid command detected. Please try again or type \"help\" to view the help page." << std::endl;
		return RESULT::INVALID_ARGUMENT;
	}

	return RESULT::OK;
}

RESULT Shell::moveCommand(std::vector<string> args)
{
	if (args.empty())
	{
		LOG->writeToLog("No arguments found.", LOG_COLOR::YELLOW);
		std::cout << "No arguments found." << std::endl;
		return RESULT::INVALID_ARGUMENT;
	}
	else if (args.size() < 4)
	{

	}

	std::cout << "Move command called." << std::endl;

	return RESULT::OK;
}

RESULT Shell::undoCommand()
{
	std::cout << "Undo command called." << std::endl;

	return RESULT::OK;
}

RESULT Shell::levelCommand(std::vector<string> args)
{
	std::cout << "Level command called." << std::endl;

	return RESULT::OK;
}

RESULT Shell::printCommand()
{
	std::cout << "Print command called." << std::endl;

	return RESULT::OK;
}

RESULT Shell::switchCommand()
{
	std::cout << "Switch command called." << std::endl;

	return RESULT::OK;
}

RESULT Shell::newCommand()
{
	std::cout << "New command called." << std::endl;

	return RESULT::OK;
}

RESULT Shell::resetCommand()
{
	std::cout << "Reset command called." << std::endl;

	return RESULT::OK;
}

void Shell::helpCommand()
{
	std::cout << "Help command called." << std::endl;
}

void Shell::tutorialCommand()
{
	std::cout << "Tutorial command called." << std::endl;
}
