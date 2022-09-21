#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H


#include <QtWidgets/QMainWindow>
#include "ui_passwordManager.h"

class PasswordManager : public QMainWindow
{
    Q_OBJECT

public:
    PasswordManager(QWidget *parent = nullptr);
    ~PasswordManager();

private:
    Ui::passwordManagerClass ui;
};

#endif // PASSWORDMANAGER_H