#include "diag.h"
#include"plant.h"
#include"map.h"
#include"shop.h"
#include"config.h"
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
    bullet * p = new bullet(location(x, y), t, attack, Map);
    return p;
}

bool plantWandou::isGetBullet(int t){
    if ((t - setTime) % speed == 0)
        return 1;
    else return 0;
}

void plantWandou::run(int t){
    if (!isDead() && isGetBullet(t)){ 
        Map.push(x, y, getBullet(t));
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

bullet* plantHanbing::getBullet(int t)
{
    bullet* p = new bulletBing(location(x, y), t, attack, Map);
    return p;
}

bool plantHanbing::isGetBullet(int t)
{
    if ((t - setTime) % speed == 0)
        return 1;
    else return 0;
}

void plantHanbing::run(int t)
{
    if (!isDead() && isGetBullet(t)) {
        Map.push(x, y, getBullet(t));
    }
}

bullet* plantShuangfa::getBullet(int t)
{
    bullet* p = new bullet(location(x, y), t, attack, Map);
    return p;
}

bool plantShuangfa::isGetBullet(int t)
{
    if ((t - setTime) % speed == 0)
        return 1;
    else return 0;
}

void plantShuangfa::run(int t)
{
    if (!isDead() && isGetBullet(t)) {
        Map.push(x, y, getBullet(t));
        Map.push(x, y, getBullet(t));
    }
}

void plantWogua::run(int t)
{
    vector<node> f = Map.getlList(x, y);
    Forr(i, 0, f.size()) {
        if (f[i].p->getId() /10 == 2) {
            f[i].p->setDead();
            setDead();
        }
    }
}

void plantCherrish::run(int t)
{
        For(i, max(1, x - 1), min(h, x + 1))
            For(j, max(1, y - 1), min(l, y + 1)) {
            vector<node> f = Map.getlList(i, j);
            Forr(l, 0, f.size()) {
                if (f[l].p->getId() / 10 == 2) {
                    f[l].p->setDead();
                }
            }
        }
        setDead();
}
