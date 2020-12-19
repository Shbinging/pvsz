#include "mainwindow.h"
#include"config.h"
#include"zombie.h"
#include"object.h"
#include"timerUse.h"
#include<QTimer>
#include "plant.h"
#include"bullet.h"
#include<QList>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QTimer* timer = new QTimer;
    this->setFixedSize(windowWidth, windowHeight);
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, windowWidth, windowHeight);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    zombieBasic* a = new zombieBasic(location(windowWidth - 50, 130 + 98), 0);
    plantWandou* b = new plantWandou(location(windowWidth -400, 130+98), 0);
    //bullet * c = new bullet(location(windowWidth - 400, 130 + 98), 0);
    //a->setMovie(":/images/ZombieWalk2.gif");
    //a->setMovieSpeed(500);
    scene->addItem(a);
    scene->addItem(b);
    //scene->addItem(c);
    view = new QGraphicsView(scene, this);
    view->resize(windowWidth + 2,windowHeight + 2);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    QPixmap backPic(":/images/Background.jpg");
    view->setBackgroundBrush(backPic);
    view->show();
    //connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    connect(timer, &QTimer::timeout, this, [&]{
        t++;
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

