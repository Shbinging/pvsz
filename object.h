#ifndef OBJECT
#define OBJECT
#include "diag.h"

using namespace std;
struct location{
    int x, y;
    location();
    location(int xx, int yy){
        x = xx;
        y = yy;
    }
};
class object{
    protected:
        int id;
        string name;
        int type;//1 plant 2 sun 3 zombie 
        int x, y;
        int setTime;
        bool live;
        int heart, mxheart;
        int attack;
        int speed;
        int color;
    public:
        virtual void run(int t){}
        object(location a, int t){
            setLocation(a);
            setTime = t;
            setLive();
            color = WHITE;
        }
        int getId(){return id;}
        location getLocation(){
            return location(x, y);
        }
        void setLocation(location a){
            x = a.x;
            y = a.y;
        }
        void setAttack(int x){
            attack = x;
        }
        int getAttack(){
            return attack;
        }
        void setSpeed(int x){
            speed = x;
        }
        int getSpeed(){
            return speed;
        }
        void setHeart(int x){
            heart = x;
        }
        void subHeart(int x){
            heart -= x;
            if (heart <= 0) setDead();
        }
        int getHeart() { return heart; }
        string getName(){return name;}
        int getType(){return type;}
        bool isDead(){
            return !live;
        }
        virtual void setDead(){
            live = 0;
        }
        void setLive(){
            live = 1;
        }        
        object(){
            setLive();
        }
};

#endif