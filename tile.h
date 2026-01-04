
#ifndef TILE_H

#define TILE_H
#include <string>
#include "PointsOfInterest.h"
#include <vector>

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

std::vector<std::vector<Tile>> generateTileMap(int width, int height);

std::string getBiomeColor(std::string biome);

void generateRivers(std::vector<std::vector<Tile>> &tileMap);
void displayTileMap(const std::vector<std::vector<Tile>> &tileMap);

#endif // TILE_H