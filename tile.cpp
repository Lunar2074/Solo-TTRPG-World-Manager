#include "tile.h"
#include <cstdlib>
#include <ctime>




std::string generateBiome(){
    std::vector<std::string> biomes = {"Grass", "Desert", "Snow", "Forest", "Swamp"};
    int randomNum = rand()% biomes.size();
    std::string biome = biomes[randomNum];

    return biome;
}

void generateTile(Tile &tile){
    tile.biome_type = generateBiome();
}

std::string getBiomeColor(std::string biome) {
    if (biome == "Grass") return "\033[32m";   // Green
    if (biome == "Forest") return "\033[92m";  // Green
    if (biome == "Desert") return "\033[33m";  // Yellow
    if (biome == "Snow") return "\033[37m";    // White
    if (biome == "Swamp") return "\033[35m";   // Magenta
    if (biome == "River") return "\033[34m";   // Blue
    if (biome == "Mountain") return "\033[90m"; // Grey
    return "\033[0m"; // Default/Reset
}

void generateRivers(std::vector<std::vector<Tile>> &tileMap) {
    int random_y = rand() % tileMap.size();
    tileMap[0][random_y].biome_type = "River";

    for (size_t i = 1; i < tileMap.size(); ++i) {
        int river_var = -1 + (rand() % 3);
        random_y += river_var;
        tileMap[0+i][random_y].biome_type = "River";
    }
}

void generateMountains(std::vector<std::vector<Tile>> &tileMap) {
    int random_y = rand() % tileMap.size();
    if (tileMap[0][random_y].biome_type != "River") {
        tileMap[0][random_y].biome_type = "Mountain";
    }
    
    for (size_t i = 1; i < tileMap.size(); ++i) {
        int mountain_var = -1 + (rand() % 3);
        random_y += mountain_var;
        tileMap[0+i][random_y].biome_type = "Mountain";
    }
}

std::vector<std::vector<Tile>> generateTileMap(int width, int height){
    srand(time(0));
    std::vector<std::vector<Tile>> tileMap;
    std::string resetColor = "\033[0m";

    for (int i = 0; i < width; i ++){
        std::vector<Tile> row;
        for (int j = 0; j < height; j++){
            PointOfInterest poi;
            generatePointOfInterest(poi);
            Tile tile(i, j, generateBiome(), poi);
            row.push_back(tile);
        } std::cout << std::endl;
        tileMap.push_back(row);
       
    }
    generateRivers(tileMap);
    generateMountains(tileMap);
    return tileMap;
}

void displayTileMap(const std::vector<std::vector<Tile>> &tileMap) {
    std::string resetColor = "\033[0m";
    for (const auto& row : tileMap) {
        for (const auto& tile : row) {
            std::cout << getBiomeColor(tile.biome_type) << "[" << tile.location_x << "," << tile.location_y << "]" << resetColor;
        }
        std::cout << std::endl;
    }
}