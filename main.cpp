#include "passwordManager.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    passwordManager w;
    w.show();
    return a.exec();
}
