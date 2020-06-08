#include "player.h"

Player::Player(){

}

Player::~Player(){
    emit stop();
    emit crash();
}

/*void Player::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Left){
        if(x()>-40)
        setPos(x()-10,y());
    }
    if(event->key() == Qt::Key_Right){
        if(x()+80<800)
        setPos(x()+10,y());
    }
    if(event->key() == Qt::Key_Up){
        if(y()>0)
        setPos(x(),y()-10);
    }
    if(event->key() == Qt::Key_Down){
        if(y()+50<600)
        setPos(x(),y()+10);
    }
}*/

void Player::moveACC(int & xacc, int & yacc){
    if(yacc<-2000){
        if(x()>-40)
            setPos(x()-(abs(yacc)/1500),y());
    }
    if(yacc>2000){
        if(x()+80<800)
            setPos(x()+(yacc/1500),y());
    }
    if(xacc<-2000){
        if(y()>0)
            setPos(x(),y()-(abs(xacc)/1500));
    }
    if(xacc>2000){
        if(y()+50<600)
            setPos(x(),y()+(xacc/1500));
    }
}


