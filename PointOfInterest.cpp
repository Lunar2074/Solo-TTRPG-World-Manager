#include "PointsOfInterest.h"
#include <cstdlib>



std::string generateMonsters(){
    std::vector<std::string> monsters = {"Goblins", "Orcs", "Skeletons", "Zombies", "Trolls"};
    int randomNum = rand()% monsters.size();
    std::string monster = monsters[randomNum];

    return monster;
}



std::vector<std::string> readPointsOfInterestFromFile(const std::string& filename){
    std::fstream pointOfInterestNames(filename);
    std::vector<std::string> names;

    if(pointOfInterestNames.is_open()){
        std::string name;

        while (std::getline(pointOfInterestNames, name, ',')){
            names.push_back(name);
        }
    }
    return names;
}

std::string generateName(){
    std::vector<std::string> names = readPointsOfInterestFromFile("pointOfInterestNames.csv");
    int randomNum = rand()% names.size();
    std::string name = names[randomNum];

    return name;
}

void generatePointOfInterest(PointOfInterest &poi){
    poi.name = generateName();
    poi.monsters1 = generateMonsters();
    poi.monsters2 = generateMonsters();
}