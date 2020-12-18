#include "plant.h"
#include "timerUse.h"
#include <QPainter>
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
    if (!phase){
        update();
        setMovie(getSourcePath("Peashooter","gif"));
    }
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
