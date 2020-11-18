#include"game.h"
#include"chessboard.h"
#include"shop.h"
#include"diag.h"
#include"screen.h"
game::game():
    Shop(mon),
    chess(h,l,Shop)
{
    t = 0;
    status = 0;
}
void game::play(){
    int s = 0;
    status = 1;
    display();
    bool f1;
    while(1){
        chess.Play(t);
        makePlant();
        if (chess.isLose()) {
            status = 3;
            break;
        }//lose
        if (t > 1000) {
            status = 2;
            break;
        }//win
        s++;
        //Sleep(50); //printf("%d\n", s);
        //display();
        if (s % 10 == 0) {
            t++;
        }
        else continue;
        display();
    }
    display();
    while(1);
}

void game::display(){
    Screen.cls();
    Screen.print("PlantVSZombie V0.3\n\n");
    chess.display();
    Shop.display();
    Screen.print(getStatus());
    Screen.Draw();

}

string game::getStatus(){
    if (status == 0) return "pause";
    if (status == 1) return "playing";
    if (status == 2) return "win!";
    if (status == 3) return "lose!";
}

bool game::makePlant() {
    static char ch = 0;
    static int state = 0;
    bool kbhit = 0;
    if (_kbhit())
    {
        ch = _getch();
        kbhit = 1;
    }
    if (ch == 'b') {
        state = 1;
        Shop.setInit();
    }
    if (ch == 27) {//esc
        state = 0;
    }
    if (ch == 13) {//enter
        if (state == 1) {
            //printf("ok\n");
            if (Shop.checkEn()) {
                state = 2;
                chess.setInit(Shop.getBuyId());
            }
        }
        else if (state == 2) {
            if (chess.checkEn()) {
                state = 0;
                Shop.Buy();
                chess.makePlant(Shop.getBuyId(), t);         
            }
        }
        else state = 0;
    }
    if (state == 0) {
        Shop.setDead();
        chess.setDead();
    }
    if (state == 1) {
        switch (ch) {
        case 75: Shop.MoveCircle("left"); break;
        case 77: Shop.MoveCircle("right");  break;
        }
    }
    if (state == 2) {
        switch (ch) {
        case 75: chess.MoveCircle("left", Shop.getBuyId()); break;
        case 77: chess.MoveCircle("right", Shop.getBuyId()); break;
        case 72: chess.MoveCircle("up", Shop.getBuyId()); break;
        case 80: chess.MoveCircle("down", Shop.getBuyId());break;
        }
    }
    ch = 0;
    if (kbhit) display();
    return kbhit;
}