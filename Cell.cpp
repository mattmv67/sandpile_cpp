#include "Cell.h"

#include <string>
#include <vector>
#include <unordered_set>

// Constructor
Cell::Cell(const int _h, const int _w, int _value, unordered_set<Cell*>& _unstableSet): h(_h), w(_w), value(_value), unstableSet(_unstableSet)
{
    // Allocate space for neighbors.
    neighbors.reserve(4);

    // Set ID to "h,w" this will be used to register the cell within the unstableMap
    // id = to_string(h) + "," + to_string(w);
}

void Cell::shatter()
{
    buffer -= 4;
    for (Cell* n : getNeighbors())
    {
        n->stack();
    }
}

void Cell::convert()
{
    value += buffer;
    buffer = 0;

    if (!isStable())
    {
        // Register this cell in the unstableSet
        unstableSet.insert(this);
    }
    else
    {
        // This cell is no longer unstable, unregister from the unstableSet
        unstableSet.erase(this);
    }
}