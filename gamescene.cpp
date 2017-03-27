#include "gamescene.h"
#include <QGraphicsView>
#include <QRectF>
#include <QPainter>
#include <QBrush>
#include <QPen>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsProxyWidget>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QFont>
#include "stars.h"
#include "score.h"

gameScene::gameScene(Opening* window) : QGraphicsScene(), parentWindow(window)
{
    this -> setSceneRect(0,0,400,600);
    this -> setBackgroundBrush(Qt::black);
    QPen yellow;
    yellow.setColor(Qt::yellow);
    yellow.setWidth(3);
   bottom_line = this -> addLine(0,450,400,450,yellow);

   score = new Score();
   this-> addItem(score);

   initial_rate = 1000;
   rate = new QTimer();
   connect(rate,SIGNAL(timeout()),SLOT(spawn_timer()));
   rate->start(3000);

   spawn_rate = new QTimer(this);
   connect(spawn_rate,SIGNAL(timeout()),SLOT(spawn()));
   spawn_rate->start(initial_rate);

}

void gameScene::spawn(){
    Star* star  = new Star(this);
    QGraphicsProxyWidget* star2 = this->addWidget(star);
    QObject* timesend = sender();
    QTimer* timersend = qobject_cast<QTimer*>(timesend);
    timersend -> setInterval(initial_rate);
}

void gameScene::spawn_timer(){
    initial_rate -= 10;
}


Opening* gameScene::get_parent(){
    return parentWindow;
}

void gameScene::stoptimers(){
    rate->stop();
    spawn_rate->stop();
}

Score* gameScene::get_score(){
    return score;
}
