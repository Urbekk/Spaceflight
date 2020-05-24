#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QGraphicsScene>


class Player: public QObject, public QGraphicsPixmapItem{
        Q_OBJECT
public:
    Player();
    ~Player();
    void keyPressEvent(QKeyEvent * event);
    void moveACC(int x, int y, int z);
signals:
void stop();
void crash();
public slots:


};

#endif // MYRECT_H
