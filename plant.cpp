#include "plant.h"
#include "timerUse.h"
#include <QPainter>
#include"config.h"
#include"bullet.h"
#include<QRandomGenerator>
#include"shop.h"
#include"zombie.h"
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
    destY = QRandomGenerator::global()->bounded(300, windowHeight - 50);
    destX = a.x;
    canMove = 0;
    speed = 1;
    sunX = 40;
    sunY = 20;
    id = 31;
    attack = 50;
}

void sun::advance(int phase)
{
    setZValue(10);
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
        QList<QGraphicsItem*> g = scene()->items(QPointF(shopLocationX, shopLocationY));
        //qDebug()<< g.size();
        shop *s;
        Forr(i, 0, g.size()){
            object* tmp =qgraphicsitem_cast<object*>(g[i]);
            if (tmp->getId() == 41){
                s = qgraphicsitem_cast<shop*>(g[i]);
            }
        }
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

void plantHanbing::advance(int phase)
{
    update();
    if (!phase){
        if (isDead()){
            setDead();
            return;
        }
        setMovie(getSourcePath("SnowPea","gif"));

        if (isGetBullet(t)){
            bulletBing* tmp = new bulletBing(location(x() + 30, y()), t);
            scene()->addItem(tmp);
        }
    }
}

bool plantHanbing::isGetBullet(int t)
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

void plantShuangfa::advance(int phrase)
{
    update();
    if (!phrase){
        if (isDead()){
            setDead();
            return;
        }
        setMovie(getSourcePath("Repeater","gif"));

        if (isGetBullet(t)){
            bullet* tmp = new bullet(location(x() + 30, y()), t);
            bullet* tmp1 = new bullet(location(x() + 40, y()), t);
            scene()->addItem(tmp);
            scene()->addItem(tmp1);
        }
    }
}

bool plantShuangfa::isGetBullet(int t)
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

void plantNut::advance(int phase)
{
    update();
    if (!phase){
        if (isDead()){
            setDead();
            return;
        }
        if (heart >= 2.0/3 * mxheart) setMovie(getSourcePath("WallNut","gif"));
        else if (heart >= 1.0/3 * mxheart) setMovie(getSourcePath("WallNut1", "gif"));
        else setMovie(getSourcePath("WallNut2", "gif"));
    }
}

void plantWogua::advance(int phase)
{
    update();
    if (!phase){
        if (isBomb){
            setMovie(getSourcePath("PotatoMineBomb","gif"));
            if (movie->frameCount() - 1 == movie->currentFrameNumber()){
                setDead();
            }
            return;
        }
        if (isDead()){
            setDead();
            return;
        }
        if (!isGrown(t)){
            setMovie(getSourcePath("PotatoMine1","gif"));
        }
        else{
            setMovie(getSourcePath("PotatoMine","gif"));
            QList<QGraphicsItem*> g = collidingItems();
            bool f = 0;
            Forr(i, 0, g.size()) {
                object* tmp =qgraphicsitem_cast<object*> (g[i]);
                if (isZombie(tmp->getId()) && !tmp->isDead()) {
                    zombieNormal* tmp1 = qgraphicsitem_cast<zombieNormal*> (tmp);
                    if (tmp1->getId() == 23){
                        zombieGan* tmp2 = qgraphicsitem_cast<zombieGan*>(tmp1);
                        qDebug()<<"get "<<tmp2->getDrop();
                        if (tmp2->getDrop() <= 3) continue;
                    }
                    tmp1->setHeart(-1);
                    tmp1->setBomb();
                    f = 1;
                }
            }
            if (f) setbomb();
        }
    }
}

bool plantWogua::isGrown(int t)
{
    return t - setTime > speed;
}

bool plantWogua::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 30;
}

void plantWogua::setbomb()
{
    isBomb = 1;
}

void plantCherrish::advance(int phase)
{
    update();
    if (!phase){
        if (t - setTime > speed){
            if (!isBomb){
                setMovie(getSourcePath("CherryBomb","gif"));
                if (movie->frameCount() - 1 == movie->currentFrameNumber()){
                    isBomb = 1;
                    QList<QGraphicsItem*> g = collidingItems();
                    bool f = 0;
                    Forr(i, 0, g.size()) {
                        object* tmp =qgraphicsitem_cast<object*> (g[i]);
                        if (isZombie(tmp->getId()) && !tmp->isDead()) {
                            zombieNormal* tmp1 = qgraphicsitem_cast<zombieNormal*> (tmp);
                            tmp1->setHeart(-1);
                            tmp1->setBomb();
                            f = 1;
                        }
                    }
                }
            }
            else{
                setMovie(getSourcePath("Boom","gif"));
                if (movie->frameCount() - 1 == movie->currentFrameNumber()){
                    setDead();
                }
            }
        }
    }
}

bool plantCherrish::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return qAbs(other->x() - x()) < 80*1.5 && qAbs(other->y() - y()) < 98*1.5;
}

void plantCherrish::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (movie){
    QImage image = movie->currentImage();
    QRectF tmp = boundingRect();
    if (isBomb) tmp = QRectF(-35 * 3, -35 * 3, 70 * 3, 70 * 3);

        painter->drawImage(tmp, image);
    }
    if (head){
        QImage image = head->currentImage();
        painter->drawImage(boundingRect(), image);
    }
}

void plantNan::advance(int phase)
{
    setZValue(1);
    update();
    if (!phase){
        if (isDead()){
            setDead();
            return;
        }
        if (heart >= 2.0/3 * mxheart) setMovie(getSourcePath("Pumpkin","gif"));
        else if (heart >= 1.0/3 * mxheart) setMovie(getSourcePath("pumpkin1", "gif"));
        else setMovie(getSourcePath("Pumpkin2", "gif"));
    }
}

QRectF plantNan::boundingRect() const
{
    return QRectF(-40, -10, 80, 50);
}
