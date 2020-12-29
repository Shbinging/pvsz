#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    int interval, tt;
    QGraphicsScene* scene;
    QGraphicsView * view;
    void checkLose();
    QTimer*  timer;
};
#endif // MAINWINDOW_H
