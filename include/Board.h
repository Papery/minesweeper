#ifndef MINESWEEPER_BOARD_H
#define MINESWEEPER_BOARD_H

#include <iostream>
#include <vector>
#include <random>
#include <stdexcept>

#include "Tile.h"

enum BoardState
{
    valid, exploded, won
};

class Board
{
private:

    int height;

    int width;

    int numMines;

    int numRevealedEntries;

    std::vector<std::vector<Tile> > fields;

    void placeMine(int y, int x);
    void placeMines();
    void reveal(int y, int x);

public:

    Board() = default;

    void initialize(int height, int width, int numMines);

    BoardState doMove(int y, int x, bool markAsMine);

    void printCurrentState() const;
    void printCompleteBoard() const;
};

#endif //MINESWEEPER_BOARD_H
