#include "button.h"
#include<QPainter>
#include<QGraphicsSceneMouseEvent>
Button::Button(QTimer *t)
{
    timer = t;
    ok = 0;
}

QRectF Button::boundingRect() const
{
    return QRectF(-80, -20, 160, 40);
}

void Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(QRect(-80, -20, 160, 40), QPixmap(":/images/Button.png"));
    painter->setPen(Qt::green);
    QFont font("Calibri", 12, QFont::Bold, true);
    painter->setFont(font);
    if (timer->isActive())
        painter->drawText(boundingRect(), Qt::AlignCenter, "PAUSE");
    else{
        if (!ok){
            painter->drawText(boundingRect(), Qt::AlignCenter, "START");
            ok = 1;
        }else
        painter->drawText(boundingRect(), Qt::AlignCenter, "CONTINUE");
       }
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        if (timer->isActive())
        {
            timer->stop();
        }
        else
        {
            timer->start(50);
        }
    }
    update();
}
