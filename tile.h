
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

    Tile(int x, int y, std::string z, std::string q, std::string w, std::string t, int e){
        location_x = x;
        location_y = y; 
        biome_type = z;
        Point.name = q;
        Point.monsters1 = w;
        Point.monsters2 = t;
        Point.pointType = e; 

    }
};

#endif // TILE_H