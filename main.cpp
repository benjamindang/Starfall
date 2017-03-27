#include <QApplication>
#include <QPushButton>
#include <QFont>
#include <ctime>
#include <cstdlib>
#include "opening.h"

int globalscore;

int main(int argc, char **argv)
{
    srand(time(NULL));
    QApplication app (argc,argv);
    Opening window;
    window.show();

    return app.exec();
}
