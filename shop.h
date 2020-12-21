#ifndef SHOP_H
#define SHOP_H
#include"object.h"
#include "config.h"
#include"timerUse.h"
#include<QDebug>
class shop:public object
{
    Q_OBJECT;
public:
    void clear(int t){
        money = t;
    }
    int getScore() { return score; }
    int addScore(int t) { score += t; qDebug() << "ok:"<< score; return 0; }
    int getMoney(){return money;}
    int addMoney(int t) { money += t; return 0; }
private:
    int money;
    int score;
protected:
    QPixmap* image;
public:
    shop(location a, int t):object(a, t){
        image = new QPixmap(getSourcePath("Shop","png"));
        money = 0;
        score = 0;
        id = 41;
    }
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase);
    ~shop();
};

#endif // SHOP_H
