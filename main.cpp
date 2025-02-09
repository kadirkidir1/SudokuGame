#include <QApplication>
#include "screenmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    screenManager* sm = new screenManager;
    sm->showFullScreen();

    return a.exec();
}
