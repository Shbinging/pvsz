#ifndef BUTTON_H
#define BUTTON_H

#include <QTimer>
#include "object.h"

class Button : public object
{
    bool ok;
public:
    Button(QTimer *t);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
private:
    QTimer *timer;
};

#endif // BUTTON_H
