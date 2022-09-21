#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_passwordManager.h"

class passwordManager : public QMainWindow
{
    Q_OBJECT

public:
    passwordManager(QWidget *parent = nullptr);
    ~passwordManager();

private:
    Ui::passwordManagerClass ui;
};
