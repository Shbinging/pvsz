#pragma once
#include "diag.h"
#include"object.h"
#include"bullet.h"

using namespace std;

class MAP;
class shop;
<<<<<<< Updated upstream
class plantNormal : public object {
protected:
    int money;
    MAP& Map;
    shop& Shop;

public:
    plantNormal(location a, int t, MAP& m, shop& s) :
=======
class plantNormal: public object{
    protected:
        int money;
        MAP& Map;
        shop& Shop;

    public:
        plantNormal(location a, int t,MAP& m,shop& s):
>>>>>>> Stashed changes
        object(a, t),
        Map(m),
        Shop(s)
    {
        type = 2;
    }
    int getMoney() { return money; }
    void beAttack();
};

class plantWandou :public plantNormal {
public:
    plantWandou(location a, int t, MAP* m, shop* n) :plantNormal(a, t, *m, *n) {
        money = 100;
        heart = 30;
        attack = 5;
        speed = 2;
        name = "Íã";
        id = 11;
    }
    bullet* getBullet(int t);
    bool isGetBullet(int t);
    void run(int t);
};

class plantSun :public plantNormal {
public:
    plantSun(location a, int t, MAP* m, shop* n) :plantNormal(a, t, *m, *n) {
        money = 25;
        heart = 50;
        attack = 50;//sun
        speed = 3;
        type = 1;
        name = "Ì«";
        id = 10;
    }
    int getSun(int t);
    bool isGetSun(int t);
    void run(int t);
};

class plantHanbing :public plantNormal {
public:
    plantHanbing(location a, int t, MAP* m, shop* n) :plantNormal(a, t, *m, *n) {
        money = 150;
        heart = 30;
        attack = 5;
        speed = 2;
        name = "º®";
        id = 12;
    }
    bullet* getBullet(int t);
    bool isGetBullet(int t);
    void run(int t);
};
class plantShuangfa :public plantNormal {
public:
    plantShuangfa(location a, int t, MAP* m, shop* n) :plantNormal(a, t, *m, *n) {
        money = 150;
        heart = 30;
        attack = 5;
        speed = 2;
        name = "Ë«";
        id = 13;
    }
    bullet* getBullet(int t);
    bool isGetBullet(int t);
    void run(int t);
};

<<<<<<< Updated upstream
class plantNut :public plantNormal {
public:
    plantNut(location a, int t, MAP* m, shop* n) :plantNormal(a, t, *m, *n) {
        money = 50;
        heart = 100;
        attack = 0;
        speed = 2;
        name = "¼á";
        id = 14;
    }
    void run(int t) {}
};

=======
class plantWandou:public plantNormal{
    public:
        plantWandou(location a, int t, MAP* m, shop* n):plantNormal(a, t, *m, *n){
            money = 100;
            heart = 30;
            attack = 5;
            speed = 2;
            name = "Íã";
            id = 11;
        }
        bullet* getBullet(int t);
        bool isGetBullet(int t);
        void run(int t);
};

class plantSun :public plantNormal {
public:
    plantSun(location a, int t, MAP* m, shop* n) :plantNormal(a, t, *m, *n) {
        money = 25;
        heart = 50;
        attack = 50;//sun
        speed = 3;
        type = 1;
        name = "Ì«";
        id = 10;
    }
    int getSun(int t);
    bool isGetSun(int t);
    void run(int t);
};

class plantHanbing :public plantNormal {
public:
    plantHanbing(location a, int t, MAP* m, shop* n) :plantNormal(a, t, *m, *n) {
        money = 150;
        heart = 30;
        attack = 5;
        speed = 2;
        name = "º®";
        id = 12;
    }
    bullet* getBullet(int t);
    bool isGetBullet(int t);
    void run(int t);
};
class plantShuangfa :public plantNormal {
public:
    plantShuangfa(location a, int t, MAP* m, shop* n) :plantNormal(a, t, *m, *n) {
        money = 150;
        heart = 30;
        attack = 5;
        speed = 2;
        name = "Ë«";
        id = 13;
    }
    bullet* getBullet(int t);
    bool isGetBullet(int t);
    void run(int t);
};

class plantNut :public plantNormal {
public:
    plantNut(location a, int t, MAP* m, shop* n) :plantNormal(a, t, *m, *n) {
        money = 50;
        heart = 100;
        attack = 0;
        speed = 2;
        name = "¼á";
        id = 14;
    }
    void run(int t){}
};

>>>>>>> Stashed changes
class plantNutHigh :public plantNormal {
public:
    plantNutHigh(location a, int t, MAP* m, shop* n) :plantNormal(a, t, *m, *n) {
        money = 100;
        heart = 200;
        attack = 0;
        speed = 2;
        name = "¸ß";
        id = 15;
    }
    void run(int t) {}
};
