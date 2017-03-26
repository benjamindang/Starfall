#ifndef STARS_H
#define STARS_H

#include<QPushButton>
#include<QGraphicsScene>
#include<QObject>
#include<QMainWindow>

class Star :public QPushButton
{
    Q_OBJECT
public:
    Star(QMainWindow* parent = 0);
    void style_button();
public slots:
    void move();
    void clickedOn();
};

#endif // STARS_H
