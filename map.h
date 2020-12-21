#ifndef MAP_H
#define MAP_H
#include<QDragEnterEvent>
#include<QDropEvent>
#include<object.h>
class Map : public object
{
public:
    bool can;
    Map(location a, int t);
    QRectF boundingRect() const override;
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event) override;
    void dragMoveEvent(QGraphicsSceneDragDropEvent *event) override;
    void dropEvent(QGraphicsSceneDragDropEvent *event) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){}
    void setCard();
};

#endif // MAP_H11
