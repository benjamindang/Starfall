#include <QApplication>
#include <QPushButton>
#include "opening.h"

int main(int argc, char **argv)
{
    QApplication app (argc,argv);
    Opening window;
    window.show();

    return app.exec();
}
