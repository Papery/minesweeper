#include "Tile.h"

void Tile::printData() const
{
    if (data == MINE)
    {
        std::cout << "x  ";
    }
    else
    {
        std::cout << data << "  ";
    }
}

void Tile::printStatus() const
{
    if (status == TileStatus::unknown)
    {
        std::cout << "?  ";
    }
    else if (status == TileStatus::markedAsMine)
    {
        std::cout << "*  ";
    }
    else
    {
        printData();
    }
}

