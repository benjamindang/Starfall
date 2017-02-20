#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include "opening.h"

Opening::Opening(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(400,600);
    QPalette background = palette();
    background.setColor(QPalette::Background, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(background);

    QGraphicsOpacityEffect *title_eff = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *title_ani = new QPropertyAnimation(title_eff,"opacity");
    title_ani->setDuration(1000);
    title_ani->setStartValue(0);
    title_ani->setEndValue(1);
    title_ani->setEasingCurve(QEasingCurve::InBack);
    title_ani->start(QPropertyAnimation::DeleteWhenStopped);

    title = new QLabel("Starfall", this);
    title->setStyleSheet("QLabel {color : yellow; }");
    title -> setGeometry(100,10,250,200);
    QFont titleFont("Times", 60, QFont::Cursive, true);
    title -> setFont(titleFont);
    title->setGraphicsEffect(title_eff);

    QGraphicsOpacityEffect *start_eff = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *start_ani = new QPropertyAnimation(start_eff,"opacity");
    start_ani->setDuration(2000);
    start_ani->setStartValue(0);
    start_ani->setEndValue(1);
    start_ani->setEasingCurve(QEasingCurve::InBack);
    start_ani->start(QPropertyAnimation::DeleteWhenStopped);

    start_button = new QPushButton("Start",this);
    QFont buttonFont("Times", 30, QFont::Cursive, true);
    start_button -> setFont(buttonFont);
    start_button -> setGeometry(100,200,160,70);
    start_button -> setStyleSheet("background-color: black;"
            "border-style: outset;"
            "border-width: 2px;"
            "border-radius: 10px;"
            "border-color: yellow;"
            "color: yellow;"
            "min-width: 10em;"
            "padding: 6px;");
    start_button -> setGraphicsEffect(start_eff);
    connect(start_button, SIGNAL (released()), this, SLOT(handleStart()));

    QGraphicsOpacityEffect *info_eff = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *info_ani = new QPropertyAnimation(info_eff,"opacity");
    info_ani->setDuration(3000);
    info_ani->setStartValue(0);
    info_ani->setEndValue(1);
    info_ani->setEasingCurve(QEasingCurve::InBack);
    info_ani->start(QPropertyAnimation::DeleteWhenStopped);

    info_button = new QPushButton("Info",this);
    info_button -> setGeometry(100,350,160,70);
    info_button -> setFont(buttonFont);
    info_button -> setStyleSheet("background-color: black;"
            "border-style: outset;"
            "border-width: 2px;"
            "border-radius: 10px;"
            "border-color: yellow;"
            "color: yellow;"
            "min-width: 10em;"
            "padding: 6px;");
    info_button -> setGraphicsEffect(info_eff);
    connect(info_button, SIGNAL (released()), this, SLOT(handleInfo()));

    QGraphicsOpacityEffect *exit_eff = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *exit_ani = new QPropertyAnimation(exit_eff,"opacity");
    exit_ani->setDuration(4000);
    exit_ani->setStartValue(0);
    exit_ani->setEndValue(1);
    exit_ani->setEasingCurve(QEasingCurve::InBack);
    exit_ani->start(QPropertyAnimation::DeleteWhenStopped);

    exit_button = new QPushButton("Exit", this);
    exit_button -> setGeometry(100,500,160,70);
    exit_button->setFont(buttonFont);
    exit_button -> setStyleSheet("background-color: black;"
            "border-style: outset;"
            "border-width: 2px;"
            "border-radius: 10px;"
            "border-color: yellow;"
            "color: yellow;"
            "min-width: 10em;"
            "padding: 6px;");
    exit_button -> setGraphicsEffect(exit_eff);
    connect(exit_button, SIGNAL (released()), this, SLOT(handleExit()));

    back_button = new QPushButton("Back",this);
    back_button -> setGeometry(100,500,160,70);
    back_button -> setFont(buttonFont);
    back_button -> setStyleSheet("background-color: black;"
            "border-style: outset;"
            "border-width: 2px;"
            "border-radius: 10px;"
            "border-color: yellow;"
            "color: yellow;"
            "min-width: 10em;"
            "padding: 6px;");
    back_button -> setVisible(false);
    connect(back_button, SIGNAL (released()), this, SLOT(handleBack()));

    description = new QLabel("Hello,welcome to Starfall. \n"
                             "Click all the stars before they hit the bottom! \n"
                             "But be careful, dont click other objects!", this);
    description->setStyleSheet("QLabel {color : yellow; }");
    description -> setGeometry(20,10,400,400);
    QFont paragraphFont("Times", 20, QFont::Cursive, true);

    description -> setFont(paragraphFont);
    description ->setVisible(false);

}

void Opening::handleStart(){
    QGraphicsOpacityEffect *title_fade = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *title_ani_fade = new QPropertyAnimation(title_fade,"opacity");
    title_ani_fade->setDuration(1000);
    title_ani_fade->setStartValue(1);
    title_ani_fade->setEndValue(0);
    title_ani_fade->setEasingCurve(QEasingCurve::OutBack);
    title_ani_fade->start(QPropertyAnimation::DeleteWhenStopped);

    QGraphicsOpacityEffect *start_fade = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *start_fade_ani = new QPropertyAnimation(start_fade,"opacity");
    start_fade_ani->setDuration(1000);
    start_fade_ani->setStartValue(1);
    start_fade_ani->setEndValue(0);
    start_fade_ani->setEasingCurve(QEasingCurve::OutBack);
    start_fade_ani->start(QPropertyAnimation::DeleteWhenStopped);

    QGraphicsOpacityEffect *info_fade = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *info_fade_ani = new QPropertyAnimation(info_fade,"opacity");
    info_fade_ani->setDuration(1000);
    info_fade_ani->setStartValue(1);
    info_fade_ani->setEndValue(0);
    info_fade_ani->setEasingCurve(QEasingCurve::OutBack);
    info_fade_ani->start(QPropertyAnimation::DeleteWhenStopped);

    QGraphicsOpacityEffect *exit_fade = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *exit_fade_ani = new QPropertyAnimation(exit_fade,"opacity");
    exit_fade_ani->setDuration(1000);
    exit_fade_ani->setStartValue(1);
    exit_fade_ani->setEndValue(0);
    exit_fade_ani->setEasingCurve(QEasingCurve::OutBack);
    exit_fade_ani->start(QPropertyAnimation::DeleteWhenStopped);


    title -> setGraphicsEffect(title_fade);
    start_button -> setGraphicsEffect(start_fade);
    info_button -> setGraphicsEffect(info_fade);
    exit_button -> setGraphicsEffect(exit_fade);

    title ->setVisible(false);
    start_button ->setVisible(false);
    info_button -> setVisible(false);
    exit_button -> setVisible(false);
}

void Opening::handleInfo(){
    QGraphicsOpacityEffect *title_fade = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *title_ani_fade = new QPropertyAnimation(title_fade,"opacity");
    title_ani_fade->setDuration(1000);
    title_ani_fade->setStartValue(1);
    title_ani_fade->setEndValue(0);
    title_ani_fade->setEasingCurve(QEasingCurve::OutBack);
    title_ani_fade->start(QPropertyAnimation::DeleteWhenStopped);

    QGraphicsOpacityEffect *start_fade = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *start_fade_ani = new QPropertyAnimation(start_fade,"opacity");
    start_fade_ani->setDuration(1000);
    start_fade_ani->setStartValue(1);
    start_fade_ani->setEndValue(0);
    start_fade_ani->setEasingCurve(QEasingCurve::OutBack);
    start_fade_ani->start(QPropertyAnimation::DeleteWhenStopped);

    QGraphicsOpacityEffect *info_fade = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *info_fade_ani = new QPropertyAnimation(info_fade,"opacity");
    info_fade_ani->setDuration(1000);
    info_fade_ani->setStartValue(1);
    info_fade_ani->setEndValue(0);
    info_fade_ani->setEasingCurve(QEasingCurve::OutBack);
    info_fade_ani->start(QPropertyAnimation::DeleteWhenStopped);

    QGraphicsOpacityEffect *exit_fade = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *exit_fade_ani = new QPropertyAnimation(exit_fade,"opacity");
    exit_fade_ani->setDuration(1000);
    exit_fade_ani->setStartValue(1);
    exit_fade_ani->setEndValue(0);
    exit_fade_ani->setEasingCurve(QEasingCurve::OutBack);
    exit_fade_ani->start(QPropertyAnimation::DeleteWhenStopped);


    title -> setGraphicsEffect(title_fade);
    start_button -> setGraphicsEffect(start_fade);
    info_button -> setGraphicsEffect(info_fade);
    exit_button -> setGraphicsEffect(exit_fade);

    QGraphicsOpacityEffect *back_eff = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *back_ani = new QPropertyAnimation(back_eff,"opacity");
    back_ani->setDuration(2000);
    back_ani->setStartValue(0);
    back_ani->setEndValue(1);
    back_ani->setEasingCurve(QEasingCurve::InBack);
    back_ani->start(QPropertyAnimation::DeleteWhenStopped);
    back_button -> setGraphicsEffect(back_eff);

    QGraphicsOpacityEffect *description_eff = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *description_ani = new QPropertyAnimation(description_eff,"opacity");
    description_ani->setDuration(1000);
    description_ani->setStartValue(0);
    description_ani->setEndValue(1);
    description_ani->setEasingCurve(QEasingCurve::InBack);
    description_ani->start(QPropertyAnimation::DeleteWhenStopped);

    back_button -> setGraphicsEffect(back_eff);
    description -> setGraphicsEffect(description_eff);
    back_button -> setVisible(true);
    description -> setVisible(true);
}

void Opening::handleExit(){
    this->close();
}

void Opening::handleBack(){
    QGraphicsOpacityEffect *title_eff = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *title_ani = new QPropertyAnimation(title_eff,"opacity");
    title_ani->setDuration(1000);
    title_ani->setStartValue(0);
    title_ani->setEndValue(1);
    title_ani->setEasingCurve(QEasingCurve::InBack);
    title_ani->start(QPropertyAnimation::DeleteWhenStopped);

    QGraphicsOpacityEffect *start_eff = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *start_ani = new QPropertyAnimation(start_eff,"opacity");
    start_ani->setDuration(2000);
    start_ani->setStartValue(0);
    start_ani->setEndValue(1);
    start_ani->setEasingCurve(QEasingCurve::InBack);
    start_ani->start(QPropertyAnimation::DeleteWhenStopped);

    QGraphicsOpacityEffect *info_eff = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *info_ani = new QPropertyAnimation(info_eff,"opacity");
    info_ani->setDuration(3000);
    info_ani->setStartValue(0);
    info_ani->setEndValue(1);
    info_ani->setEasingCurve(QEasingCurve::InBack);
    info_ani->start(QPropertyAnimation::DeleteWhenStopped);

    QGraphicsOpacityEffect *exit_eff = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *exit_ani = new QPropertyAnimation(exit_eff,"opacity");
    exit_ani->setDuration(4000);
    exit_ani->setStartValue(0);
    exit_ani->setEndValue(1);
    exit_ani->setEasingCurve(QEasingCurve::InBack);
    exit_ani->start(QPropertyAnimation::DeleteWhenStopped);

    QGraphicsOpacityEffect *description_fade = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *description_fade_ani = new QPropertyAnimation(description_fade,"opacity");
    description_fade_ani->setDuration(1000);
    description_fade_ani->setStartValue(1);
    description_fade_ani->setEndValue(0);
    description_fade_ani->setEasingCurve(QEasingCurve::OutBack);
    description_fade_ani->start(QPropertyAnimation::DeleteWhenStopped);

    QGraphicsOpacityEffect *back_fade = new QGraphicsOpacityEffect(this);
    QPropertyAnimation *back_fade_ani = new QPropertyAnimation(back_fade,"opacity");
    back_fade_ani->setDuration(1000);
    back_fade_ani->setStartValue(1);
    back_fade_ani->setEndValue(0);
    back_fade_ani->setEasingCurve(QEasingCurve::OutBack);
    back_fade_ani->start(QPropertyAnimation::DeleteWhenStopped);

    description -> setGraphicsEffect(description_fade);
    back_button -> setGraphicsEffect(back_fade);
    title -> setGraphicsEffect(title_eff);
    start_button ->setGraphicsEffect(start_eff);
    info_button -> setGraphicsEffect(info_eff);
    exit_button -> setGraphicsEffect(exit_eff);
    description -> setVisible(false);
    back_button -> setVisible(false);

}
