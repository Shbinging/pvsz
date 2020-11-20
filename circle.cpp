#include"circle.h"
#include"shop.h"
#include"map.h"

void mapCircle::Move(string st, bool ex){
    if (st == "up"){
        if (canGo(x -1, y)) x-=1;
    }
    if (st == "down"){
        if (canGo(x +1, y)) x+=1;
    }
    if (st == "left"){
        if (canGo(x, y-1)) y-=1;
    }
    if (st == "right"){
        if (canGo(x, y+1)) y+=1;
    } 
}
void mapCircle::changeStatus(bool ex){
    if (ex) { color = GREEN; name = "put"; en = 1; }
    else { color = RED; name = "forbid"; en = 0; }
}

void shopCircle::Move(string st){
    if (st == "up"){
        if (canGo(x -1, y)) x-=1;
    }
    if (st == "down"){
        if (canGo(x +1, y)) x+=1;
    }
    if (st == "left"){
        if (canGo(x, y-1)) y-=1;
    }
    if (st == "right"){
        if (canGo(x, y+1)) y+=1;
    } 
    changeStatus();
 }

 void shopCircle::changeStatus(){
     if (Shop.canBuy()) { color = YELLOW; en = 1; name = "Buy"; }
     else { color = RED; en = 0; name = "can't"; }
}

