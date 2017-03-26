#include "gamescene.h"
#include <QGraphicsView>
#include <QRectF>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QTimer>
#include "stars.h"

gameScene::gameScene(QWidget* parentWidget) : QGraphicsScene(parentWidget)
{
    this -> setSceneRect(0,0,400,600);
    this -> setBackgroundBrush(Qt::black);
    QPen test;
    test.setColor(Qt::yellow);
    test.setWidth(3);
   QGraphicsLineItem* bottom_line = this -> addLine(0,450,400,450,test);

   QTimer* timer = new QTimer();
   connect(timer,SIGNAL(timeout()),SLOT(spawn()));
   timer->start(2000);
}

void gameScene::spawn(){
    Star* star  = new Star();
    this ->addWidget(star);
}
