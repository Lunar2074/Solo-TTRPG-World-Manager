#include <iostream>
#include "tile.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    Tile Tile1(1,1,"Grass");

    std::cout << Tile1.biome_type << "/"  << Tile1.location_x << "/"<< Tile1.location_y;
    return 0;
}
