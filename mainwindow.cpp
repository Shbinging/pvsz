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
#include"logo.h"
#include"pzcreator.h"
#include"button.h"
#include <QSound>
#include <QMediaPlaylist>
#include <QMediaPlayer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    timer = new QTimer;
    this->setFixedSize(windowWidth, windowHeight);
    //this->setMinimumSize(windowWidth, windowHeight);
    QMediaPlayer* player = new QMediaPlayer;
    //connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    QMediaPlaylist *playlist = new QMediaPlaylist;
    playlist->setCurrentIndex(1);
    playlist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    playlist->addMedia(QUrl::fromLocalFile("E:\\Documents\\sophomore\\qt\\pvszView\\Grazy Dave.mp3"));
    player->setPlaylist(playlist);
    player->setVolume(30);
    player->play();
    //QSound sound(":/Grazy Dave.wav");
    //sound.setLoops(QSound::Infinite);
    //sound.play();
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
    Button *button = new Button(timer);
    button->setPos(970, 20);
    scene->addItem(button);
    scene->advance();
    view = new QGraphicsView(scene, this);
    view->resize(windowWidth + 2,windowHeight + 2);
    view->setRenderHint(QPainter::Antialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    QPixmap backPic(":/images/Background.jpg");
    view->setBackgroundBrush(backPic);
    view->show();
    //connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    interval = 200;
    tt = 200;
    connect(timer, &QTimer::timeout, this, [&]{
        t++;
        qDebug()<< t << " "<<tt;
        if (t ==  tt){
           // qDebug()<< t;
            pzCreator p;
            object* q = p.createObject(t % 4 + 20, location(windowWidth, 130 + (rand() % 5) * 98), 0);
            qDebug()<<q->getId();
            interval /= 1.07;
            tt += interval;
            //zombieBasic* b = new zombieBasic(location(windowWidth, 130 + (t % 5) * 98), 0);
            scene->addItem(q);
            //scene->addItem(b);
        }
        if (t%200 == 0){
            sun* c = new sun(location(t % windowWidth + 50, 0),0);
            c->setMove();
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
   connect(timer, &QTimer::timeout, this, &MainWindow::checkLose);
}

MainWindow::~MainWindow()
{
    delete scene;
    delete view;
}

void MainWindow::checkLose()
{
    bool isLose = 0;
    QList<QGraphicsItem*> li = scene->items();
    Forr(i, 0, li.size()){
        object* tmp = qgraphicsitem_cast<object*>(li[i]);
        if (tmp->getLocation().x < 150 && isZombie(tmp->getId())){
            //timer->stop();
            isLose = 1;
            qDebug()<<"lose";
        }
    }
    if (isLose || t >= tt){
        bool f = 0;
        Forr(i, 0, li.size()){
            object* tmp = qgraphicsitem_cast<object*>(li[i]);
            if (isZombie(tmp->getId()) && !isLose){
                f = 1;
                break;
            }
            }
        if (!f){
        if (isLose){
            logoWin* h = new logoWin(location(300, 100));
            scene->addItem(h);
        }
        else{
            logoLose* p = new logoLose(location(530, 200));
            scene->addItem(p);
        }
        timer->stop();
        }
    }
}

