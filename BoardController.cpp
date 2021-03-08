#include "BoardController.h"

BoardController::BoardController()
{
	game = new HnefataflBoard();
}

BoardController::~BoardController()
{
	delete game;
}

void BoardController::update()
{
}
