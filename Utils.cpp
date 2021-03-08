#include "Utils.h"

RESULT Utils::validateTile(Tile tile)
{
    if (tile.row >= SIZE || tile.col >= SIZE || tile.row < 0 || tile.col < 0)
    {
        return RESULT::INVALID_ARGUMENT;
    }

    return RESULT::OK;
}
