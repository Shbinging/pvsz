#include "shop.h"
#include<QPainter>
#include<QString>

QRectF shop::boundingRect() const
{
    return QRectF(-270, -45, 540, 90);
}

void shop::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if (image) painter->drawPixmap(QRect(-270, -45, 540, 90), *image);
    QFont font;
    font.setPointSizeF(10);
    painter->setFont(font);
    painter->drawText(QRectF(-255, 18, 65, 22), Qt::AlignCenter, QString::number(money));
    painter->drawPoint(-220, 0);
}

void shop::advance(int phase)
{
    update();
}

shop::~shop()
{
    if (image) delete image;
}
