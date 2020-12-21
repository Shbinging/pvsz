#include "map.h"
#include"pzcreator.h"
#include<QGraphicsSceneDragDropEvent>
#include<QMimeData>
#include"timerUse.h"
#include"config.h"
#include"card.h"
#include<stdio.h>
#include"shovel.h"
#include<QList>
QList<int> l ={10, 11, 12, 13, 14, 16};
Map::Map(location a, int t):object(a,t)
{
    can = 1;
    setAcceptDrops(true);
}

QRectF Map::boundingRect() const
{
    return QRectF(-369, -235, 738, 470);
}

void Map::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if (!event->mimeData()->hasText()) return;
    QPointF pos = mapToScene(event->pos());
    location posl = getPlantLocation(pos.x(), pos.y());
    QString st = event->mimeData()->text();
    int id = st.toInt();
    //qDebug() << "require:" << posl.x << posl.y;
    can = 1;
    if (id > 0){
        if (isPlant(id) && (!isProtecter(id))){
            QList<QGraphicsItem*> g = scene()->items(QPoint(posl.x, posl.y));

            Forr(i, 0, g.size()) {
                object* tmp =qgraphicsitem_cast<object*> (g[i]);
               // qDebug()<< tmp->getId();
                if (isPlant(tmp->getId()) && !isProtecter(tmp->getId())) can = 0;
            }
        }
        else if (isPlant(id) && isProtecter(id)){
            QList<QGraphicsItem*> g = scene()->items(QPoint(posl.x, posl.y));
            Forr(i, 0, g.size()) {
                object* tmp =qgraphicsitem_cast<object*> (g[i]);
                if (isProtecter(tmp->getId())) can = 0;
            }
        }
    }

    if (can) event->accept();
    else event->ignore();
}

void Map::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    if (!event->mimeData()->hasText()) return;
    QPointF pos = mapToScene(event->pos());
    location posl = getPlantLocation(pos.x(), pos.y());
    QString st = event->mimeData()->text();
    int id = st.toInt();
    //qDebug() << "require:" << posl.x << posl.y;
    can = 1;
    if (id > 0){
        if (isPlant(id) && (!isProtecter(id))){
            QList<QGraphicsItem*> g = scene()->items(QPoint(posl.x, posl.y));

            Forr(i, 0, g.size()) {
                object* tmp =qgraphicsitem_cast<object*> (g[i]);
                //qDebug()<< tmp->getId();
                if (isPlant(tmp->getId()) && !isProtecter(tmp->getId())) can = 0;
            }
        }
        else if (isPlant(id) && isProtecter(id)){
            QList<QGraphicsItem*> g = scene()->items(QPoint(posl.x, posl.y));
            Forr(i, 0, g.size()) {
                object* tmp =qgraphicsitem_cast<object*> (g[i]);
                if (isProtecter(tmp->getId())) can = 0;
            }
        }
    }
    else{
        can = 0;
        QList<QGraphicsItem*> g = scene()->items(QPoint(posl.x, posl.y));
        Forr(i, 0, g.size()) {
            object* tmp =qgraphicsitem_cast<object*> (g[i]);
            if (isPlant(tmp->getId())) can = 1;
        }
    }
    if (can) event->accept();
    else event->ignore();
}

void Map::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    if (!event->mimeData()->hasText()) return;
    QPointF pos = mapToScene(event->pos());
    location posl = getPlantLocation(pos.x(), pos.y());
    QString st = event->mimeData()->text();
    QString st1 = event->mimeData()->html();
    int id = st.toInt();
    //qDebug()<<"prepare";
    if (id > 0){
        if (can){
            pzCreator a;
            //qDebug() << "plant:" << posl.x << posl.y;
            scene()->addItem(a.createObject(id, posl, t));
            int xx, yy;
            sscanf(st1.toStdString().c_str(), "%d%d", &xx, &yy);
            QList<QGraphicsItem*> g = scene()->items(QPoint(xx, yy));
            Forr(i, 0, g.size()){
                object* tmp =qgraphicsitem_cast<object*>(g[i]);
                if (tmp->getId() == 40){
                    card* tmp = qgraphicsitem_cast<card*>(g[i]);
                    tmp->reset();
                }
            }

        }
    }
    else{
        QList<QGraphicsItem*> g = scene()->items(QPoint(posl.x, posl.y));
        Forr(i, 0, g.size()) {
            object* tmp =qgraphicsitem_cast<object*> (g[i]);
            if (isPlant(tmp->getId())) tmp->setDead();
        }
        g = scene()->items(QPoint(830, 40));
        Forr(i, 0, g.size()) {
            object* tmp =qgraphicsitem_cast<object*> (g[i]);
            if (tmp->getId() == 43){
                shovel* tmp = qgraphicsitem_cast<shovel*> (g[i]);
                tmp->reset();
            }
        }
    }
    event->accept();
}

void Map::setCard()
{
    Forr(i, 0, l.size()){
        card* p = new card(location(375 + 65 * i, 45), 0, l[i]);
        scene()->addItem(p);
    }
}

