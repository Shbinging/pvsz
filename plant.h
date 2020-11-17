#ifndef PLANT
#define PLANT
#include "diag.h"
#include"object.h"
#include"bullet.h"

using namespace std;

class MAP;
class shop;
class plantNormal: public object{
    protected:
        int money;
        MAP& Map;
        shop& Shop;
    public:
        plantNormal(location a, int t,MAP& m,shop& s):
        object(a, t),
        Map(m),
        Shop(s)
        {
            type = 2;
        }
        int getMoney(){return money;}
        void beAttack();
};

class plantWandou:public plantNormal{
    public:
        plantWandou(location a, int t, MAP* m, shop* n):plantNormal(a, t, *m, *n){
            money = 100;
            heart = 30;
            attack = 5;
            speed = 2;
            name = "Wandou";
        }
        bullet* getBullet(int t);
        bool isGetBullet(int t);
        void run(int t);
};

class plantSun:public plantNormal{
    public: 
        plantSun(location a, int t, MAP* m, shop* n):plantNormal(a, t, *m, *n){
            money = 25;
            heart = 50;
            attack = 50;//sun
            speed = 3;
            type = 1;
            name = "SunF";
        }
        int getSun(int t);
        bool isGetSun(int t);
        void run(int t);
};
#endif