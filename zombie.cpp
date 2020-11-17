#include"zombie.h"
#include"map.h"
#define Forr(i, l, r) for(int i = l; i < r; i++)

void zombieNormal::Attack(int t){
    if ((t-setTime)%attackSpeed) return;
    //vector<node> f = Map.getList(x, y - 1);
    vector<node> g = Map.getList(x, y);
    //g.insert(g.end(), f.begin(), f.end());
    Forr(i, 0, g.size()){
        if (g[i].p->getId() / 10 == 1){
            g[i].p->subHeart(attack);
            break;
        }
    }  
}

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
