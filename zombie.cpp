#include "zombie.h"
#include "timerUse.h"
#include"config.h"
#include<QObject>
#include<QList>
#include<QPainter>
void zombieBasic::advance(int phase)
{
    if (!phase){
        update();
        if (isDead()){
            setMovie(getSourcePath("ZombieDie","gif"));
            setHead(getSourcePath("ZombieHead","gif"));
            if (head->frameCount() - 1 == head->currentFrameNumber()){
                setDead();
            }
            return;
        }
        Attack(t);
        Move(t);
    }
}

void zombieBasic::Attack(int t)
{
    QList<QGraphicsItem*> g = collidingItems();
    Forr(i, 0, g.size()) {
        object* tmp =qgraphicsitem_cast<object*> (g[i]);
        if (isProtecter(tmp->getId()) && !tmp->isDead()) {
            setMovie(getSourcePath("ZombieAttack", "gif"));
            movie->setSpeed(1000/attackSpeed);
            if ((t-setTime)%attackSpeed) return;
            tmp->subHeart(attack);
            return;
        }
    }
    Forr(i, 0, g.size()){
        object* tmp =qgraphicsitem_cast<object*> (g[i]);
        if (isPlant(tmp->getId()) && !tmp->isDead()) {
            setMovie(getSourcePath("ZombieAttack", "gif"));
            movie->setSpeed(1000/attackSpeed);
            if ((t-setTime)%attackSpeed) return;
            tmp->subHeart(attack);
            return;
        }
    }
}

void zombieBasic::Move(int t)
{
    QList<QGraphicsItem*> g = collidingItems();
    Forr(i, 0, g.size()){
        object* tmp =qgraphicsitem_cast<object*> (g[i]);
        if (isPlant(tmp->getId())) return;
    }
    setMovie(getSourcePath("ZombieWalk1", "gif"));
    movie->setSpeed(1000/speed);
    if ((t - setTime) % speed == 0 && t - setTime > 0) {
        location tmp = getLocation();
        setLocation(location(tmp.x - 5, tmp.y));
    }
}

bool zombieNormal::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 30;
}

void zombieNormal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (movie){
    QImage image = movie->currentImage();
    painter->drawImage(QRectF(-70, -100, 140, 140), image);
    }
    if (head){
        QImage image = head->currentImage();
        painter->drawImage(QRectF(0, -100, 140, 140), image);
    }
}

QRectF zombieNormal::boundingRect() const
{
    return QRectF(-80, -100, 200, 140);
}
