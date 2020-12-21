#include "pzcreator.h"
#include"QGraphicsItem"
#define makeo(id, obj) case id: p=new obj(x, t); break;


object *pzCreator::createObject(int id, location x, int t)
{
    object* p = NULL;
    switch(id){
        //case 10: p = new plantSun(x, t, &m, &n); break;
        makeo(10, plantSun)
        makeo(11, plantWandou)
        makeo(12, plantHanbing)
        makeo(13, plantShuangfa)
        makeo(14, plantNut)
        makeo(16, plantWogua)
        makeo(20, zombieBasic)
        makeo(31, sun)
    }
    return p;
}

location getPlantLocation(int x, int y){
    return location((x - 249) / 82 * 82 + 290, (y - 81) / 98 * 98 + 130);
}
