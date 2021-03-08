#include "HnefataflBoard.h"

HnefataflBoard::HnefataflBoard() : humanColor(Color::BLACK), machineColor(Color::WHITE)
{
	gameState = GameState::MENU;
	currentPlayer = Player::MACHINE;
	nextPlayer = Player::HUMAN;
	machineLevel = 3;
	moveStack = stack<Board>();
	humanPieces = list<Piece>();
	machinePieces = list<Piece>();
}

HnefataflBoard::HnefataflBoard(HnefataflBoard& hb) : humanColor(hb.humanColor), machineColor(hb.machineColor)
{
}

HnefataflBoard::~HnefataflBoard()
{
}

Board* HnefataflBoard::move(Move move)
{
	return nullptr;
}

Board* HnefataflBoard::machineMove()
{
	return nullptr;
}

Board* HnefataflBoard::undo()
{
	return nullptr;
}

void HnefataflBoard::setMachineDifficulty(int level)
{
}

int HnefataflBoard::getMachineDifficulty()
{
	return 0;
}

Player HnefataflBoard::getWinner()
{
	return Player();
}

bool HnefataflBoard::isOver()
{
	return false;
}

GameState HnefataflBoard::getGameState()
{
	return GameState();
}

void HnefataflBoard::setGameState(GameState gameState)
{
}

list<Piece>* HnefataflBoard::getMachinePieces()
{
	return nullptr;
}

list<Piece>* HnefataflBoard::getHumanPieces()
{
	return nullptr;
}

const Color HnefataflBoard::getMachineColor()
{
	return Color();
}

const Color HnefataflBoard::getHumanColor()
{
	return Color();
}

Player HnefataflBoard::getCurrentPlayer()
{
	return Player();
}

Player HnefataflBoard::getNextPlayer()
{
	return Player();
}
