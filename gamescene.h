#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include<stars.h>


class gameScene : public QGraphicsScene
{
    Q_OBJECT
public:
     gameScene(QWidget* parentWidget = 0);
public slots:
     void spawn();
};

#endif // GAMESCENE_H
