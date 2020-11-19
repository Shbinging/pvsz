#include"bullet.h"
#include"map.h"
#define Forr(i, l, r) for(int i = l; i < r; i++)
void bullet::Attack(){
    vector<node> f = Map.getlList(x, y);
    Forr(i, 0, f.size()){
        if (f[i].p->getType() == 3){
            f[i].p->subHeart(attack);
            setDead();
            break;
        }
    }   
}

void bullet::run(int t){
    Attack();
    Move(t);
    if (!isDead()) Attack();
}

void bulletBing::Attack()
{
    vector<node> f = Map.getlList(x, y);
    Forr(i, 0, f.size()) {
        if (f[i].p->getType() == 3) {
            f[i].p->subHeart(attack);
            f[i].p->setSpeed(2 * f[i].p->getSpeed());
            setDead();
            break;
        }
    }
}

void bulletBall::Attack()
{
    if (y != x1) return;
    vector<node> f = Map.getList(x, y);
    Forr(i, 0, f.size()) {
        if (isPlant(f[i].p->getId())) {
            f[i].p->subHeart(attack);
            setDead();
            break;
        }
    }
}

void bulletBall::Move(int t)
{
    if (!((t - setTime) % speed) && t - setTime > 0) y -= 1;
    if (y < 1) setDead();
}
