#ifndef SANDPILE_H
#define SANDPILE_H

#include "Grid.h"

#include <iostream>
#include <unordered_map>
#include <utility>
#include <tuple>

using namespace std;

class Sandpile
{
    public:

        Sandpile(int _height,int _width,  unordered_map<pair<int, int>, int> _valueMap, unordered_map<int, tuple<int,int,int>> _colorMap);

        // Public Methods
        void generate();

    private:
        int height;
        int width;
        unordered_map<pair<int, int>, int> valueMap;
        unordered_map<int, tuple<int,int,int>> colorMap;
    
        Grid grid;

};

#endif