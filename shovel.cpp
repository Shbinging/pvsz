#include "shovel.h"

#include<QPainter>
#include<QDrag>
#include<QMimeData>
#include"timerUse.h"
shovel::shovel(location _a, int t):object(_a, t)
{
    name = "Shovel";
    id = 43;
}

void shovel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(QRect(-40, -40, 80, 80), QPixmap(":/images/ShovelBank.png"));
    painter->drawPixmap(QRect(-35, -35, 70, 70), QPixmap(":/images/Shovel.png"));
}

void shovel::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug()<<"new";
    QDrag* drag = new QDrag(this);
    QMimeData* mime = new QMimeData;
    QImage image(getSourcePath(name, "png"));
    QPixmap pic(getSourcePath(name, "png"));
    pic = pic.scaledToHeight(70);
    mime->setText("-1");
    drag->setHotSpot(QPoint(35, 35));
    drag->setMimeData(mime);
    drag->setPixmap(pic);
    drag->exec();
}

QRectF shovel::boundingRect() const
{
    return QRectF(-40, -40, 80, 80);
}

void shovel::reset()
{
    setLocation(location(830, 40));
}
