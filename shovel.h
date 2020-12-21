#ifndef SHOVEL_H
#define SHOVEL_H

#include"object.h"
#include"plant.h"
class shovel:public object
{
    Q_OBJECT
public:
    shovel(location _a, int t);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    QRectF boundingRect() const;
    void advance(int phase){}
    void reset();
};

#endif // SHOVEL_H
