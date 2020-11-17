#ifndef BULLET
#define BULLET
#include"object.h"
#include"map.h"

class MAP;
class bullet:public object{
    protected:
        MAP& Map;
    public:
    bullet(location a, int tt, int att, MAP& m):object(a, tt), Map(m){
        attack = 2;
        name = "@";
        speed = 1;
        type = 4;
        id = 0;
    } 
    virtual void Attack();
    void run(int t);
    void Move(int t){
        if (!((t -setTime) % speed) && t-setTime >0) y += 1;
        //printf("ok::%d\n", y);
    }
};
class bulletBing :public bullet {
public:
    bulletBing(location a, int tt, int att, MAP& m) :bullet(a, tt, att, m){
        name = "$";
        id = 1;
    }
    void Attack();
};

#endif