#include "plant.h"
#include "timerUse.h"
#include <QPainter>
#include"config.h"
#include"bullet.h"
int plantNormal::getMoney()
{
    return money;
}

bool plantNormal::canDouble()
{
    return two;
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
    QList<QGraphicsItem*> item = scene()->items();
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

QRectF plantNormal::boundingRect() const
{
    return QRectF(-35, -35, 70, 70);
}
