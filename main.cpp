#include "passwordManager.h"
#include "login.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Login window;
    window.show();
    return app.exec();
}
