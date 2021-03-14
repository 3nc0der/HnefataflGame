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

	RESULT moveCommand();

	RESULT undoCommand();

	RESULT levelCommand();

	BoardController *controller;

	bool running;
};

