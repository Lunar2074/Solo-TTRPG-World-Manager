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

std::string getBiomeColor(std::string biome) {
    if (biome == "Grass") return "\033[32m";   // Green
    if (biome == "Forest") return "\033[32m";  // Green
    if (biome == "Desert") return "\033[33m";  // Yellow
    if (biome == "Snow") return "\033[37m";    // White
    if (biome == "Swamp") return "\033[35m";   // Magenta
    if (biome == "River") return "\033[34m";   // Blue
    return "\033[0m"; // Default/Reset
}

void generateRivers(std::vector<std::vector<Tile>> &tileMap) {
    tileMap[0][rand() % tileMap[0].size()].biome_type = "River";
    for (size_t i = 1; i < tileMap.size(); ++i) {
        int prevRiverX = -1;
        for (size_t j = 0; j < tileMap[i - 1].size(); ++j) {
            if (tileMap[i - 1][j].biome_type == "River") {
                prevRiverX = j;
                break;
            }
        }
        int riverX = prevRiverX + (rand() % 3 - 1); // Move left, stay, or move right
        if (riverX < 0) riverX = 0;
        if (riverX >= tileMap[i].size()) riverX = tileMap[i].size() - 1;
        tileMap[i][riverX].biome_type = "River";
    }
}

std::vector<std::vector<Tile>> generateTileMap(int width, int height){
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
        generateRivers(tileMap);
    }
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