#ifndef zombie_
#define zombie_
#include"object.h"
#include"shop.h"
#include"rand.h"
#include"config.h"
#include"bullet.h"
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
        virtual void Attack(int t);
        virtual void Move(int t);
        virtual void run(int t);
};
class zombieBasic: public zombieNormal{
    public:
        zombieBasic(location a, int t, MAP* m, shop* n):zombieNormal(a, t, *m, *n){
            attack = 5;
            mxheart = heart = 10;
            speed = 40;
            attackSpeed = 20;
            id = 20;
            score = 5;
            name = "僵";
        }
    void setDead() {
        live = 0;
        Shop.addScore(score);
    }
    //void run(int t);
    //void Move(int t);
};
class zombieLu : public zombieNormal {
public:
    zombieLu(location a, int t, MAP* m, shop* n) :zombieNormal(a, t, *m, *n) {
        attack = 5;
        mxheart = heart = 30;
        speed = 20;
        attackSpeed = 3;
        id = 21;
        score = 5;
        name = "路";
    }
    void setDead() {
        live = 0;
        Shop.addScore(score);
    }
    //void run(int t);
    //void Move(int t);
};
class zombieBao : public zombieNormal {
private:
    bool f;
public:
    zombieBao(location a, int t, MAP* m, shop* n) :zombieNormal(a, t, *m, *n) {
        attack = 5;
        mxheart = heart = 30;
        speed = 20;
        attackSpeed = 3;
        id = 22;
        f = 1;
        score = 5;
        name = "报";
    }
    void setDead() {
        live = 0;
        Shop.addScore(score);
    }
    void run(int t);
    //void Move(int t);
};

class zombieGan : public zombieNormal {
private:
    bool f;
public:
    zombieGan(location a, int t, MAP* m, shop* n) :zombieNormal(a, t, *m, *n) {
        attack = 5;
        mxheart = heart = 30;
        speed = 20;
        attackSpeed = 3;
        id = 23;
        f = 1;
        score = 5;
        name = "撑";
    }
    void setDead() {
        live = 0;
        Shop.addScore(score);
    }
    //void run(int t);
    void Move(int t);
};
class zombieXiao : public zombieNormal {
private:
    int s1;
public:
    zombieXiao(location a, int t, MAP* m, shop* n) :zombieNormal(a, t, *m, *n) {
        attack = 5;
        mxheart = heart = 30;
        speed = 20;
        attackSpeed = 3;
        id = 24;
        score = 5;
        name = "小";
        s1 = randint(1, l * 2);
    }
    void setDead() {
        live = 0;
        Shop.addScore(score);
    }
    void run(int t);
    void bomb();
    //void Move(int t);
};
class zombieTou : public zombieNormal {
private:
    int s1, s, stage, ballS;
public:
    zombieTou(location a, int t, MAP* m, shop* n) :zombieNormal(a, t, *m, *n) {
        s = 0;
        stage = 0;
        attack = 30;
        mxheart = heart = 30;
        speed = 40;
        attackSpeed = 10;
        id = 25;
        score = 5;
        name = "投";
        ballS = 5;
        s1 = randint(1, l * 2);
    }
    void setDead() {
        live = 0;
        Shop.addScore(score);
    }
    void Attack(int t);
    void run(int t);
};
#endif