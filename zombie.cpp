#include "zombie.h"
#include "timerUse.h"
#include"config.h"
#include<QObject>
#include<QList>
#include<QPainter>
void zombieBasic::advance(int phase)
{
    setZValue(2);
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
    if ((t - setTime) % attackSpeed == 0 && t - setTime > 0){
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

void zombieLu::Attack(int t)
{
    if ((t - setTime) % attackSpeed == 0 && t - setTime > 0){
    QList<QGraphicsItem*> g = collidingItems();
    Forr(i, 0, g.size()) {
        object* tmp =qgraphicsitem_cast<object*> (g[i]);
        if (isProtecter(tmp->getId()) && !tmp->isDead()) {
            if (heart > mxheart / 3) setMovie(getSourcePath("ConeZombieAttack","gif"));
            else setMovie(getSourcePath("ZombieAttack", "gif"));
            movie->setSpeed(1000/attackSpeed);
            if ((t-setTime)%attackSpeed) return;
            tmp->subHeart(attack);
            return;
        }
    }
    Forr(i, 0, g.size()){
        object* tmp =qgraphicsitem_cast<object*> (g[i]);
        if (isPlant(tmp->getId()) && !tmp->isDead()) {
            if (heart > mxheart / 3) setMovie(getSourcePath("ConeZombieAttack","gif"));
            else setMovie(getSourcePath("ZombieAttack", "gif"));
            movie->setSpeed(1000/attackSpeed);
            if ((t-setTime)%attackSpeed) return;
            tmp->subHeart(attack);
            return;
        }
    }
    }
}

void zombieLu::Move(int t)
{
    QList<QGraphicsItem*> g = collidingItems();
    Forr(i, 0, g.size()){
        object* tmp =qgraphicsitem_cast<object*> (g[i]);
        if (isPlant(tmp->getId())) return;
    }
    if (heart < mxheart / 3) setMovie(getSourcePath("ZombieWalk1","gif"));
    else setMovie(getSourcePath("ConeZombieWalk", "gif"));
    movie->setSpeed(1000/speed);
    if ((t - setTime) % speed == 0 && t - setTime > 0) {
        location tmp = getLocation();
        setLocation(location(tmp.x - 5, tmp.y));
    }
}

void zombieLu::advance(int phase)
{
    setZValue(2);
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

void zombieBao::Attack(int t)
{
    if ((t - setTime) % attackSpeed == 0 && t - setTime > 0){
    QList<QGraphicsItem*> g = collidingItems();
    Forr(i, 0, g.size()) {
        object* tmp =qgraphicsitem_cast<object*> (g[i]);
        if (isProtecter(tmp->getId()) && !tmp->isDead()) {
            if (heart > mxheart / 3) setMovie(getSourcePath("BucketZombieAttack","gif"));
            else setMovie(getSourcePath("ZombieAttack", "gif"));
            movie->setSpeed(1000/attackSpeed);
            if ((t-setTime)%attackSpeed) return;
            tmp->subHeart(attack);
            return;
        }
    }
    Forr(i, 0, g.size()){
        object* tmp =qgraphicsitem_cast<object*> (g[i]);
        if (isPlant(tmp->getId()) && !tmp->isDead()) {
            if (heart > mxheart / 3) setMovie(getSourcePath("BucketZombieAttack","gif"));
            else setMovie(getSourcePath("ZombieAttack", "gif"));
            movie->setSpeed(1000/attackSpeed);
            if ((t-setTime)%attackSpeed) return;
            tmp->subHeart(attack);
            return;
        }
    }
    }
}

void zombieBao::Move(int t)
{
    QList<QGraphicsItem*> g = collidingItems();
    Forr(i, 0, g.size()){
        object* tmp =qgraphicsitem_cast<object*> (g[i]);
        if (isPlant(tmp->getId())) return;
    }
    if (heart < mxheart / 3){
        setMovie(getSourcePath("ZombieWalk1","gif"));
        if (!isDrop){
            isDrop = 1;
            speed /= 3;
        }
    }
    else setMovie(getSourcePath("BucketZombieWalk", "gif"));
    movie->setSpeed(1000/speed);
    if ((t - setTime) % speed == 0 && t - setTime > 0) {
        location tmp = getLocation();
        setLocation(location(tmp.x - 5, tmp.y));
    }
}

void zombieBao::advance(int phase)
{
    setZValue(2);
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

int zombieGan::getDrop()
{
    return isDrop;
}

void zombieGan::Attack(int t)
{
    if ((t - setTime) % attackSpeed == 0 && t - setTime > 0 && isDrop == 4){
    QList<QGraphicsItem*> g = collidingItems();
    Forr(i, 0, g.size()) {
        object* tmp =qgraphicsitem_cast<object*> (g[i]);
        if (isProtecter(tmp->getId()) && !tmp->isDead()) {
            if (heart > mxheart / 3) setMovie(getSourcePath("PoleVaultingZombieAttack","gif"));
            else setMovie(getSourcePath("PoleVaultingZombieAttack", "gif"));
            movie->setSpeed(1000/attackSpeed);
            if ((t-setTime)%attackSpeed) return;
            tmp->subHeart(attack);
            return;
        }
    }
    Forr(i, 0, g.size()){
        object* tmp =qgraphicsitem_cast<object*> (g[i]);
        if (isPlant(tmp->getId()) && !tmp->isDead()) {
            if (heart > mxheart / 3) setMovie(getSourcePath("PoleVaultingZombieAttack","gif"));
            else setMovie(getSourcePath("PoleVaultingZombieAttack", "gif"));
            movie->setSpeed(1000/attackSpeed);
            if ((t-setTime)%attackSpeed) return;
            tmp->subHeart(attack);
            return;
        }
    }
    }
}

void zombieGan::Move(int t)
{
    int delta = 1;
    bool hasPlant = 0;
    QList<QGraphicsItem*> g = collidingItems();
    Forr(i, 0, g.size()){
        object* tmp =qgraphicsitem_cast<object*> (g[i]);
        if (isPlant(tmp->getId())) hasPlant = 1;
    }
    if (isDrop == 0 && !hasPlant){
        setMovie(getSourcePath("PoleVaultingZombie", "gif"));
        movie->setSpeed(3000/speed);
    }
    if (hasPlant == 1 && isDrop == 0){
        movie = new QMovie(getSourcePath("PoleVaultingZombieJump", "gif"));
        //movie->setSpeed(80);
        movie->start();
        //setMovie(getSourcePath("PoleVaultingZombieJump", "gif"));
        //movie->setSpeed(100);
        isDrop++;
        qDebug()<<"ok:"<<isDrop;
    }
    else
    if (isDrop >= 1 && isDrop <= delta){
        location tmp = getLocation();
        setLocation(location(tmp.x - 5, tmp.y));
        if (movie->frameCount() - 1 <= movie->currentFrameNumber()){
            isDrop++;

        }
    }
    else
    if (isDrop == 1+delta){
        location tmp = getLocation();
        setLocation(location(tmp.x - 45, tmp.y));
        movie = new QMovie(getSourcePath("PoleVaultingZombieJump2", "gif"));
        movie->start();
        //movie->setSpeed(10000);
        qDebug()<< "1";
        isDrop++;
    }
    if (isDrop == 2+delta){
         location tmp = getLocation();
        setLocation(location(tmp.x - 3, tmp.y));
        if (movie->frameCount() - 1 == movie->currentFrameNumber()){
            isDrop++;
            setMovie(getSourcePath("PoleVaultingZombieWalk", "gif"));
            speed *= 1.4;
            movie->setSpeed(1000/speed);
             qDebug()<< "2";
        }
    }
    else{
    if (isDrop == 3+delta && hasPlant) return;
    if (isDrop == 4) setMovie(getSourcePath("PoleVaultingZombieWalk", "gif"));
    movie->setSpeed(1000/speed);
    if ((t - setTime) % speed == 0 && t - setTime > 0) {
        location tmp = getLocation();
        setLocation(location(tmp.x - 5, tmp.y));
    }
    }
}

void zombieGan::advance(int phase)
{
    setZValue(2);
    if (!phase){
        update();
        if (isDead()){
            if (!isBomb){
                setMovie(getSourcePath("PoleVaultingZombieDie","gif"));
                setHead(getSourcePath("PoleVaultingZombieHead","gif"));
            }
            else{
                setMovie(getSourcePath("BoomDie", "gif"));
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

QRectF zombieGan::boundingRect() const
{
    return QRectF(-80*1.8, -100*1.5, 200*1.8, 140*1.5);
}

bool zombieGan::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 30;
}

void zombieGan::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (movie){

        QImage image = movie->currentImage();
        if (isCold()) changeBlue(image);
    painter->drawImage(QRectF(-70 * 1.8, -100 * 1.5, 140 * 1.8, 140 * 1.5), image);
    }
    if (head){

        QImage image = head->currentImage();
        if (isCold()) changeBlue(image);
        painter->drawImage(QRectF(-70, -100, 140 * 1.8, 140 * 1.5), image);
    }
}
