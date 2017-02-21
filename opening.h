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

class Opening : public QMainWindow
{
    Q_OBJECT
public:
    explicit Opening(QWidget *parent = 0);
    void fade_in_effect(QWidget* w,int duration);
    void fade_out_effect(QWidget* w, int duration);
    void hide_all();
    void delay();
private:
    QLabel *title;
    QLabel *description;
    QPushButton *start_button;
    QPushButton *info_button;
    QPushButton *exit_button;
    QPushButton *back_button;

private slots:
    void handleStart();
    void handleInfo();
    void handleExit();
    void handleBack();
};

#endif // OPENING_H
