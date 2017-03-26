#include "stars.h"
#include <QGraphicsScene>
#include <QTimer>
#include <ctime>
#include <stdlib.h>
#include <QGraphicsProxyWidget>
#include "gamescene.h"

Star::Star(gameScene* scene):QPushButton(), parentscene(scene){
    int randomX = (rand() % 391) + 5;
    this -> style_button();

    this->setGeometry(randomX,0,10,10);

    connect(this,SIGNAL(pressed()),this,SLOT(clickedOn()));

    QTimer* time = new QTimer(this);
    connect(time,SIGNAL(timeout()),this,SLOT(move()));
    time ->start(1);

}

void Star::move(){
    this->setGeometry(x(),y() + 1,10,10);
    if(pos().y() + rect().height() > 448){
        if(!(this->isVisible())){
            this->setVisible(false);
            delete this;
        }
        else{
            parentscene -> get_parent() -> reset();
            parentscene -> stoptimers();
            parentscene -> clear();
        }
    }
}

void Star::clickedOn(){
    this->setVisible(false);
}

void Star::style_button(){
    this -> setStyleSheet("background-color: yellow;"
            "min-width: 0em;"
            "min-height: 0em;"
            "border-color: yellow;"
            "border-style: outset;"
            "border-width: 2px;"
                          );
}

