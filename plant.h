#ifndef PLANT_H
#define PLANT_H
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QString>
#include "object.h"
class plantNormal: public object{
    Q_OBJECT
    protected:
        int money;
        bool two;
        int coldTime;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
        QRectF boundingRect() const;
    public:
        plantNormal(location a, int t):
        object(a, t)
        {
            ttype = 2;
            two = 0;
        }
        int getMoney();
        bool canDouble();
        int getColdTime();
};

class plantWandou:public plantNormal{
    public:
        plantWandou(location a, int t):plantNormal(a, t){
            money = 100;
            mxheart = heart = 30;
            attack = 5;
            speed = 2;
            name = "豌";
            id = 11;
            coldTime = 10;


        }
        void advance(int phrase) override;
};

#endif // PLANT_H
