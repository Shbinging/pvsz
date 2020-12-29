#ifndef BULLET_H
#define BULLET_H
#include"object.h"
#include<QImage>
#include "timerUse.h"
class bulletNormal:public object{
    Q_OBJECT
protected:
QPixmap* image;
    public:
    bulletNormal(location a, int tt):object(a, tt){}
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    virtual void Attack();
    virtual void Move(int t);
    virtual void advance(int phase);
    ~bulletNormal(){delete image;}
};

class bullet:public bulletNormal{
public:
    bullet(location a, int tt):bulletNormal(a, tt){
        attack = 12;
        live = 1;
        name = "*";
        speed = 1;
        //qDebug()<<"create";
        id = 0;
        image = new QPixmap(getSourcePath("Pea", "png"));
    }
};
class car:public bulletNormal{
private:
    bool goOn;
public:
    car(location _a, int tt):bulletNormal(_a, tt){
        attack = 100000;
        live = 1;
        name = "*";
        speed = 1;
        //qDebug()<<"create";
        id = 5;
        image = new QPixmap(getSourcePath("LawnMower", "png"));
        goOn = 0;
    }
    void Attack();
    void Move(int t);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

class bulletBing:public bulletNormal{
private:
  int coldTime;
public:
    bulletBing(location a, int tt):bulletNormal(a, tt){
        coldTime = 100;
        attack = 15;
        live = 1;
        name = "*";
        speed = 1;
        //qDebug()<<"create";
        id = 1;
        image = new QPixmap(getSourcePath("PeaSnow", "png"));
    }
    virtual void Attack();
};
#endif // BULLET_H
