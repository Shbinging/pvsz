#pragma once
#include"object.h"

class MAP;
class plantNormal;
class shop;
class pzCreator{
    public:
        object* createObject(int id, MAP& m, shop& n, location x = location(0, 0), int t = -1);
        vector<plantNormal*> getPlantList();
};
