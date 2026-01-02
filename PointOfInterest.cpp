#include "PointsOfInterest.h"
#include <cstdlib>

std::string generateName(){
    std::vector<std::string> names = {"Tower of Despair", "Ruins of Mordor", "Catacombs of Bellimoris", "The Old Rotting Bridge"};
    int randomNum = rand()% names.size();
    std::string name = names[randomNum];

    return name;
}

std::string generateMonsters(){
    std::vector<std::string> monsters = {"Goblins", "Orcs", "Skeletons", "Zombies", "Trolls"};
    int randomNum = rand()% monsters.size();
    std::string monster = monsters[randomNum];

    return monster;
}

void generatePointOfInterest(PointOfInterest &poi){
    poi.name = generateName();
    poi.monsters1 = generateMonsters();
    poi.monsters2 = generateMonsters();
}

