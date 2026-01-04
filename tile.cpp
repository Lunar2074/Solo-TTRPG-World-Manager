#include "tile.h"
#include <cstdlib>

std::string generateBiome(){
    std::vector<std::string> biomes = {"Grass", "Desert", "Snow", "Forest", "Swamp"};
    int randomNum = rand()% biomes.size();
    std::string biome = biomes[randomNum];

    return biome;
}

void generateTile(Tile &tile){
    tile.biome_type = generateBiome();
}

std::vector<std::vector<Tile>> generateTileMap(int width, int height){
    std::vector<std::vector<Tile>> tileMap;

    for (int i = 0; i < width; i ++){
        std::vector<Tile> row;
        for (int j = 0; j < height; j++){
            PointOfInterest poi;
            generatePointOfInterest(poi);
            Tile tile(i, j, generateBiome(), poi);
            row.push_back(tile);
            std::cout << "[" << tile.location_x << ","<< tile.location_y <<"]";
        } std::cout << std::endl;
        tileMap.push_back(row);
    }
    return tileMap;
}