#ifndef FUEL_H
#define FUEL_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QGraphicsScene>
#include <player.h>

class Fuel: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Fuel(int size, int velocity);
signals:
    void collect();
public slots:
    void move();
    void stopmove();
    void startmove();
private:
    QTimer * timer123;
};

#endif // FUEL_H
