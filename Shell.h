#pragma once

#include "BoardController.h"

class Shell
{
public:

	Shell();
	~Shell();

	RESULT execute();

	RESULT parseCommand();

	RESULT moveCommand();

	RESULT undoCommand();

	RESULT levelCommand();
};

