#include "mainwindow.h"
#include"config.h"
#include"zombie.h"
#include"object.h"
#include"timerUse.h"
#include<QTimer>
#include "plant.h"
#include "bullet.h"
#include "shop.h"
#include "card.h"
#include "map.h"
#include "shovel.h"
#include<QList>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QTimer* timer = new QTimer;
    this->setFixedSize(windowWidth, windowHeight);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(150, 0, windowWidth, windowHeight);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    zombieBasic* a = new zombieBasic(location(windowWidth - 50, 130 + 98), 0);
    zombieBasic* a1 = new zombieBasic(location(windowWidth + 100, 130 + 98), 0);
    car* b = new car(location(windowWidth -100, 130+98), 0);
    sun* c = new sun(location(windowWidth -400, 0),0);
    shop* d = new shop(location(520, 45), 0);
    card* e =  new card(location(windowWidth - 50, 130), 0, 11);
    sun* f = new sun(location(windowWidth -400, 0),0);
    shovel* g = new shovel(location(830, 40), 0);
    c->setMove();
    f->setMove();
    //bullet * c = new bullet(location(windowWidth - 400, 130 + 98), 0);
    //a->setMovie(":/images/ZombieWalk2.gif");
    //a->setMovieSpeed(500);
    //scene->addItem(a1);
    //scene->addItem(a);
    //scene->addItem(b);
    scene->addItem(d);
    scene->addItem(f);
    scene->addItem(g);
    For(i, 0, 4){
        car* p = new car(location(210, 130 + 98 * i), 0);
        scene->addItem(p);
    }
    Map *map = new Map(location(618,326), 0);
    scene->addItem(map);
    map->setCard();
    view = new QGraphicsView(scene, this);
    view->resize(windowWidth + 2,windowHeight + 2);
    view->setRenderHint(QPainter::Antialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    QPixmap backPic(":/images/Background.jpg");
    view->setBackgroundBrush(backPic);
    view->show();
    //connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    connect(timer, &QTimer::timeout, this, [&]{
        t++;
        if (t % 137 == 0){
            zombieBasic* a = new zombieBasic(location(windowWidth - 50, 130 + (t % 5) * 98), 0);
            sun* c = new sun(location(t % windowWidth + 50, 0),0);
            c->setMove();
            scene->addItem(a);
            scene->addItem(c);
        }
        //qDebug()<<t;
        /*
        QList<QGraphicsItem*> li = scene->items();
        Forr(i, 0, li.size()){
            object* tmp = qgraphicsitem_cast<object*>(li[i]);
            if (tmp->isDead()){
                scene->removeItem(li[i]);
                delete li[i];
            }
        }*/
        //scene->advance();
    });
   connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    timer->start(50);
}

MainWindow::~MainWindow()
{
    delete scene;
    delete view;
}

