#include "card.h"
#include<QPainter>
#include"pzcreator.h"
#include"timerUse.h"
#include"object.h"
#include"plant.h"
#include<QMap>
#include <QGraphicsSceneDragDropEvent>
#include<QApplication>
#include<QDrag>
#include<QMimeData>
#include<stdio.h>
#include"shop.h"
const QMap<int, QString> IdtoName = {{10, "SunFlower"},{11, "Peashooter"}, {20, "zombieBasic"},{31, "sun"}};

card::card(location _a, int t, int _id):object(_a, t)
{
    candrag = 1;
    id = 40;
    id1 = _id;
    name = IdtoName[id1];
    pzCreator tmp;
    object* p = tmp.createObject(id1);
    plantNormal* q = qgraphicsitem_cast<plantNormal*> (p);
    coldTime = q->getColdTime();
    money = q->getMoney();
}

QRectF card::boundingRect() const
{
    return QRectF(-50, -30, 100, 60);
}

void card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->scale(0.6, 0.58);
    painter->drawPixmap(QRect(-50, -70, 100, 140), QPixmap(getSourcePath("Card", "png")));
    painter->drawPixmap(QRect(-35, -42, 70, 70), QPixmap(getSourcePath(name, "png")));
    QFont font;
    font.setPointSizeF(13);
    painter->setFont(font);
    pzCreator a;
    object* b = a.createObject(id1);
    plantNormal* c = qgraphicsitem_cast<plantNormal* > (b);
    painter->drawText(-35, 65, QString().sprintf("%3d", c->getMoney()));
    if (t - setTime < coldTime){
        candrag = 0;
        QBrush brush(QColor(0, 0, 0, 200));
        painter->setBrush(brush);
        painter->drawRect(QRectF(-48, -68, 98, 132 * (1- 1.0*(t - setTime) / coldTime)));
    }
}

void card::advance(int phase)
{
     update();
     QList<QGraphicsItem*> g = scene()->items(QPoint(shopLocationX, shopLocationY));
     shop* s = nullptr;
     Forr(i, 0, g.size()){
         object* tmp =qgraphicsitem_cast<object*>(g[i]);
         if (tmp->getId() == 41){
             s = qgraphicsitem_cast<shop*>(g[i]);
         }
     }
    assert(s != 0);
    if (s->getMoney() < money){
        candrag = 0;
    }
    else
    if (t - setTime < coldTime){
        candrag = 0;
    }
    else candrag = 1;
}

void card::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //qDebug()<<"new" << candrag;
    if (!candrag) return;
    //qDebug()<<"new";
    QDrag* drag = new QDrag(this);
    QMimeData* mime = new QMimeData;
    QImage image(getSourcePath(name, "png"));
    mime->setText(QString().sprintf("%d", id1));
    mime->setHtml(QString().sprintf("%d %d",getLocation().x, getLocation().y));
    drag->setHotSpot(QPoint(35, 35));
    drag->setMimeData(mime);
    drag->setPixmap(QPixmap::fromImage(image));
    drag->exec();
}

void card::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{

}

void card::reset()
{
    candrag = 0;
    setTime = t;
    QList<QGraphicsItem*> g = scene()->items(QPoint(shopLocationX, shopLocationY));
    shop* s = nullptr;
    Forr(i, 0, g.size()){
        object* tmp =qgraphicsitem_cast<object*>(g[i]);
        if (tmp->getId() == 41){
            s = qgraphicsitem_cast<shop*>(g[i]);
        }
    }
   assert(s != 0);
   s->addMoney(-money);
}

int card::s = 0;
