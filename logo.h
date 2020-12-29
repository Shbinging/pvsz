#ifndef LOGO_H
#define LOGO_H
#include"object.h"
#include"timerUse.h"
#include<QString>
class logoWin:public object
{
public:
    logoWin(location _a);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase);
};

class logoLose:public object
{
public:
    logoLose(location _a);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase);
};

#endif // LOGO_H
