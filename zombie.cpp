#include"zombie.h"
#include"map.h"
#define Forr(i, l, r) for(int i = l; i < r; i++)

void zombieNormal::Attack(int t){
    if ((t-setTime)%attackSpeed) return;
    //vector<node> f = Map.getList(x, y - 1);
    vector<node> g = Map.getList(x, y);
    //g.insert(g.end(), f.begin(), f.end());
    Forr(i, 0, g.size()) {
        if (g[i].p->getId() / 10 == 3) {
            g[i].p->subHeart(attack);
            return;
        }
    }
    Forr(i, 0, g.size()){
        if (g[i].p->getId() / 10 == 1){
            g[i].p->subHeart(attack);
            return;
        }
    }  
}
void zombieNormal::run(int t)
{
    Attack(t);
    Move(t);
}

void zombieNormal::Move(int t)
{
    vector<node> g = Map.getList(x, y);
    Forr(i, 0, g.size()) if (g[i].p->getId() / 10 == 1) return;
    if ((t - setTime) % speed == 0 && t - setTime > 0) {
        y -= 1; if (y < 0) setDead();
    }
}
/*
void zombieBasic::run(int t){
    Attack(t);
    Move(t);
}

void zombieBasic::Move(int t){
    //vector<node> f = Map.getList(x, y - 1);
    vector<node> g = Map.getList(x, y);
    //g.insert(g.end(), f.begin(), f.end());
    Forr(i, 0, g.size()) if (g[i].p->getId()/10 == 1) return;
    if ((t-setTime)%speed == 0 && t -setTime > 0) y -= 1; 
}

void zombieLu::run(int t)
{
    Attack(t);
    Move(t);
}

void zombieLu::Move(int t)
{
    //vector<node> f = Map.getList(x, y - 1);
    vector<node> g = Map.getList(x, y);
    //g.insert(g.end(), f.begin(), f.end());
    Forr(i, 0, g.size()) if (g[i].p->getId() / 10 == 1) return;
    if ((t - setTime) % speed == 0 && t - setTime > 0) y -= 1;
}
*/
void zombieBao::run(int t)
{
    if (heart < mxheart / 3 && f) { color = RED; speed /= 3; f = 0; }
    Attack(t);
    Move(t);
}
/*
void zombieBao::Move(int t)
{
    //vector<node> f = Map.getList(x, y - 1);
    vector<node> g = Map.getList(x, y);
    //g.insert(g.end(), f.begin(), f.end());
    Forr(i, 0, g.size()) if (g[i].p->getId() / 10 == 1) return;
    if ((t - setTime) % speed == 0 && t - setTime > 0) y -= 1;
}

void zombieGan::run(int t)
{
    Attack(t);
    Move(t);
}
*/
void zombieGan::Move(int t)
{
    vector<node> g = Map.getList(x, y);
    bool hasplant = 0, hasGao = 0;
    Forr(i, 0, g.size()) if (g[i].p->getId() / 10 == 1) { hasplant = 1; if (g[i].p->getId() == 15) hasGao = 1; }
    if ((t - setTime) % speed == 0 && t - setTime > 0) {
        if (hasplant && f && !hasGao) {
            y -= 1;
            f = 0;
            color = RED;
        }
        else if (!hasplant) { y -= 1; color = BROWN; }
    }
}

void zombieXiao::run(int t)
{
    if (l - y == s1) {
        bomb();
    }
    else if (l - y == s1 - 1) {
        color = RED;
    }
    Attack(t);
    Move(t);
}

void zombieXiao::bomb()
{
    For(i, max(1, x - 1), min(h, x + 1))
        For(j, max(1, y - 1), min(l, y + 1)) {
        vector<node> f = Map.getlList(i, j);
        Forr(l, 0, f.size()) {
            if (isPlant(f[l].p->getId())) {
                f[l].p->setDead();
            }
        }
    }
    setDead();
}

void zombieTou::Attack(int t) {
    vector<node> f = Map.getList(x, y);
    Forr(l, 0, f.size()) {
        if (isPlant(f[l].p->getId())) {
            f[l].p->setDead();
        }
    }
}

void zombieTou::run(int t)
{
    bulletBall *p = new bulletBall(location(x, y), t, attack, Map);
    int x1 = p->getX();
    if (x1 == -1 || s >= ballS) {
        name = "³µ";
        Move(t);
        Attack(t);   
    }
    else{
        name = "Í¶";
        color = RED;
        if ((t - setTime) % attackSpeed == 0 && t - setTime > 0) {
            s++;
            bullet* p = new bulletBall(location(x, y), t, attack, Map);
            Map.push(x, y, p);
        }
    }
}
