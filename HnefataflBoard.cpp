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

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			gameBoard[i][j] = {static_cast<unsigned short>(i), static_cast<unsigned short>(j), Color::NONE, TileType::NORMAL};

			if (i == j && i == (BOARD_SIZE - 1) / 2)
			{
				gameBoard[i][j].tileType = TileType::KONAKIS;
			}
			else if ((i == 0 && j == 0) || (i == 0 && j == BOARD_SIZE - 1) || (i == BOARD_SIZE - 1 && j == BOARD_SIZE - 1) || (i == BOARD_SIZE - 1 && j == 0))
			{
				gameBoard[i][j].tileType = TileType::CORNER;
			}

			//TODO: Add function to read in a game from a text file or something.
			if (i == 0)
			{
				if (j >= 3 && j <= 7)
				{
					gameBoard[i][j].occupiedBy = Color::BLACK;
					machinePieces.push_back(Warrior());
				}
			}
			else if (i == 1)
			{
				if (j == 5)
				{
					gameBoard[i][j].occupiedBy = Color::BLACK;
					machinePieces.push_back(Warrior());
				}
			}
			else if (i == 3)
			{
				if (j == 0 || j == BOARD_SIZE - 1)
				{
					gameBoard[i][j].occupiedBy = Color::BLACK;
					machinePieces.push_back(Warrior());
				}
				else if (j == 5)
				{
					gameBoard[i][j].occupiedBy = Color::WHITE;
					humanPieces.push_back(Warrior());
				}
			}
			else if (i == 4)
			{
				if (j == 0 || j == BOARD_SIZE - 1)
				{
					gameBoard[i][j].occupiedBy = Color::BLACK;
					machinePieces.push_back(Warrior());
				}
				else if (j >= 4 && j <= 6)
				{
					gameBoard[i][j].occupiedBy = Color::WHITE;
					humanPieces.push_back(Warrior());
				}
			}
			else if (i == 5)
			{
				if (j == 0 || j == BOARD_SIZE - 1 || j == 1 || j == BOARD_SIZE - 2)
				{
					gameBoard[i][j].occupiedBy = Color::BLACK;
					machinePieces.push_back(Warrior());
				}
				else if (j >= 3 && j <= 7)
				{
					if (j == 5)
					{
						gameBoard[i][j].occupiedBy = Color::KONAKIS;
						humanPieces.push_back(Konakis());
					}
					else
					{
						gameBoard[i][j].occupiedBy = Color::WHITE;
						humanPieces.push_back(Warrior());
					}
				}
			}
			else if (i == 6)
			{
				if (j == 0 || j == BOARD_SIZE - 1)
				{
					gameBoard[i][j].occupiedBy = Color::BLACK;
					machinePieces.push_back(Warrior());
				}
				else if (j >= 4 && j <= 6)
				{
					gameBoard[i][j].occupiedBy = Color::WHITE;
					humanPieces.push_back(Warrior());
				}
			}
			else if (i == 7)
			{
				if (j == 0 || j == BOARD_SIZE - 1)
				{
					gameBoard[i][j].occupiedBy = Color::BLACK;
					machinePieces.push_back(Warrior());
				}
				else if (j == 5)
				{
					gameBoard[i][j].occupiedBy = Color::WHITE;
					humanPieces.push_back(Warrior());
				}
			}
			else if (i == 9)
			{
				if (j == 5)
				{
					gameBoard[i][j].occupiedBy = Color::BLACK;
					machinePieces.push_back(Warrior());
				}
			}
			else if (i == 10)
			{
				if (j >= 3 && j <= 7)
				{
					gameBoard[i][j].occupiedBy = Color::BLACK;
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
	if (!validateMove(move))
	{
		return nullptr;
	}


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

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			res += gameBoard[i][j].toString();
		}

		res += "\n";
	}

	return res;
}

bool HnefataflBoard::validateMove(Move move)
{
	if (assertMove(move))
	{
		return false;
	}

	// TODO: remove the konakis color again and also the extra classes for konakis and warrior.
	if (gameBoard[move.getSource().row][move.getSource().col].occupiedBy != getCurrentPlayersColor())
	{
		return false;
	}
	else if (isTileOccupied(move.getDestination()))
	{
		return false;
	}
	
	// TODO: add the check for konakis and corner tiles on normal pieces' destination.

	Position dir = move.getDirection();

	for (unsigned short i = 0; i < move.getDistance(); i++)
	{
		if (gameBoard[move.getSource().row + i * dir.row][move.getSource().col + i * dir.col].occupiedBy != Color::NONE)
		{
			return false;
		}
	}
}

bool HnefataflBoard::assertMove(Move move)
{
	if (move.rowFrom >= BOARD_SIZE || move.rowFrom < 0)
	{
		return true;
	}
	else if (move.rowTo >= BOARD_SIZE || move.rowTo < 0)
	{
		return true;
	}
	else if (move.colFrom >= BOARD_SIZE || move.colFrom < 0)
	{
		return true;
	}
	else if (move.colTo >= BOARD_SIZE || move.colTo < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool HnefataflBoard::isTileOccupied(Position pos)
{
	if (gameBoard[pos.row][pos.col].occupiedBy != Color::NONE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Color HnefataflBoard::getCurrentPlayersColor()
{
	switch (currentPlayer)
	{
		case Player::HUMAN:
		{
			return humanColor;
		}
		case Player::MACHINE:
		{
			return machineColor;
		}
		default:
		{
			return Color::NONE;
		}
	}
}

Piece* HnefataflBoard::getCurrentPlayersPieceAt(Position pos)
{
	switch (currentPlayer)
	{
		case Player::HUMAN:
		{
			std::list<Piece>::iterator i = humanPieces.begin();
			for (; i != humanPieces.end(); i++)
			{
				if ((*i).getPosition().getPosition() == pos)
				{
					return &(*i);
				}
			}

			return nullptr;
		}
		case Player::MACHINE:
		{
			std::list<Piece>::iterator i = machinePieces.begin();
			for (; i != machinePieces.end(); i++)
			{
				if ((*i).getPosition().getPosition() == pos)
				{
					return &(*i);
				}
			}

			return nullptr;
		}
		default:
		{
			return nullptr;
		}
	}
}
