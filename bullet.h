#ifndef BULLET
#define BULLET
#include"object.h"
#include"map.h"

class MAP;
<<<<<<< Updated upstream
class bullet :public object {
protected:
    MAP& Map;
public:
    bullet(location a, int tt, int att, MAP& m) :object(a, tt), Map(m) {
=======
class bullet:public object{
    protected:
        MAP& Map;
    public:
    bullet(location a, int tt, int att, MAP& m):object(a, tt), Map(m){
>>>>>>> Stashed changes
        attack = 2;
        name = "@";
        speed = 1;
        type = 4;
        id = 0;
<<<<<<< Updated upstream
    }
=======
    } 
>>>>>>> Stashed changes
    virtual void Attack();
    void run(int t);
    void Move(int t) {
        if (!((t - setTime) % speed) && t - setTime > 0) y += 1;
        //printf("ok::%d\n", y);
    }
};
class bulletBing :public bullet {
public:
<<<<<<< Updated upstream
    bulletBing(location a, int tt, int att, MAP& m) :bullet(a, tt, att, m) {
=======
    bulletBing(location a, int tt, int att, MAP& m) :bullet(a, tt, att, m){
>>>>>>> Stashed changes
        name = "$";
        id = 1;
    }
    void Attack();
};

#endif