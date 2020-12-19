#include "bullet.h"
#include"config.h"
#include"timerUse.h"
#include<QPainter>
#include<QDebug>
QRectF bulletNormal::boundingRect() const
{
    return QRectF(-12, -28, 24, 24);
}

void bulletNormal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (image)
        painter->drawPixmap(QRect(-12, -28, 24, 24), *image);
}

bool bulletNormal::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 30;
}

void bulletNormal::Attack()
{
    QList<QGraphicsItem*> g = collidingItems();
    Forr(i, 0, g.size()) {
        object* tmp =qgraphicsitem_cast<object*> (g[i]);
        if (isZombie(tmp->getId()) && !tmp->isDead()) {
            tmp->subHeart(attack);
            setDead();
            qDebug()<< "dead!!!";
            return;
        }
    }
}

void bulletNormal::Move(int t)
{
    if (!((t - setTime) % speed) && t - setTime > 0){
        location tmp = getLocation();
        setLocation(location(tmp.x + 5, tmp.y));
    }
}

void bulletNormal::advance(int phase)
{
    if (!phase){
        update();
        Attack();
        Move(t);
    }
}
