#include "gamescene.h"
#include <QGraphicsView>
#include <QBrush>
#include <QPen>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QGraphicsProxyWidget>
#include <QGraphicsTextItem>
#include <QTimer>
#include <QFont>
#include "stars.h"
#include "score.h"
#include "player.h"

gameScene::gameScene(Opening* window) : QGraphicsScene(), parentWindow(window)
{
    this -> setSceneRect(0,0,400,600);
    this -> setBackgroundBrush(Qt::black);

    play = new Player();
    this->addItem(play);

   score = new Score();
   this-> addItem(score);

   initial_rate = 500;
   rate = new QTimer();
   connect(rate,SIGNAL(timeout()),SLOT(spawn_timer()));
   rate->start(1000);

   spawn_rate = new QTimer(this);
   connect(spawn_rate,SIGNAL(timeout()),SLOT(spawn()));
   spawn_rate->start(initial_rate);
   play->setFocus();

}

void gameScene::spawn(){
    Star* star  = new Star(this);
    this->addItem(star);
    QObject* timesend = sender();
    QTimer* timersend = qobject_cast<QTimer*>(timesend);
    timersend -> setInterval(initial_rate);
    play->setFocus();
}

void gameScene::spawn_timer(){
    if(initial_rate > 100)
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

Player* gameScene::get_player(){
    return play;
}
