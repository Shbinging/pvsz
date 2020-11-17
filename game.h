#pragma once

#include"config.h"
#include"view.h"
#include"chessboard.h"
#include"shop.h"

class chessboard;
class shop;

class game:public view
{
private:
    int t;
    chessboard chess;
    shop Shop;
    int status;
public:
    game();
    void play();
    bool makePlant();
    void display();
    string getStatus();
};

