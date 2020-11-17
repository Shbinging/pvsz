#pragma once

#include "diag.h"
#include "view.h"
#include"circle.h"
using namespace std;

class pzCreator;
class plantNormal;
class shopCircle;

class shop:public view{
    private:
        shopCircle shopPoint;
    public:
        shop(int t);
        int getSum(){return Sum;}
        void clear(int t){
            money = t;
        }
        int getScore() { return score; }
        int addScore(int t) { score += t; return 0; }
        int getMoney(){return money;}
        int addMoney(int t) { money += t; shopPoint.changeStatus(); return 0; }
        bool canBuy();
        void Buy();
        int getBuyId();
        void MoveCircle(string st);
        void setInit();
        void setDead();
        void display();
        bool checkEn();
    private:
        int money;
        vector<plantNormal*> list;
        int Sum;
        int score;
};
