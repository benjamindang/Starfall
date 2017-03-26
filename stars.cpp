#include "stars.h"
#include <QGraphicsScene>
#include <QTimer>
#include <stdlib.h>
#include <QtAlgorithms>
#include "gamescene.h"

Star::Star(QGraphicsScene* scene):QPushButton(), parentscene(scene){
    int randomX = (rand() % 399) + 1;
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
        if(!(this->isVisible()))
            delete this;
        else{
            parentscene ->clear();
            qDeleteAll(parentscene->items());
            delete parentscene;
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

