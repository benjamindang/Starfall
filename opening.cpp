#include "opening.h"

Opening::Opening(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(400,600);
    title = new QLabel("Baloons!", this);
    title -> setGeometry(165,50,60,20);
    start_button = new QPushButton("Start",this);
    start_button -> setGeometry(165,150,60,20);
    info_button = new QPushButton("Info",this);
    info_button -> setGeometry(165,300,60,20);
    exit_button = new QPushButton("Exit", this);
    exit_button -> setGeometry(165,450,60,20);


}
