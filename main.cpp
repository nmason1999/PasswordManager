#include "WindowHandler.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    WindowHandler window;
    return app.exec();
}
