
#include "Sandpile.h"
#include "ColorMapper.h"
#include "Grid.h"

#include <unordered_map>
#include <utility>
#include <tuple>

Sandpile::Sandpile( int _height,
                    int _width, 
                    unordered_map<pair<int, int>, int> _valueMap,
                    unordered_map<int, tuple<int, int, int>> _colorMap) 
                   : height(_height), width(_width), valueMap(_valueMap), colorMap(_colorMap), grid(*(new Grid(_height, _width)))
{
    // Populate grid with values from valueMap
}

void Sandpile::generate()
{
    int h_div_2 = height / 2;
    int w_div_2 = width / 2;
    Cell* centerCell = grid.getCell(h_div_2, w_div_2); // TODO should this reference be const in any way? 

    while (grid.iterate())
    {

        // TODO here is where to put in other options, like recording the entire drawing process of the fractal.
        if (grid.getTick() % 100 == 0)
        {
                // Every 100 iterations, export the state of the grid + give some cout info.
                vector<vector<int>> raw = *grid.exportGrid(); // calls new, need to delete

                cout << "Tick: " << grid.getTick() << " Center cell value: " << centerCell->getValue() << endl;

                ColorMapper colorMapper = ColorMapper(raw, colorMap); // TODO pass colormap by reference.

                vector<vector<tuple<int, int, int>>> rgbs;
                colorMapper.map(rgbs);
        }
    }

}