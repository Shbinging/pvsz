#include "diag.h"
#include"plant.h"
#include"map.h"
#include"shop.h"
#define Forr(i, l, r) for(int i = l; i < r; i++)
using namespace std;

void plantNormal::beAttack(){
    vector<node> f = Map.getList(x, y + 1);
    Forr(i, 0, f.size()){
        if (f[i].p->isDead()) continue;
        if (f[i].p->getType() == 3){
            subHeart(f[i].p->getAttack());
        }
    }   
}

bullet* plantWandou::getBullet(int t){
    bullet * p = new bullet(location(x, y + 1), t, attack, Map);
    return p;
}

bool plantWandou::isGetBullet(int t){
    if ((t - setTime) % speed == 0)
        return 1;
    else return 0;
}

void plantWandou::run(int t){
    if (!isDead() && isGetBullet(t)){ 
        Map.push(x, y + 1, getBullet(t));
    }
}

bool plantSun::isGetSun(int t){
    return !((t-setTime) % speed);
}

int plantSun::getSun(int t){
    return attack;
}

void plantSun::run(int t){
    if (isGetSun(t)) Shop.addMoney(getSun(t));
}