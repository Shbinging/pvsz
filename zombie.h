#ifndef zombie_
#define zombie_
#include"object.h"
#include"shop.h"
class MAP;
class zombieNormal: public object{
    protected:
        int score;
        int attackSpeed;
        MAP& Map;
        shop& Shop;
    public:
        zombieNormal(location a, int t, MAP& m, shop& n):
        object(a, t),
        Shop(n),
        Map(m)
        {
            type = 3;
        }
        void Attack(int t);
        virtual void Move(){}
};
class zombieBasic: public zombieNormal{
    public:
        zombieBasic(location a, int t, MAP* m, shop* n):zombieNormal(a, t, *m, *n){
            attack = 5;
            heart = 1;
            speed = 5;
            attackSpeed = 3;
            id = 21;
            score = 5;
            name = "zombie";
        }
    void setDead() {
        live = 0;
        Shop.addScore(score);
    }
    void run(int t);
    void Move(int t);
};
#endif