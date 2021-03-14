#include "HnefataflBoard.h"
#include "Warrior.h"
#include "Konakis.h"

HnefataflBoard::HnefataflBoard() : humanColor(Color::WHITE), machineColor(Color::BLACK)
{
	gameState = GameState::MENU;
	currentPlayer = Player::MACHINE;
	nextPlayer = Player::HUMAN;
	machineLevel = 3;
	humanPieces = list<Piece>();
	machinePieces = list<Piece>();

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			gameBoard[i][j] = {static_cast<unsigned short>(i), static_cast<unsigned short>(j), Color::NONE, TileType::NORMAL};

			if (i == j && i == (SIZE - 1) / 2)
			{
				gameBoard[i][j].tileType = TileType::KONAKIS;
			}
			else if ((i == 0 && j == 0) || (i == 0 && j == SIZE - 1) || (i == SIZE - 1 && j == SIZE - 1) || (i == SIZE - 1 && j == 0))
			{
				gameBoard[i][j].tileType = TileType::CORNER;
			}

			//TODO: Add function to read in a game from a text file or something.
			if (i == 0)
			{
				if (j >= 3 && j <= 7)
				{
					gameBoard[i][j].tileColor = Color::BLACK;
					machinePieces.push_back(Warrior());
				}
			}
			else if (i == 1)
			{
				if (j == 5)
				{
					gameBoard[i][j].tileColor = Color::BLACK;
					machinePieces.push_back(Warrior());
				}
			}
			else if (i == 3)
			{
				if (j == 0 || j == SIZE - 1)
				{
					gameBoard[i][j].tileColor = Color::BLACK;
					machinePieces.push_back(Warrior());
				}
				else if (j == 5)
				{
					gameBoard[i][j].tileColor = Color::WHITE;
					humanPieces.push_back(Warrior());
				}
			}
			else if (i == 4)
			{
				if (j == 0 || j == SIZE - 1)
				{
					gameBoard[i][j].tileColor = Color::BLACK;
					machinePieces.push_back(Warrior());
				}
				else if (j >= 4 && j <= 6)
				{
					gameBoard[i][j].tileColor = Color::WHITE;
					humanPieces.push_back(Warrior());
				}
			}
			else if (i == 5)
			{
				if (j == 0 || j == SIZE - 1 || j == 1 || j == SIZE - 2)
				{
					gameBoard[i][j].tileColor = Color::BLACK;
					machinePieces.push_back(Warrior());
				}
				else if (j >= 3 && j <= 7)
				{
					if (j == 5)
					{
						gameBoard[i][j].tileColor = Color::KONAKIS;
						humanPieces.push_back(Konakis());
					}
					else
					{
						gameBoard[i][j].tileColor = Color::WHITE;
						humanPieces.push_back(Warrior());
					}
				}
			}
			else if (i == 6)
			{
				if (j == 0 || j == SIZE - 1)
				{
					gameBoard[i][j].tileColor = Color::BLACK;
					machinePieces.push_back(Warrior());
				}
				else if (j >= 4 && j <= 6)
				{
					gameBoard[i][j].tileColor = Color::WHITE;
					humanPieces.push_back(Warrior());
				}
			}
			else if (i == 7)
			{
				if (j == 0 || j == SIZE - 1)
				{
					gameBoard[i][j].tileColor = Color::BLACK;
					machinePieces.push_back(Warrior());
				}
				else if (j == 5)
				{
					gameBoard[i][j].tileColor = Color::WHITE;
					humanPieces.push_back(Warrior());
				}
			}
			else if (i == 9)
			{
				if (j == 5)
				{
					gameBoard[i][j].tileColor = Color::BLACK;
					machinePieces.push_back(Warrior());
				}
			}
			else if (i == 10)
			{
				if (j >= 3 && j <= 7)
				{
					gameBoard[i][j].tileColor = Color::BLACK;
					machinePieces.push_back(Warrior());
				}
			}
		}
	}
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

HnefataflBoard* HnefataflBoard::move(Move move)
{
	return nullptr;
}

HnefataflBoard* HnefataflBoard::machineMove()
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

std::string HnefataflBoard::toString()
{
	std::string res = "";

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			res += gameBoard[i][j].toString();
		}
	}

	return res;
}
