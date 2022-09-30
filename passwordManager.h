#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H


//#include <QMainWindow>
#include "ui_passwordManager.h"

class PasswordManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit PasswordManager(QWidget *parent = nullptr);
    ~PasswordManager();

private:
    Ui::passwordManagerClass ui;
};

#endif // PASSWORDMANAGER_H