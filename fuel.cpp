#include "fuel.h"

Fuel::Fuel(int size, int velocity)
{

    setPos(rand()%600,-50);
    setPixmap(QPixmap(":/images/oil.png").scaled(size,size));

    timer123 = new QTimer(this);
    connect(timer123,SIGNAL(timeout()),this,SLOT(move()));
    timer123->start(velocity);
}


void Fuel::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            emit collect();
            scene()->removeItem(this);
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

void Fuel::stopmove(){
    timer123->stop();
}

void Fuel::startmove(){
    timer123->start(40);
}
