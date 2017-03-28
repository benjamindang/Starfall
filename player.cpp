#include "player.h"
#include <QGraphicsScene>
#include <QPixmap>
#include <QKeyEvent>

#include <QDebug>

Player::Player(QGraphicsItem* parent) : QObject(), QGraphicsPixmapItem(parent)
{
    this -> setFlag(QGraphicsItem::ItemIsFocusable);
    QPixmap spaceship(":/Pictures/SpaceShip.png");
    spaceship = spaceship.scaled(50,50,Qt::IgnoreAspectRatio,Qt::FastTransformation);
    this->setPixmap(spaceship);

    this->setX(200);
    this->setY(300);
}

void Player::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_W){
        setPos(x(),y() - 20);
    }
    else if(event->key() == Qt::Key_S){
        if(y() >= 400)
            return;
        else
            setPos(x(),y() + 20);
    }
    else if(event->key() == Qt::Key_D){
        setPos(x() + 20,y());
    }
    else if(event->key() == Qt::Key_A){
        setPos(x() - 20,y());
    }
}
