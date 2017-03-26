#ifndef STARS_H
#define STARS_H

#include<QPushButton>
#include<QGraphicsScene>
#include<QObject>
#include<QMainWindow>
#include "gamescene.h"

class Star :public QPushButton
{
    Q_OBJECT
public:
    Star(QGraphicsScene* scene);
    void style_button();
public slots:
    void move();
    void clickedOn();
private:
    QGraphicsScene* parentscene;
};

#endif // STARS_H
