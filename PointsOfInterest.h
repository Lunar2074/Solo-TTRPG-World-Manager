#ifndef POINTSOFINTEREST.H
#include <string>
#include <iostream>

class PointOfInterest {
    public: 
        std::string name;
        std::string monsters1;
        std::string monsters2;
        int pointType;

        PointOfInterest(){
            name = "None";
            monsters1 = "None";
            monsters2 = "None";
            pointType = 0;
        }

        PointOfInterest(std::string q, std::string w, std::string t, int e){
            name = q;
            monsters1 = w;
            monsters2 = t;
            pointType = e;
        }
};


#endif // POINTSOFINTEREST.H