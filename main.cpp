#include <iostream>
#include "tile.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    PointOfInterest poi1;
    generatePointOfInterest(poi1);
    Tile Tile1(1,1,"Grass", poi1);

    std::cout << Tile1.biome_type << "/"  << Tile1.location_x << "/"<< Tile1.location_y<< std::endl;
    std::cout << "Point of Interest: " << Tile1.Point.name << std::endl;
    std::cout << "Monsters: " << Tile1.Point.monsters1 << ", " << Tile1.Point.monsters2 << std::endl;
    
    return 0;
}

