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

    void printData() const;

    void printStatus() const;
};

#endif //MINESWEEPER_ENTRY_H
