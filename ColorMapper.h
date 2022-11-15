#ifndef COLORMAPPER_H
#define COLORMAPPER_H

#include <vector>
#include <unordered_map>
#include <tuple>

using namespace std;

class ColorMapper
{
    public:

        ColorMapper( vector<vector<int>>& rawData, unordered_map<int, tuple<int, int, int>> colorMap );
        
        // populates a 2D array of RGB values.
        void map(vector<vector<tuple<int, int, int>>>& mapRef);
        

    private:
        vector<vector<int>> rawData;
        unordered_map<int, tuple<int, int, int>> colorMap;


};

#endif