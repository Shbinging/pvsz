#pragma once
#include"object.h"


class shop;
class MAP;
class circle :public object {
protected:
    bool en;
    int h, l;
    int ih, il;//init
    bool canGo(int x, int y) {
        if (x <= ih + h - 1 && y <= il + l - 1 && x >= ih && y >= il) return 1;
        else return 0;
    }
public:
    circle(int hh, int ll) :object() {
        h = hh;
        l = ll;
        en = 0;
        setDead();
    }


    bool checkEn() {
        return en;
    }
};

class mapCircle :public circle {
protected:
    MAP& Map;
    void changeStatus();
public:
    void setInit() {
        setLive();
        x = ih;
        y = il - 1;
        Move("right");
    }
    mapCircle(int hh, int ll, int iih, int iil, MAP& Mapp) :circle(hh, ll), Map(Mapp) {
        ih = iih;
        il = iil;
    }
    void Move(string st);

};

class shopCircle :public circle {
protected:

    shop& Shop;
public:
    void changeStatus();
    void setInit() {
        setLive();
        x = ih;
        y = il - 1;
        Move("right");
    }
    int getId() { return y; }
    shopCircle(int hh, int ll, int iih, int iil, shop* Shopp) :circle(hh, ll), Shop(*Shopp) {
        ih = iih;
        il = iil;
    }
    void setHL(int hh, int ll) {
        h = hh;
        l = ll;
    }
    void Move(string st);
};




