#pragma once
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
        bool two;
        int coldTime;
    public:
        plantNormal(location a, int t,MAP& m,shop& s):
        object(a, t),
        Map(m),
        Shop(s)
        {
            type = 2;
            two = 0;
            color = GREEN;
        }
        int getMoney(){return money;}
        void beAttack();
        bool canDouble() { return two; }
        int getColdTime() { return coldTime; }
        void setColor();
};

class plantWandou:public plantNormal{
    public:
        plantWandou(location a, int t, MAP* m, shop* n):plantNormal(a, t, *m, *n){
            money = 100;
            mxheart = heart = 30;
            attack = 5;
            speed = 2;
            name = "Íã";
            id = 11;
            coldTime = 10;
        }
        bullet* getBullet(int t);
        bool isGetBullet(int t);
        void run(int t);
};

class plantSun :public plantNormal {
public:
    plantSun(location a, int t, MAP* m, shop* n) :plantNormal(a, t, *m, *n) {
        money = 25;
        mxheart = heart = 50;
        attack = 50;//sun
        speed = 3;
        type = 1;
        name = "Ì«";
        id = 10;
        coldTime = 10;
    }
    int getSun(int t);
    bool isGetSun(int t);
    void run(int t);
};

class plantHanbing :public plantNormal {
public:
    plantHanbing(location a, int t, MAP* m, shop* n) :plantNormal(a, t, *m, *n) {
        money = 150;
        mxheart = heart = 30;
        attack = 5;
        speed = 2;
        name = "º®";
        id = 12;
        coldTime = 10;
    }
    bullet* getBullet(int t);
    bool isGetBullet(int t);
    void run(int t);
};
class plantShuangfa :public plantNormal {
public:
    plantShuangfa(location a, int t, MAP* m, shop* n) :plantNormal(a, t, *m, *n) {
        money = 150;
        mxheart = heart = 30;
        attack = 5;
        speed = 2;
        name = "Ë«";
        id = 13;
        coldTime = 10;
    }
    bullet* getBullet(int t);
    bool isGetBullet(int t);
    void run(int t);
};

class plantNut :public plantNormal {
public:
    plantNut(location a, int t, MAP* m, shop* n) :plantNormal(a, t, *m, *n) {
        money = 50;
        mxheart = heart = 100;
        attack = 0;
        speed = 2;
        name = "¼á";
        id = 14;
        coldTime = 10;
    }
    void run(int t){}
};

class plantNutHigh :public plantNormal {
public:
    plantNutHigh(location a, int t, MAP* m, shop* n) :plantNormal(a, t, *m, *n) {
        money = 100;
        mxheart = heart = 200;
        attack = 0;
        speed = 2;
        name = "¸ß";
        id = 15;
        coldTime = 10;
    }
    void run(int t) {}
};
class plantWogua :public plantNormal {
public:
    plantWogua(location a, int t, MAP* m, shop* n) :plantNormal(a, t, *m, *n) {
        money = 150;
        mxheart = heart = 30;
        attack = 5;
        speed = 2;
        name = "ÙÁ";
        id = 16;
        coldTime = 10;
    }
    void run(int t);
};

class plantCherrish :public plantNormal {
public:
    plantCherrish(location a, int t, MAP* m, shop* n) :plantNormal(a, t, *m, *n) {
        money = 150;
        mxheart = heart = 30;
        attack = 5;
        speed = 2;
        name = "Ó£";
        id = 17;
        coldTime = 10;
        color = RED;
    }
    void run(int t);
};

class plantSuan :public plantNormal {
public:
    plantSuan(location a, int t, MAP* m, shop* n) :plantNormal(a, t, *m, *n) {
        money = 200;
        mxheart = heart = 30;
        attack = 5;
        speed = 2;
        name = "Ëâ";
        id = 18;
        coldTime = 10;
    }
    void run(int t);
};

class plantNan :public plantNormal {
public:
    plantNan(location a, int t, MAP* m, shop* n) :plantNormal(a, t, *m, *n) {
        money = 200;
        mxheart = heart = 200;
        attack = 5;
        speed = 2;
        name = "ÄÏ";
        id = 30;
        two = 1;
        coldTime = 10;
    }
    void run();
};
