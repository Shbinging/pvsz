#pragma once
#include"object.h"
#include"map.h"
#include"rand.h"
#include"diag.h"
#include"config.h"
class MAP;
class bullet:public object{
    protected:
        MAP& Map;
    public:
    bullet(location a, int tt, int att, MAP& m):object(a, tt), Map(m){
        attack = 2;
        name = "*";
        speed = 1;
        type = 4;
        id = 0;
    } 
    virtual void Attack();
    virtual void run(int t);
    virtual void Move(int t){
        if (!((t -setTime) % speed) && t-setTime >0) y += 1;
        if (y > l) setDead();
        //printf("ok::%d\n", y);
    }
};
class bulletBing :public bullet {
public:
    bulletBing(location a, int tt, int att, MAP& m) :bullet(a, tt, att, m){
        name = "*";
        id = 1;
        attack = 5;
    }
    void Attack();
};

class bulletBall :public bullet {
private:
    int x1;
public:
    bulletBall(location a, int tt, int att, MAP& m) :bullet(a, tt, att, m) {
        name = "@";
        id = 2;
        attack = 2;
        vector<object*> f = Map.getListAll();
        vector<int> g;
        Forr(i, 0, f.size())
            if (isPlant(f[i]->getId()) && a.x == f[i]->getLocation().x) {
                    g.push_back(f[i]->getLocation().y);
            }
        if (g.size()) {
            x1 = g[randint(0, int(g.size() - 1))];
        }
        else x1 = -1;
    }
    void Attack();
    void Move(int t);
    int getX() { return x1; }
};
