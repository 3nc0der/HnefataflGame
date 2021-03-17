#include "Utils.h"

RESULT Utils::validateTile(Tile tile)
{
    if (tile.row >= BOARD_SIZE || tile.col >= BOARD_SIZE || tile.row < 0 || tile.col < 0)
    {
        return RESULT::INVALID_ARGUMENT;
    }

    return RESULT::OK;
}

RESULT Utils::splitString(std::string text, std::vector<std::string>& container, char delimiter)
{
    std::string temp = "";

    for (int i = 0; i < text.size(); i++)
    {
        if (text[i] == delimiter)
        {
            container.push_back(temp);
            temp = "";
        }
        else
        {
            temp.push_back(text[i]);
        }
    }

    container.push_back(temp);

    return RESULT::OK;
}
