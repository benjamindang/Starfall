#ifndef OPENING_H
#define OPENING_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

class Opening : public QMainWindow
{
    Q_OBJECT
public:
    explicit Opening(QWidget *parent = 0);
private:
    QLabel *title;
    QPushButton *start_button;
    QPushButton *info_button;
    QPushButton *exit_button;
signals:

public slots:
};

#endif // OPENING_H
