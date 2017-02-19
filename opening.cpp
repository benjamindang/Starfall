#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include "opening.h"

Opening::Opening(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(400,600);
    QPalette background = palette();
    background.setColor(QPalette::Background, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(background);

    title = new QLabel("Starfall", this);
    title->setStyleSheet("QLabel {color : yellow; }");
    title -> setGeometry(110,10,250,200);
    QFont newFont("Times", 60, QFont::Cursive, true);
    title -> setFont(newFont);

    start_button = new QPushButton("Start",this);
    start_button -> setGeometry(100,200,160,70);
    start_button -> setStyleSheet("background-color: white;"
            "border-style: outset;"
            "border-width: 2px;"
            "border-radius: 10px;"
            "border-color: black;"
            "font: bold 14px;"
            "min-width: 10em;"
            "padding: 6px;");
    connect(start_button, SIGNAL (released()), this, SLOT(handleStart()));

    info_button = new QPushButton("Info",this);
    info_button -> setGeometry(100,350,160,70);
    info_button -> setStyleSheet("background-color: white;"
            "border-style: outset;"
            "border-width: 2px;"
            "border-radius: 10px;"
            "border-color: black;"
            "font: bold 14px;"
            "min-width: 10em;"
            "padding: 6px;");
    connect(info_button, SIGNAL (released()), this, SLOT(handleInfo()));


    exit_button = new QPushButton("Exit", this);
    exit_button -> setGeometry(100,500,160,70);
    exit_button -> setStyleSheet("background-color: white;"
            "border-style: outset;"
            "border-width: 2px;"
            "border-radius: 10px;"
            "border-color: black;"
            "font: bold 14px;"
            "min-width: 10em;"
            "padding: 6px;");
    connect(exit_button, SIGNAL (released()), this, SLOT(handleExit()));

    back_button = new QPushButton("Back",this);
    back_button -> setGeometry(100,500,160,70);
    back_button -> setStyleSheet("background-color: white;"
            "border-style: outset;"
            "border-width: 2px;"
            "border-radius: 10px;"
            "border-color: black;"
            "font: bold 14px;"
            "min-width: 10em;"
            "padding: 6px;");
    back_button -> setVisible(false);
    connect(back_button, SIGNAL (released()), this, SLOT(handleBack()));

}

void Opening::handleStart(){
    start_button -> setVisible(false);
    info_button -> setVisible(false);
    exit_button -> setVisible(false);
    title -> setVisible(false);
}

void Opening::handleInfo(){
    start_button -> setVisible(false);
    info_button -> setVisible(false);
    exit_button -> setVisible(false);
    title -> setVisible(false);
    back_button -> setVisible(true);
}

void Opening::handleExit(){
    this->close();
}

void Opening::handleBack(){
    start_button -> setVisible(true);
    info_button -> setVisible(true);
    exit_button -> setVisible(true);
    title -> setVisible(true);
    back_button ->setVisible(false);
}
