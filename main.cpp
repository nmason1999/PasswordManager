#include "passwordManager.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    passwordManager window;
    window.show();
    return app.exec();
}
