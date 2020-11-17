#include"shop.h"
#include"config.h"
#include"pzCreator.h"
#include"plant.h"
#include"circle.h"
#include"diag.h"

void shop::display() {
    Screen.print("[Shop]\t\t\t\t\tSunSum:" + to_string(getMoney()) + ", Score:" + to_string(getScore()) + "\n");
    printLine('-');
    Screen.print("|");
    For(i, 1, Sum)
        Screen.print(list[i]->getName() + "\t" + "|");

    Screen.print("\n");
    Screen.print("|");
    For(i, 1, Sum)
        Screen.print(to_string(list[i]->getMoney()) + "\t" + "|");
    Screen.print("\n");
    printLine('-');
    Screen.print("|");
    For(i, 1, getSum()) {
        if (!shopPoint.isDead() && i == shopPoint.getLocation().y) Screen.print(shopPoint.getName() + "\t" + "|");
        else {
            Screen.print("\t");
            Screen.print("|");
        }
    }
    Screen.print("\n");
    printLine();
}

bool shop::canBuy() {
    int t = shopPoint.getLocation().y;
    if (t > Sum || t < 1) return 0;
    if (list[t]->getMoney() > money) return 0;
    else return 1;
}

void shop::Buy() {
    int t = shopPoint.getLocation().y;
    money -= list[t]->getMoney();
}

shop::shop(int t) :shopPoint(1, 2, 1, 1, this) {//!!!
    score = 0;
    money = t;
    pzCreator tmp;
    list = tmp.getPlantList();
    Sum = list.size() - 1;
    shopPoint.setHL(1, Sum);
}

void shop::setDead() {
    shopPoint.setDead();
}

void shop::setInit() {
    shopPoint.setInit();
}

void shop::MoveCircle(string st) {
    shopPoint.Move(st);
}

bool shop::checkEn() {
    return canBuy();
}

int shop::getBuyId() {
    return 9 + shopPoint.getLocation().y;
}