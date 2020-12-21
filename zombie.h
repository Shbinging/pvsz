#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "object.h"
#include <QMovie>
#include <QObject>
#include <QGraphicsItem>
class zombieNormal: public object{
    Q_OBJECT
private:

protected:
    int setColdTime;
    int needColdTime;
    bool isBomb;
        int score;
        int attackSpeed;
        bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
        QRectF boundingRect() const override;
    public:
        bool isCold();
        void setCold(int tt);
        zombieNormal(location a, int t):
        object(a, t)
        {
            setColdTime = t;
            needColdTime = -1;
            ttype = 3;
            isBomb = 0;
            //init();
        }
        ~zombieNormal(){}
        virtual void Attack(int t) = 0;
        virtual void Move(int t) = 0;
        void setBomb();
};

class zombieBasic: public zombieNormal{
    public:
        zombieBasic(location a, int t):zombieNormal(a, t){
            attack = 5;
            mxheart = heart = 100;
            speed = 5;
            attackSpeed = 8;
            id = 20;
            score = 5;
            name = "僵";
        }
    void Attack(int t);
    void Move(int t);
    void advance(int phase) override;
};
#endif // ZOMBIE_H
