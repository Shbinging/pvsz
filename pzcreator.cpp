#include "pzcreator.h"
#define makeo(id, obj) case id: p=new obj(x, t); break;


object *pzCreator::createObject(int id, location x, int t)
{
    object* p = NULL;
    switch(id){
        //case 10: p = new plantSun(x, t, &m, &n); break;
        makeo(11, plantWandou)
        makeo(20, zombieBasic)
    }
    return p;
}
