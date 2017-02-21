#include "gamescene.h"
#include <QGraphicsView>

gameScene::gameScene(QWidget* parentWidget) : QGraphicsScene(parentWidget)
{
    this -> setBackgroundBrush(Qt::black);
}
