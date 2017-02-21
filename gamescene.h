#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>


class gameScene : public QGraphicsScene
{
    Q_OBJECT
public:
    gameScene(QWidget* parentWidget = 0);
};

#endif // GAMESCENE_H
