#ifndef SANDPILE_H
#define SANDPILE_H

#include "Grid.h"

#include <iostream>
#include <unordered_map>
#include <utility>
#include <tuple>


namespace std {

  // Frankensteined from https://stackoverflow.com/questions/17016175/c-unordered-map-using-a-custom-class-type-as-the-key

  template <>
  struct hash<pair<int, int>>
  {
    std::size_t operator()(const pair<int, int>& k) const
    {
      using std::size_t;
      using std::hash;

      // Compute individual hash values for first and
      // second and combine them using XOR
      // and bit shifting:

      return ((hash<int>()(k.first) ^ (hash<int>()(k.second) << 1)) >> 1);
    }
  };

}


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