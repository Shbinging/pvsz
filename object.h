#ifndef OBJECT_H
#define OBJECT_H
#include<QGraphicsItem>
#include<QGraphicsScene>
#include<QString>
#include<QObject>
#include<QMovie>
struct location{
    int x, y;
    location();
    location(int xx, int yy){
        x = xx;
        y = yy;
    }
};

class object:public QObject, public QGraphicsItem
{
    Q_OBJECT
protected:
    int id;
    QString name;
    int ttype;//1 plant 2 sun 3 zombie
    int xx, yy;
    int setTime;
    bool live;
    int heart, mxheart;
    int attack;
    int speed;

    QMovie* movie;
    QMovie* head;
    bool movieOver;
    bool headOver;
    enum { Tyype = UserType + 1 };
    int type() const override
    {
        // Enable the use of qgraphicsitem_cast with this item.
        return Tyype;
    }
    QString oripath1, oripath2;
public:
    void setMovie(QString path);
    void setHead(QString path);
    void setMovieSpeed(int speed);
    bool isMovieOver();
    bool isHeadOver();
    object(location a, int t);
    int getId();
    location getLocation();
    void setLocation(location a);
    void setAttack(int x);
    int getAttack();
    void setSpeed(int x);
    int getSpeed();
    void setHeart(int x);
    void subHeart(int x);
    int getHeart();
    QString getName();
    int getType() const;
    void setType(int x);
    bool isDead();
    virtual void setDead();
    void setLive();
    object();
    ~object();
};

#endif // OBJECT_H
