#include "object.h"
#include <QPainter>
#include<QDebug>
object::object(location a, int t){
    setLocation(a);
    setTime = t;
    setLive();
    head = nullptr;
    movie = nullptr;
    oripath1 = "";
    oripath2 = "";
}
int object::getId(){return id;}
location object::getLocation(){
    return location(xx, yy);
}
void object::setLocation(location a){
    xx = a.x;
    yy = a.y;
    this->setPos(xx, yy);
}
void object::setAttack(int x){
    attack = x;
}
int object::getAttack(){
    return attack;
}
void object::setSpeed(int x){
    speed = x;
}
int object::getSpeed(){
    return speed;
}
void object::setHeart(int x){
    heart = x;
}
void object::subHeart(int x){
    heart -= x;
}
int object::getHeart() { return heart; }
QString object::getName(){return name;}
int object::getType() const{return ttype;}

void object::setType(int x)
{
    ttype = x;
}

bool object::isDead(){
    return heart <= 0 || (!live);
}
void object::setDead(){
    live = 0;
    scene()->removeItem(this);
}
void object::setLive(){
    live = 1;
}
object::object(){
    setLive();
}

void object::setMovie(QString path)
{
    if (oripath1 == path) return;
    oripath1 = path;
    if (!movie){
        delete movie;
    }
    movieOver = 0;
    movie = new QMovie(path);
    movie->start();
}

void object::setHead(QString path)
{
    if (oripath2 == path) return;
    oripath2 = path;
    if (!head){
        delete head;
    }
    headOver = 0;
    head = new QMovie(path);
    head->start();
}

void object::setMovieSpeed(int speed)
{
    if (movie) movie->setSpeed(speed);
    if (head) head->setSpeed(speed);
}

bool object::isMovieOver()
{
    if (movie->frameCount() - 1 == movie->currentFrameNumber()){
        movieOver = 1;
    }
    else movieOver = 0;
    return movieOver;
}

bool object::isHeadOver()
{
    if (head->frameCount() - 1 == head->currentFrameNumber()){
        headOver = 1;
    }
    else headOver = 0;
    return headOver;
}

object::~object()
{
    if (movie) delete movie;
    if (head) delete head;
}
