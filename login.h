#ifndef LOGIN_H
#define LOGIN_H

#include "passwordManager.h"
#include "ui_login.h"

namespace Ui {
    class Login;
}

using System::Data::SqlClient::SqlConnection;
using System::Data::SqlClient::SqlCommand;
using System::Data::SqlClient::SqlDataReader;

// ref to fix a member of a non-managed class cannot be a handle
ref struct User {
        int id = 0;
        System::String^ username = nullptr;
        System::String^ password = nullptr;
};

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget* parent = nullptr);
    ~Login();

signals:
    void changeToNewUser();
    void changeToPasswordManager();

private slots:
    void confirmPress();
    void newUserPress();

private:
    Ui::loginClass ui;
};

#endif // LOGIN_H