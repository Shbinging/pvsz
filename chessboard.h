#pragma once
#include"diag.h"
#include"config.h"
#include"view.h"
#include"map.h"
#include"circle.h"
class MAP;
class mapCircle;
class object;
class shop;
class chessboard:public view {
private:
    int t;
    int id;
    int h, l;
    MAP Map;
    shop& Shop;
    mapCircle mapPoint;
    void makeZombie(int t);
    void makeSun(int t);
public:
    void reset();
    bool isLose();
    chessboard(int hh, int ll, shop& s);
    void Play(int t);
    void display();
    void makePlant(int id, int t);
    void MoveCircle(string st, int id = 0);
    bool checkEn();
    void setInit(int id);
    void setDead();
};