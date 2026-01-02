
#ifndef TILE_H

#define TILE_H
#include <string>
#include "PointsOfInterest.h"

class Tile {
public: 
    int location_y ;
    int location_x;
    std::string biome_type;
    PointOfInterest Point;

    Tile(int x, int y, std::string biome, PointOfInterest poi){
        location_x = x;
        location_y = y; 
        biome_type = biome;
        Point = poi;

    }
};

void generateTile(Tile &tile);

#endif // TILE_H