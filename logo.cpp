#include "logo.h"
#include"object.h"
#include<QPainter>

logoWin::logoWin(location _a):object(_a, 0)
{
    setZValue(20);
}

QRectF logoWin::boundingRect() const
{
    return QRectF(0, 0, 1000, 1000);
}

void logoWin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(QRect(10, 10, 564, 468), QPixmap(getSourcePath("ZombiesWon", "png")));
}

void logoWin::advance(int phase)
{
    update();
}

logoLose::logoLose(location _a):object(_a, 0)
{
setZValue(20);
}

QRectF logoLose::boundingRect() const
{
    return QRectF(0, 0, 1000, 1000);
}

void logoLose::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
 painter->drawPixmap(QRect(0, 0, 166, 134), QPixmap(getSourcePath("trophy", "png")));
}

void logoLose::advance(int phase)
{
    update();
}
