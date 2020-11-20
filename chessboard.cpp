#include "diag.h"
#include"chessboard.h"
#include"map.h"
#include"config.h"
#include"shop.h"
#include"config.h"
#include"plant.h"
#include"rand.h"
#include"pzCreator.h"
#include"circle.h"


using namespace std;



chessboard::chessboard(int hh, int ll, shop& s) :
    Map(hh, ll),
    mapPoint(hh, ll, 1, 1, Map),
    Shop(s)
{
    h = hh;
    l = ll;
    t = 0;
    reset();
}
void chessboard::reset(){
    Map.clear();
    t = 0;
}

bool chessboard::isLose(){
    vector<object*> list= Map.getListAll();
    Forr(i, 0, list.size()){
        if (list[i]->getId()/10 == 2 && list[i]->getLocation().y <=0 )
         return 1;
    }
    return 0;
}

void chessboard::display(){
    printLine('-');
    For(i, 1, h){
        Screen.print("|");
        For(j, 1, l){
            vector<node> list = Map.getList(i, j);
            string st;
            if (!mapPoint.isDead() && mapPoint.getLocation().x == i && mapPoint.getLocation().y == j){
                Screen.print(mapPoint.getName());
                Screen.print("\t");
            }
            else 
                if (!list.size()) Screen.print("\t");
            else {
                    int s1 = 0;
                    Forr(k, 0, list.size()) {
                        if (s1 > 5) break;
                        if (list[k].p->getId() / 10 == 1) {
                            Screen.print(list[k].p->getName());
                            s1++;
                        }
                    }
                    Forr(k, 0, list.size()) {
                        if (s1 > 5) break;
                        if (list[k].p->getId() / 10 == 2) {
                            Screen.print(list[k].p->getName(), RED);
                            s1++;
                        }
                    }
                    Forr(k, 0, list.size()) {
                        if (s1 > 5) break;
                        if (list[k].p->getId() / 10 == 0) {
                            Screen.print(list[k].p->getName());
                            s1++;
                        }
                    }
                    Forr(k, 0, list.size()) {
                        if (s1 > 5) break;
                        if (list[k].p->getId() / 10 == 3) {
                            Screen.print(list[k].p->getName());
                            s1++;
                        }
                    }
                    Screen.print("\t"); 
            }
            Screen.print("|");
        } 
        Screen.print("\n");
        printLine('-');
    }
    printLine();
}


void chessboard::makePlant(int id, int t) {
    pzCreator tmp;
    Map.push(tmp.createObject(id, Map, Shop, mapPoint.getLocation(), t));
}

bool chessboard::checkEn(){
    location loc = mapPoint.getLocation();
    bool canPlant = 1;
    if (id / 10 == 1) {
        vector<node> f = Map.getList(loc.x, loc.y);
        Forr(i, 0, f.size()) {
            if (f[i].p->getId() / 10 == 1) canPlant = 0;
        }

    }
    else if (id / 10 == 3) {
        vector<node> f = Map.getList(loc.x, loc.y);
        Forr(i, 0, f.size()) {
            if (f[i].p->getId() == id) canPlant = 0;
        }
    }
    return canPlant;
}

void chessboard::Play(int t){
    static int setTime = -1;
    if (t != setTime){
        setTime = t;
    }
    else return;
    makeSun(t);
    makeZombie(t);
    vector<object*> list;
    list = Map.getListAll();
    Forr(k, 0, list.size()) if (!list[k]->isDead() && list[k]->getId() / 10 == 2) list[k]->run(t);
    list = Map.getListAll();
    Forr(k, 0, list.size()) if (!list[k]->isDead() && list[k]->getId() / 10 == 1) list[k]->run(t);
    list = Map.getListAll();
    Forr(k, 0, list.size()) if (!list[k]->isDead() && list[k]->getId() / 10 == 3) list[k]->run(t);
    list = Map.getListAll();
    Forr(k, 0, list.size()) if (!list[k]->isDead() && list[k]->getId() / 10 == 0)
        list[k]->run(t);
}

void chessboard::makeZombie(int t)
{
    static bool New = 1;
    static int setTime = 0;
    static int interval = 0;
    static int s1 = 0;
    if ((t - setTime == interval) || (New && (t > 5))) {
        //if (s1) return;
        New = 0;
        pzCreator b;
        int id = randint(20, mxZomId);//noraml zombie
        //int id = mxZomId;
        int x = randint(1, h);
        Map.push(b.createObject(id, Map, Shop, location(x,l), t));
        setTime = t;
        interval = randint(6, 10);
        s1++;
    }
}

void chessboard::makeSun(int t)
{
    static bool New = 1;
    static int setTime = 0;
    static int interval = 0;
    if ((t - setTime == interval) || (New && (t > 5))) {
        New = 0;
        Shop.addMoney(50);
        setTime = t;
        interval = randint(10, 20);
    }
}

void chessboard::MoveCircle(string st, int id){
    this->id = id;
    static pzCreator b;
    static vector<plantNormal*> a = b.getPlantList();
    mapPoint.Move(st);
    mapPoint.changeStatus(checkEn());
}

void chessboard::setInit(int id){
    this->id = id;
    mapPoint.setInit();
    mapPoint.changeStatus(checkEn());
}
void chessboard::setDead(){
    mapPoint.setDead();
}