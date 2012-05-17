#include <QtGui/QApplication>
#include "mainwindow.h"

///Main function. Creates a new MainWindow object
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow *window = new MainWindow;
    window->show();

    return app.exec();
}
