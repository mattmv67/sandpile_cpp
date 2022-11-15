#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string> 

using namespace std;

class Cell
{
    public:
    
        // Constructor def
        Cell(int _h, int _w, int _value, unordered_set<Cell*>& _unstableSet);

        // Public methods
        inline int getH() { return h; }
        inline int getW() { return w; }
        // inline const string& getId() const { return id; }

        inline int getValue() { return value; }

        inline void setValue(int _value) { value = _value; }

        inline vector<Cell*>& getNeighbors() { return neighbors;}

        inline void addNeighbor (Cell* neighbor) { neighbors.push_back(neighbor); };

        // inline void setNeighbors(vector<Cell*>& _neighbors) { neighbors = _neighbors; }
        
        inline bool isStable() const { return value < 4; }

        inline void stack() { buffer++; }
        
        void shatter();

        void convert();

    private:

        int value;
        int buffer = 0;
        int h;
        int w;

        // string id;
        unordered_set<Cell*> unstableSet;
        vector<Cell*> neighbors;

};

#endif