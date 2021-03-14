#include "BoardController.h"

BoardController::BoardController()
{
	LOG->writeToLog("New controller instance is created...", LOG_COLOR::GREEN);
	moveStack = stack<HnefataflBoard*>();
	game = new HnefataflBoard();
}

BoardController::~BoardController()
{
	LOG->writeToLog("Controller instance is deleted...", LOG_COLOR::PURPLE);
	delete game;
	while (moveStack.size() > 0)
	{
		moveStack.pop();
	}
}

std::string BoardController::getBoardString()
{
	if (game != nullptr)
	{
		return game->toString();
	}

	return "Error. Couldn't read game string.";
}

void BoardController::update()
{
}

RESULT BoardController::undo()
{
	if (moveStack.size() > 1)
	{
		game = moveStack.top();
		moveStack.pop();

		return RESULT::OK;
	}

	return RESULT::ERR;
}
