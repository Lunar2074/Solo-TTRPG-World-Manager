
#ifndef TILE_H

#define TILE_H
#include <string>

class Tile {
public: 
    int location_y ;
    int location_x;
    int biome_type;

    Tile(int x, int y, int z){
        location_x = x;
        location_y = y; 
        biome_type = z;
    }
};

#endif // TILE_H