#ifndef MINESWEEPER_ENTRY_H
#define MINESWEEPER_ENTRY_H

#include <iostream>

#include "constants.h"

enum Status
{
    mine, revealed, unknown
};

class Entry
{
public:

    int data;

    Status status;

    void printData();

    void printStatus();
};

#endif //MINESWEEPER_ENTRY_H
