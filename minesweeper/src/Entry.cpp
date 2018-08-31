#include "Entry.h"

void Entry::printData() const
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

void Entry::printStatus() const
{
    if (status == Status::unknown)
    {
        std::cout << "?  ";
    }
    else if (status == Status::mine)
    {
        std::cout << "*  ";
    }
    else
    {
        printData();
    }
}
