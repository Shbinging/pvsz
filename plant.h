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
        mxheart = heart = 20;
        attack = 50;//sun
        speed = 200;
        name = "̫";
        id = 10;
        coldTime = 30;
    }
    bool isGetSun(int t);
    void advance(int phase);
};

class plantHanbing :public plantNormal {
public:
    plantHanbing(location a, int t) :plantNormal(a, t) {
        money = 150;
        mxheart = heart = 70;
        attack = 10;
        speed = 20;
        name = "";
        id = 12;
        coldTime = 200;
    }
    void advance(int phase) override;
    bool isGetBullet(int t);
};

class plantShuangfa :public plantNormal {
public:
    plantShuangfa(location a, int t) :plantNormal(a, t) {
        money = 150;
        mxheart = heart = 70;
        attack = 10;
        speed = 20;
        name = "";
        id = 13;
        coldTime = 200;
    }
    void advance(int phrase) override;
    bool isGetBullet(int t);
};

class plantNut :public plantNormal {
public:
    plantNut(location a, int t) :plantNormal(a, t) {
        money = 50;
        mxheart = heart = 100;
        attack = 0;
        speed = 2;
        name = "";
        id = 14;
        coldTime = 100;
    }
    void advance(int phase);
};

class plantWogua :public plantNormal {
protected:
    bool isBomb;
public:
    plantWogua(location a, int t) :plantNormal(a, t) {
        money = 200;
        mxheart = heart = 50;
        attack = 5;
        speed = 40;
        name = "";
        id = 16;
        isBomb = 0;
        coldTime = 200;
    }
    void advance(int phase);
    bool isGrown(int t);
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void setbomb();
};

class plantCherrish :public plantNormal {
protected:
    bool isBomb;
public:
    plantCherrish(location a, int t) :plantNormal(a, t) {
        money = 300;
        mxheart = heart = 30;
        attack = 5;
        speed = 2;
        name = "";
        id = 17;
        coldTime = 300;
        isBomb = 0;
    }
    void advance(int phase);
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

class plantNan :public plantNormal {
public:
    plantNan(location a, int t) :plantNormal(a, t) {
        money = 200;
        mxheart = heart = 200;
        attack = 5;
        speed = 2;
        name = "";
        id = 30;
        two = 1;
        coldTime = 300;
    }
    void advance(int phase);
    QRectF boundingRect() const;
};

#endif // PLANT_H
