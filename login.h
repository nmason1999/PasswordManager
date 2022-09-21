#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QTimer>
#include "passwordManager.h"
#include "ui_login.h"

namespace Ui {
    class Login;
}

using System::Data::SqlClient::SqlConnection;
using System::Data::SqlClient::SqlCommand;

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget* parent = 0);
    ~Login();

private slots:
    void confirmPress();
    void changeWindow();

private:
    Ui::loginClass ui;
    PasswordManager* second;
    QTimer* timer;
};

#endif // LOGIN_H