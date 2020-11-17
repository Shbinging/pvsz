#ifndef BULLET
#define BULLET
#include"object.h"
#include"map.h"

class MAP;
class bullet:public object{
    private:
        MAP& Map;
    public:
    bullet(location a, int tt, int att, MAP& m):object(a, tt), Map(m){
        attack = att;
        name = "@";
        speed = 1;
        type = 4;
    } 
    void Attack();
    void run(int t);
    void Move(int t){
        if (!((t -setTime) % speed) && t-setTime >0) y += 1;
        //printf("ok::%d\n", y);
    }
};

#endif