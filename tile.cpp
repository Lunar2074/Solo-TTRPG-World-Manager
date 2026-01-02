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