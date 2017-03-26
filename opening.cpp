#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QThread>
#include <QGraphicsView>
#include "opening.h"
#include "gamescene.h"

Opening::Opening(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(400,600);                                 //Set size for intro screen window(also window for game) and background color
    QPalette background = palette();
    background.setColor(QPalette::Background, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(background);

    title = new QLabel("Starfall", this);                   //Create label for title, setting style and font
    title->setStyleSheet("QLabel {color : yellow; }");
    title -> setGeometry(100,10,250,200);
    QFont titleFont("Times", 60, QFont::Cursive, true);
    title -> setFont(titleFont);
    fade_in_effect(title,1000);

    start_button = new QPushButton("Start",this);           //Create pushbutton for start button, setting style and font
    QFont buttonFont("Times", 30, QFont::Cursive, true);
    start_button -> setFont(buttonFont);
    start_button -> setGeometry(100,200,160,70);
    style_button(start_button);
    fade_in_effect(start_button, 2000);
    connect(start_button, SIGNAL (released()), this, SLOT(handleStart()));

    info_button = new QPushButton("Info",this);             //Create PushButton for Info button, setting style and font
    info_button -> setGeometry(100,350,160,70);
    info_button -> setFont(buttonFont);
    style_button(info_button);
    fade_in_effect(info_button, 3000);
    connect(info_button, SIGNAL (released()), this, SLOT(handleInfo()));

    exit_button = new QPushButton("Exit", this);            //Create PushButton for Exit button, setting style and font
    exit_button -> setGeometry(100,500,160,70);
    exit_button->setFont(buttonFont);
    style_button(exit_button);
    fade_in_effect(exit_button, 4000);
    connect(exit_button, SIGNAL (released()), this, SLOT(handleExit()));

    back_button = new QPushButton("Back",this);             //Create PushButton for Back button on info page, setting style and font
    back_button -> setGeometry(100,500,160,70);
    back_button -> setFont(buttonFont);
    style_button(back_button);
    back_button -> setVisible(false);
    connect(back_button, SIGNAL (released()), this, SLOT(handleBack()));

    description = new QLabel("Hello,welcome to Starfall. \n"                        //Create Label for description/how to play game on info page
                             "Click all the stars before they hit the bottom! \n"
                             "But be careful, dont click other objects!", this);
    description->setStyleSheet("QLabel {color : yellow; }");
    description -> setGeometry(20,10,400,400);
    QFont paragraphFont("Times", 20, QFont::Cursive, true);
    description -> setFont(paragraphFont);
    description ->setVisible(false);

}

void Opening::handleStart(){

    fade_out_effect(title, 1000);
    fade_out_effect(start_button, 1000);
    fade_out_effect(info_button, 1000);
    fade_out_effect(exit_button, 1000);
    delay();
    hide_all();
    game_scene = new gameScene(this);
    game_view = new QGraphicsView(this);
    game_view->setScene(game_scene);
    this -> setCentralWidget(game_view);

}

void Opening::handleInfo(){
    fade_out_effect(title, 1000);
    fade_out_effect(start_button, 1000);
    fade_out_effect(info_button, 1000);
    fade_out_effect(exit_button, 1000);

    fade_in_effect(description, 1000);
    fade_in_effect(back_button,2000);
    back_button -> setVisible(true);
    description -> setVisible(true);
}

void Opening::handleExit(){
    this->close();
}

void Opening::handleBack(){

    fade_out_effect(description, 1000);
    fade_out_effect(back_button, 1000);
    fade_in_effect(title,1000);
    fade_in_effect(start_button,2000);
    fade_in_effect(info_button,3000);
    fade_in_effect(exit_button,4000);
    delay();
    description -> setVisible(false);
    back_button -> setVisible(false);

}

void Opening::fade_in_effect(QWidget *w, int duration){
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *ani = new QPropertyAnimation(eff,"opacity");
    ani->setDuration(duration);
    ani->setStartValue(0);
    ani->setEndValue(1);
    ani->setEasingCurve(QEasingCurve::InBack);
    ani->start(QPropertyAnimation::DeleteWhenStopped);
    w -> setGraphicsEffect(eff);
}

void Opening::fade_out_effect(QWidget *w, int duration){
    QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *ani = new QPropertyAnimation(eff,"opacity");
    ani->setDuration(duration);
    ani->setStartValue(1);
    ani->setEndValue(0);
    ani->setEasingCurve(QEasingCurve::OutBack);
    ani->start(QPropertyAnimation::DeleteWhenStopped);
    w -> setGraphicsEffect(eff);
}

void Opening::hide_all(){
    title ->setVisible(false);
    start_button ->setVisible(false);
    info_button -> setVisible(false);
    exit_button -> setVisible(false);
}

void Opening::show_all(){
    fade_in_effect(title, 1000);
    fade_in_effect(start_button, 2000);
    fade_in_effect(info_button, 3000);
    fade_in_effect(exit_button, 4000);
    title ->setVisible(true);
    start_button ->setVisible(true);
    info_button -> setVisible(true);
    exit_button -> setVisible(true);
}

void Opening::delay(){
    QTime endTime= QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < endTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Opening::style_button(QPushButton* w){
    w -> setStyleSheet("background-color: black;"
            "border-style: outset;"
            "border-width: 2px;"
            "border-radius: 10px;"
            "border-color: yellow;"
            "color: yellow;"
            "min-width: 10em;"
            "padding: 6px;");
}

void Opening::reset(){
    this->setCentralWidget(0);
    this->show_all();
}

QGraphicsView* Opening::get_view(){
    return game_view;
}
