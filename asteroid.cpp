#include "asteroid.h"

Asteroid::Asteroid(int size, int velocity)
{
    setPos(rand()%600,-30);
    setPixmap(QPixmap(":/images/asteroida1.png").scaled(size,size));

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(velocity);
}

void Asteroid::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    setPos(x(),y()+3);
    if (pos().y() > 600){
        scene()->removeItem(this);
        delete this;
    }
}

void Asteroid::stopmove(){
    timer->stop();
}

void Asteroid::startmove(){
    timer->start(40);
}
