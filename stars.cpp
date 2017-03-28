#include "stars.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <ctime>
#include <stdlib.h>
#include <QGraphicsProxyWidget>
#include "gamescene.h"

Star::Star(gameScene* scene,QGraphicsItem* parent):QObject(),QGraphicsPixmapItem(parent), parentscene(scene){
    int randomX = (rand() % 391) + 5;
    QPixmap star(":/Pictures/Star.png");
    star = star.scaled(30,30,Qt::IgnoreAspectRatio,Qt::FastTransformation);
    this->setPixmap(star);

    this->setX(randomX);
    this->setY(0);

    QTimer* time = new QTimer(this);
    connect(time,SIGNAL(timeout()),this,SLOT(move()));
    time ->start(1);

}

void Star::move(){
    this->setY(y() + 3);
    QList<QGraphicsItem*> colliding_items = collidingItems();
    if(colliding_items.size() >= 1){
        parentscene -> get_parent() -> reset();
        parentscene -> stoptimers();
        parentscene -> clear();
    }
    else if(pos().y() > 448){
        parentscene->get_score()->add();
        delete this;
    }
}

