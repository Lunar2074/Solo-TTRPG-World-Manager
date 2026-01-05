#include <iostream>
#include "tile.h"
#include <stdlib.h>

enum choices {
    generate_map = 1,
    check_point_of_interest = 2,
    exit_program = 3
};


int main() {
   bool exit = 0;
   std::vector<std::vector<Tile>> myMap;
   int width =0, height =0;


    do{
        std::cout << "Select an option: \n1. Generate Tile Map\n2. Check Point of Interest\n3. Exit Program\n";
        int userChoice;
        std::cin>> userChoice;

        switch (userChoice){
            case generate_map:
                int width, height;
                std:: cout << "Enter the width and height of the tile map: ";
                std::cin >> width >> height;
                myMap = generateTileMap(width, height);
                displayTileMap(myMap);
                break;
            case check_point_of_interest:
            std:: cout << "Enter the X and Y coordinates of the tile you want to check: ";
                std::cin>>width>>height;
                std::cout<< myMap[width][height].Point.name << std::endl;
                std::cout<< myMap[width][height].Point.monsters1 << std::endl;
                std::cout << myMap[width][height].biome_type << std::endl;
                break;
            case exit_program:
                exit = 1;
                break;
        }


    }while(exit == 0);

    

    return 0;
}

