#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <player.h>

class Asteroid: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Asteroid(int size, int velocity);
private:
    QTimer * timer;
public slots:
    void move();
    void stopmove();
    void startmove();
signals:


};

#endif // ENEMY_H
