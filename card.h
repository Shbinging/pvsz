#ifndef CARD_H
#define CARD_H
#include"object.h"
#include<QString>
class card: public object
{
public:
    static int s;
    card(location a, int t, int _id);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void advance(int phase) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void reset();
    int id1;
private:
    bool candrag;

    int coldTime;
    int money;
};

#endif // CARD_H
