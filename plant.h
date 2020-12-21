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
        bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
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
            speed = 20;
            name = "豌";
            id = 11;
            coldTime = 100;
        }
        void advance(int phrase) override;
        bool isGetBullet(int t);
};

class sun: public plantNormal{
    Q_OBJECT
protected:
    int destY;
    int destX;
    bool canMove;
    int sunX, sunY;
    int stepX, stepY;
public:
    sun(location a, int t);
    void advance(int phase);
    void calc();
    void move(int t);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void setMove();
    void setPause();
};

class plantSun :public plantNormal {
public:
    plantSun(location a, int t) :plantNormal(a, t) {
        money = 25;
        mxheart = heart = 500;
        attack = 50;//sun
        speed = 30;
        name = "̫";
        id = 10;
        coldTime = 10;
    }
    bool isGetSun(int t);
    void advance(int phase);
};
#endif // PLANT_H
