
#include "ColorMapper.h"

ColorMapper::ColorMapper( vector<vector<int>>& _rawData, unordered_map<int, tuple<int, int, int>> _colorMap )
    : rawData(_rawData), colorMap(_colorMap)
{
    // Default    
}

void ColorMapper::map( vector<vector<tuple<int,int,int>>>& mapRef ) // rename this ability... irritates me that no maps are in this function.
{
    for (int h = 0; h < rawData.size(); h++) //TODO Update to foreach... I didn't think they'd make sense here, but turns out they do.
    {
        vector<int> rawRow = rawData[h];
        vector<tuple<int,int,int>> mapRefRow;

        for(int w = 0; w < rawRow.size(); w++)
        {
            tuple<int, int, int> rgb = colorMap[rawRow[w]];
            mapRefRow.push_back(rgb);   
        }
        mapRef.push_back(mapRefRow);
    }
}
