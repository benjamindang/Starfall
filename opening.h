#ifndef OPENING_H
#define OPENING_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QTime>
#include <QCoreApplication>
#include <QGraphicsScene>
#include <gamescene.h>

class gameScene;

class Opening : public QMainWindow
{
    Q_OBJECT
public:
    explicit Opening(QWidget *parent = 0);
    void fade_in_effect(QWidget* w,int duration);
    void fade_out_effect(QWidget* w, int duration);
    void style_button(QPushButton* w);
    void hide_all();
    void show_all();
    void delay();
    void reset();
    QGraphicsView* get_view();
    gameScene* get_scene();
private:
    QLabel *title;
    QLabel *description;
    QPushButton *start_button;
    QPushButton *info_button;
    QPushButton *exit_button;
    QPushButton *back_button;
    gameScene *game_scene;
    QGraphicsView *game_view;
    QLabel *game_over;
    QPushButton *play_again;
    QLabel *score_label;
private slots:
    void handleStart();
    void handleInfo();
    void handleExit();
    void handleBack();
    void handlePlay();
};

#endif // OPENING_H
