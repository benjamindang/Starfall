#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsLineItem>
#include "stars.h"
#include "opening.h"
#include "score.h"
#include "player.h"

class Opening;
class Star;
class Score;

class gameScene : public QGraphicsScene
{
    Q_OBJECT
public:
     gameScene(Opening* window = 0);
public slots:
     void spawn();
     void spawn_timer();
     Opening* get_parent();
     Score* get_score();
     Player* get_player();
     void stoptimers();
private:
     int points;
     int initial_rate;
     Opening* parentWindow;
     QTimer* rate;
     QTimer* spawn_rate;
     QGraphicsLineItem* bottom_line;
     Score* score;
     Player* play;
};

#endif // GAMESCENE_H
