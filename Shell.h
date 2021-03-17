#pragma once

#include "BoardController.h"

class Shell
{
public:

	Shell();
	~Shell();

	RESULT execute();

private:

	RESULT parseCommand(std::string command);

	RESULT moveCommand(std::vector<string> args);

	RESULT undoCommand();

	RESULT levelCommand(std::vector<string> args);

	RESULT printCommand();

	RESULT switchCommand();

	RESULT newCommand();

	RESULT resetCommand();

	void helpCommand();

	void tutorialCommand();

	BoardController *controller;

	bool running;
};

