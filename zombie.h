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

class zombieLu: public zombieNormal{
protected:
    bool isDrop;
    public:
        zombieLu(location a, int t):zombieNormal(a, t){
            attack = 5;
            mxheart = heart = 100;
            speed = 5;
            attackSpeed = 8;
            id = 21;
            score = 5;
            name = "僵";
        }
    void Attack(int t);
    void Move(int t);
    void advance(int phase) override;
};

class zombieBao: public zombieNormal{
protected:
    bool isDrop;
    public:
        zombieBao(location a, int t):zombieNormal(a, t){
            attack = 5;
            mxheart = heart = 400;
            speed = 5;
            attackSpeed = 8;
            id = 21;
            score = 5;
            isDrop = 0;
            name = "僵";
        }
    void Attack(int t);
    void Move(int t);
    void advance(int phase) override;
};

class zombieGan: public zombieNormal{
protected:
    int isDrop;
    public:
        zombieGan(location a, int t):zombieNormal(a, t){
            attack = 5;
            mxheart = heart = 40;
            speed = 5;
            attackSpeed = 8;
            id = 23;
            score = 5;
            isDrop = 0;
            name = "僵";
        }
    int getDrop();
    void Attack(int t);
    void Move(int t);
    void advance(int phase) override;
    QRectF boundingRect() const override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};
#endif // ZOMBIE_H
