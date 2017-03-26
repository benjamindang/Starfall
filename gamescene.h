#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsLineItem>
#include "stars.h"
#include "opening.h"
#include <vector>

class Opening;
class Star;

class gameScene : public QGraphicsScene
{
    Q_OBJECT
public:
     gameScene(Opening* window = 0);
public slots:
     void spawn();
     void spawn_timer();
     Opening* get_parent();
     void stoptimers();
private:
     int initial_rate;
     Opening* parentWindow;
     QTimer* rate;
     QTimer* spawn_rate;
     QGraphicsLineItem* bottom_line;
};

#endif // GAMESCENE_H
