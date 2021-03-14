#include "BoardController.h"

BoardController::BoardController()
{
	moveStack = stack<HnefataflBoard*>();
	game = new HnefataflBoard();
}

BoardController::~BoardController()
{
	delete game;
	while (moveStack.size() > 0)
	{
		moveStack.pop();
	}
}

std::string BoardController::getBoardString()
{
	return game->toString();
}

void BoardController::update()
{
}

HnefataflBoard* BoardController::undo()
{
	if (moveStack.size() > 1)
	{
		game = moveStack.top();
		moveStack.pop();
	}
}
