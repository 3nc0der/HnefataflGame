#include "Utils.h"

RESULT Utils::validateTile(Tile tile)
{
    if (tile.row >= BOARD_SIZE || tile.col >= BOARD_SIZE || tile.row < 0 || tile.col < 0)
    {
        return RESULT::INVALID_ARGUMENT;
    }

    return RESULT::OK;
}
