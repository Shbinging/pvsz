#include"shop.h"
#include"config.h"
#include"pzCreator.h"
#include"plant.h"
#include"circle.h"
#include"diag.h"

void shop::display(){
    printf("[Shop]\t\t\t\t\tSunSum:%d, Score:%d\n", getMoney(), getScore());
    printLine('-');
    printf("|");
    For(i, 1, Sum)
        cout << list[i]->getName() << "\t"<<"|";
    printf("\n");
    printf("|");
    For(i, 1, Sum)
        cout << list[i]->getMoney() <<"\t" <<"|";
    printf("\n");
    printLine('-');
    printf("|");
    For(i, 1, getSum()){
        if (!shopPoint.isDead() && i == shopPoint.getLocation().y) cout <<shopPoint.getName()<<"\t" <<"|";
        else cout <<"\t"<<"|";
    }
    cout <<endl;
    printLine();
}

bool shop::canBuy(){
    int t = shopPoint.getLocation().y;
    if (t > Sum || t < 1) return 0;
        if (list[t]->getMoney() > money) return 0;
        else return 1;
}

void shop::Buy(){
    int t = shopPoint.getLocation().y;
    money -= list[t]->getMoney();
}

shop::shop(int t):shopPoint(1,2,1,1, this){//!!!
    score = 0;
    money = t;
    pzCreator tmp;
    list = tmp.getPlantList();
    Sum = list.size() - 1;
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
int shop::getBuyId(){
    return 9+shopPoint.getLocation().y;
}