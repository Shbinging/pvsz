#include"shop.h"
#include"config.h"
#include"pzCreator.h"
#include"plant.h"
#include"circle.h"
#include"diag.h"

void shop::display(){
    Screen.print("[Shop]\t\t\t\t\tSunSum:" + to_string(getMoney()) + ", Score:" + to_string(getScore()) + "\n");
    printLine('-');
    Screen.print("|");
    For(i, 1, Sum)
        Screen.print(list[i]->getName() + "\t" + "|");

    Screen.print("\n");
    Screen.print("|");
    For(i, 1, Sum) {
        Screen.print(to_string(list[i]->getMoney()) + "\t", YELLOW);
        Screen.print("|");
    }
    Screen.print("\n");
    printLine('-');

    Screen.print("|");
    For(i, 1, getSum()) {
        Screen.print(to_string(coldTime[i]) + "\t", RED);
        Screen.print("|");
    }
    Screen.print("\n");
    printLine('-');
    Screen.print("|");
    For(i, 1, getSum()){
        if (!shopPoint.isDead() && i == shopPoint.getLocation().y) { 
            Screen.print(shopPoint.getName(), shopPoint.getColor());
            Screen.print("\t|");
        }
        else {
            Screen.print("\t");
            Screen.print("|");
        }
    }
    Screen.print("\n");
    printLine();
}

bool shop::canBuy(){
    int t = shopPoint.getLocation().y;
    if (t > Sum || t < 1) return 0;
        if (list[t]->getMoney() > money || coldTime[t] > 0) return 0;
        else return 1;
}

void shop::Buy(){
    int t = shopPoint.getLocation().y;
    money -= list[t]->getMoney();
    coldTime[t] = list[t]->getColdTime();
}

shop::shop(int t):shopPoint(1,2,1,1, this){//!!!
    score = 0;
    money = t;
    pzCreator tmp;
    list = tmp.getPlantList();
    Sum = list.size() - 1;
    shopPoint.setHL(1, Sum);
    For(i, 1, Sum) coldTime[i] = 0;
}

void shop::setDead(){
    shopPoint.setDead();
}

void shop::setInit(){
    shopPoint.setInit();
}

void shop::MoveCircle(string st){
    shopPoint.Move(st);
}

bool shop::checkEn(){
    return canBuy();
}

void shop::update(int t)
{
    if (t == 0 || t % 5) return;
    For(i, 1, Sum) coldTime[i] = max(0, coldTime[i] - 1);
}

int shop::getBuyId(){
    static pzCreator b;
    static vector<plantNormal*> a = b.getPlantList();
    return a[shopPoint.getLocation().y]->getId();
}