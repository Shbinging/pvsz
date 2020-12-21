#include "plant.h"
#include "timerUse.h"
#include <QPainter>
#include"config.h"
#include"bullet.h"
#include<QRandomGenerator>
#include"shop.h"
int plantNormal::getMoney()
{
    return money;
}

bool plantNormal::canDouble()
{
    return two;
}

int plantNormal::getColdTime()
{
    return coldTime;
}

void plantWandou::advance(int phase)
{
    update();
    if (!phase){
        if (isDead()){
            setDead();
            return;
        }
        setMovie(getSourcePath("Peashooter","gif"));

        if (isGetBullet(t)){
            bullet* tmp = new bullet(location(x() + 30, y()), t);
            scene()->addItem(tmp);
        }
    }
}

bool plantWandou::isGetBullet(int t)
{
    bool hasZombie = 0;
    QList<QGraphicsItem*> item = collidingItems();
    Forr(i, 0, item.size()){
        object* tmp = qgraphicsitem_cast<object*>(item[i]);
        if (isZombie(tmp->getId()) && !tmp->isDead()){
            hasZombie = 1;
        }
    }
    if ((t - setTime) % speed == 0 && hasZombie)
         return 1;
     else return 0;
}

void plantNormal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (movie){
    QImage image = movie->currentImage();
   painter->drawImage(boundingRect(), image);
    }
    if (head){
        QImage image = head->currentImage();
        painter->drawImage(boundingRect(), image);
    }
}

bool plantNormal::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return qFuzzyCompare(other->y(), y());
}

QRectF plantNormal::boundingRect() const
{
    return QRectF(-35, -35, 70, 70);
}

sun::sun(location a, int t):plantNormal(a, t)
{
    destY = QRandomGenerator::global()->bounded(50, windowHeight - 50);
    destX = a.x;
    canMove = 0;
    speed = 1;
    sunX = 40;
    sunY = 20;
    id = 31;
    attack = 500;
}

void sun::advance(int phase)
{
    if (!phase){
        update();
        setMovie(getSourcePath("Sun","gif"));
        move(t);
    }
}

void sun::calc()
{
    int xx = qAbs(getLocation().x - destX);
    int yy = qAbs(getLocation().y - destY);

    //qDebug()<<"xx" << xx <<" "<<yy;
    stepX = qMax(int(10.0 * xx / yy), 1);
    stepY = 10;
    if (speed == 0){ stepX *= 3; stepY *= 3;}
    /*
    else{
        xx /=20;
        yy /= 20;
    }*/
}

void sun::move(int t)
{
    if (getLocation().x == sunLocationX && getLocation().y == sunLocationY){
        shop *s = qgraphicsitem_cast<shop *>(scene()->items(QPointF(shopLocationX, shopLocationY))[0]);
        s->addMoney(attack);
        setDead();
        return;
    }
    if (!canMove) return;
    if (speed == 0 || ((t - setTime) % speed == 0 && t - setTime > 0)) {
        location tmp = getLocation();
        int toX = tmp.x, toY = tmp.y;
        if (tmp.x < destX) toX += qMin(stepX, qAbs(tmp.x - destX));
        if (tmp.x > destX) toX -= qMin(stepX, qAbs(tmp.x - destX));
        if (tmp.y < destY) toY += qMin(stepY, qAbs(tmp.y - destY));
        if (tmp.y > destY) toY -= qMin(stepY, qAbs(tmp.y - destY));
        //qDebug()<< stepX << " "<< toX<<" "<<toY;
        setLocation(location(toX, toY));
    }
}

void sun::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    destX = sunLocationX;
    destY = sunLocationY;
    speed = 0;
    setZValue(1);
    setMove();
}

void sun::setMove()
{
    canMove = 1;
    calc();
}

void sun::setPause()
{
    canMove = 0;
}

bool plantSun::isGetSun(int t)
{
    if ((t - setTime) % speed == 0 && (t - setTime > 0))
         return 1;
     else return 0;
}

void plantSun::advance(int phase)
{
    update();
    if (!phase){
        if (isDead()){
            setDead();
            return;
        }
        setMovie(getSourcePath("SunFlower","gif"));

        if (isGetSun(t)){
            sun* tmp = new sun(location(x() + 30, y() + 30), t);
            scene()->addItem(tmp);
        }
    }
}
