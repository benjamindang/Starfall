#ifndef STARS_H
#define STARS_H

#include<QGraphicsItem>
#include<QGraphicsPixmapItem>
#include "gamescene.h"

class gameScene;

class Star :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Star(gameScene* scene,QGraphicsItem* parent = 0);
public slots:
    void move();
private:
    gameScene* parentscene;
};

#endif // STARS_H
