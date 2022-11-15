#include "Grid.h"
#include "Cell.h"

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

Grid::Grid(int _height, int _width): height(_height), width(_width)
{
    // optimization variables
    int h_minus_1  = height - 1;
    int w_minus_1  = width - 1;

    // Create the unstableSet which will keep track of which cells are unstable.
    unordered_set<Cell*>* unstableSet_ptr = new unordered_set<Cell*>();
    unstableSet = *unstableSet_ptr;
    unstableSet.reserve (height * width);

    // Populate cellGrid with [height x width] Cell objects.
    cout << "[Grid] Populating cell grid" << endl;

    cellGrid.reserve(height);
    for (int h = 0; h < height ; h++)
    {
        vector<Cell*>* row = new vector<Cell*>();
        row->reserve(width);
        for (int w = 0; w < width ; w++)
        {
            Cell* newCell_ptr = new Cell(h, w, 0, unstableSet);
            if (!newCell_ptr->isStable())
            {
                unstableSet.insert(newCell_ptr);
            }

            row->push_back(newCell_ptr);
        }
        cellGrid.push_back(*row);
    }
    cout << "\t...DONE!" << endl;

    // form neighbor associations within the cells.
    cout << "[Grid] Assigning neighbor associations" << endl;
    for (int h = 0; h < height ; h++)
    {
        for (int w = 0; w < width ; w++)
        {
            Cell* currentCell_ptr = cellGrid.at(h).at(w);

            if (w != 0)
            {
                currentCell_ptr->addNeighbor(cellGrid[h][w-1]);
            }
            if (w != w_minus_1)
            {
                currentCell_ptr->addNeighbor(cellGrid[h][w+1]);
            }
            if (h != 0)
            {
                currentCell_ptr->addNeighbor(cellGrid[h-1][w]);
            }
            if (h != h_minus_1)
            {
                currentCell_ptr->addNeighbor(cellGrid[h+1][w]);
            }
        }
    }
    cout << "\t...DONE!" << endl;
}

bool Grid::iterate()
{
    tick++;

    unordered_set<Cell*> converts;
    if (unstableSet.size() != 0)
    {
        converts.reserve((unstableSet.size() * 4) + unstableSet.size());
    }

    for (Cell* cell_ptr : unstableSet)
    {
        cell_ptr->shatter();
        converts.insert(cell_ptr);
        for (Cell* n : cell_ptr->getNeighbors())
        {
            // Since this cell was unstable, it's neighbors need to have their buffers converted.
            converts.insert(n);
        }
    }

    if (converts.size() != 0)
    {
        for (Cell* c : converts)
        {
            c->convert();
        }
        return true;
    }
    else
    {
        // stable configuration!
        return false;
    }
}

void Grid::setCellValue(int h, int w, int value)
{
    // Careful, only use this within the constructor of the Grid (or sandpile before calling iterate)... otherwise the unstableSet could be inaccurate
    cellGrid.at(h).at(w)->setValue(value);
}

vector<vector<int>>* Grid::exportGrid()
{
    vector<vector<int>>* ret = new vector<vector<int>>();
    ret->reserve(height);
    for (auto each : cellGrid)
    {
        vector<int>* row = new vector<int>();
        row->reserve(width);
        for (Cell* cell_p : each)
        {
            row->push_back(cell_p->getValue());
        }
        ret->push_back(*row);
    }

    return ret;
}