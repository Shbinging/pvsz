#ifndef PZCREATOR_H
#define PZCREATOR_H
#include"object.h"
#include"plant.h"
#include"zombie.h"
class pzCreator{
    public:
        object* createObject(int id, location x = location(0, 0), int t = -1);
};
#endif // PZCREATOR_H
