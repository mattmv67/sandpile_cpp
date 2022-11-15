#ifndef GRID_H
#define GRID_H

#include "Cell.h"

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Grid
{
    public:
    
        // Constructor def
        Grid(int _height, int _width);

        // Public methods
        vector<vector<int>>* exportGrid();
        
        inline Cell* getCell(int h, int w) { return cellGrid[h][w];} // TODO investigate if these inlines have an effect on the speed of the program.
        
        bool iterate();
        void setCellValue(int h, int w, int value); // Careful, only use this within the constructor of the Grid (or before iterate is called.)... otherwise the unstableSet could be inaccurate



        inline int getTick() { return tick; }

    private:
        int height;
        int width;
        int tick = 0;
        vector<vector<Cell*>> cellGrid;
        unordered_set<Cell*> unstableSet;

};

#endif