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
            if (!isBomb){
                setMovie(getSourcePath("ZombieDie","gif"));
                setHead(getSourcePath("ZombieHead","gif"));
            }
            else{
                setMovie(getSourcePath("Burn", "gif"));
            }
            if (movie->frameCount() - 1 == movie->currentFrameNumber()){
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

void changeBlue(QImage& p){
    int width = p.width();
    int height = p.height();
    Forr(i, 0, width)
        Forr(j, 0, height){
            QColor col = p.pixelColor(i, j);
            col.setBlue(254);
            p.setPixelColor(i, j, col);
        }
}
void zombieNormal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (movie){
        movie->setSpeed(1000/speed);
        QImage image = movie->currentImage();
        if (isCold()) changeBlue(image);
    painter->drawImage(QRectF(-70, -100, 140, 140), image);
    }
    if (head){
        head->setSpeed(1000/speed);
        QImage image = head->currentImage();
        if (isCold()) changeBlue(image);
        painter->drawImage(QRectF(0, -100, 140, 140), image);
    }
}

QRectF zombieNormal::boundingRect() const
{
    return QRectF(-80, -100, 200, 140);
}

bool zombieNormal::isCold()
{
    if (t-setColdTime == needColdTime + 1) speed /= 3;
    return (t-setColdTime) <= needColdTime;
}

void zombieNormal::setCold(int tt)
{
    if (!isCold()){
    needColdTime = tt;
    speed *= 3;
    setColdTime = t;
    }
}

void zombieNormal::setBomb()
{
    isBomb = 1;
}
