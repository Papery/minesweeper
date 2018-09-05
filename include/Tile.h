#ifndef MINESWEEPER_ENTRY_H
#define MINESWEEPER_ENTRY_H

#include <iostream>

#include "constants.h"

enum TileStatus
{
    revealed, unknown, markedAsMine
};

class Tile
{
public:

    int data;

    TileStatus status;

    void printData() const;

    void printStatus() const;
};

#endif //MINESWEEPER_ENTRY_H
