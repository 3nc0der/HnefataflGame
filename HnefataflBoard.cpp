#include "HnefataflBoard.h"

HnefataflBoard::HnefataflBoard() : humanColor(Color::BLACK), machineColor(Color::WHITE)
{
	gameState = GameState::MENU;
	currentPlayer = Player::MACHINE;
	nextPlayer = Player::HUMAN;
	machineLevel = 3;
	humanPieces = list<Piece>();
	machinePieces = list<Piece>();
}

HnefataflBoard::HnefataflBoard(HnefataflBoard& hb) : humanColor(hb.humanColor), machineColor(hb.machineColor)
{
	gameState = hb.gameState;
	currentPlayer = hb.currentPlayer;
	nextPlayer = hb.nextPlayer;
	machineLevel = hb.machineLevel;
	humanPieces = hb.humanPieces;
	machinePieces = hb.machinePieces;
}

HnefataflBoard::~HnefataflBoard()
{
	humanPieces.clear();
	machinePieces.clear();
}

Board* HnefataflBoard::move(Move move)
{
	return nullptr;
}

Board* HnefataflBoard::machineMove()
{
	return nullptr;
}

void HnefataflBoard::setMachineDifficulty(int level)
{
	machineLevel = level;
}

int HnefataflBoard::getMachineDifficulty()
{
	return machineLevel;
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
	return gameState;
}

void HnefataflBoard::setGameState(GameState gameState)
{
	this->gameState = gameState;
}

list<Piece>* HnefataflBoard::getMachinePieces()
{
	return &machinePieces;
}

list<Piece>* HnefataflBoard::getHumanPieces()
{
	return &humanPieces;
}

const Color HnefataflBoard::getMachineColor()
{
	return machineColor;
}

const Color HnefataflBoard::getHumanColor()
{
	return humanColor;
}

Player HnefataflBoard::getCurrentPlayer()
{
	return currentPlayer;
}

Player HnefataflBoard::getNextPlayer()
{
	return nextPlayer;
}
