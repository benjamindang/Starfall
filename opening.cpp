#include "opening.h"

Opening::Opening(QWidget *parent) : QMainWindow(parent)
{
    QFont newFont("Cambria", 33, QFont::Bold, true);
    setFixedSize(400,600);
    title = new QLabel("Baloons!", this);
    title -> setGeometry(125,50,160,70);
    title -> setFont(newFont);
    start_button = new QPushButton("Start",this);
    start_button -> setGeometry(115,200,160,70);
    info_button = new QPushButton("Info",this);
    info_button -> setGeometry(115,350,160,70);
    exit_button = new QPushButton("Exit", this);
    exit_button -> setGeometry(115,500,160,70);
}
