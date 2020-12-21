#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "object.h"
#include <QMovie>
#include <QObject>
#include <QGraphicsItem>
class zombieNormal: public object{
    Q_OBJECT
    protected:
        int score;
        int attackSpeed;
        bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
        QRectF boundingRect() const override;
    public:
        zombieNormal(location a, int t):
        object(a, t)
        {
            ttype = 3;
            //init();
        }
        ~zombieNormal(){}
        virtual void Attack(int t) = 0;
        virtual void Move(int t) = 0;
};

class zombieBasic: public zombieNormal{
    public:
        zombieBasic(location a, int t):zombieNormal(a, t){
            attack = 5;
            mxheart = heart = 10000;
            speed = 5;
            attackSpeed = 4;
            id = 20;
            score = 5;
            name = "僵";
        }
    void Attack(int t);
    void Move(int t);
    void advance(int phase) override;
};
#endif // ZOMBIE_H
