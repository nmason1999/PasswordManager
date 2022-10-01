#include <string>
#include <QMessageBox>
#include <msclr\marshal_cppstd.h>
#include "defines.h"
#include "addItem.h"

#define SQL(...) #__VA_ARGS__

AddItem::AddItem(QWidget* parent) :
    QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.confirmButton, SIGNAL(clicked()), this, SLOT(confirmPress()));
}

AddItem::~AddItem()
{}


void AddItem::confirmPress() {
    std::string url = ui.urlLineEdit->text().toStdString();
    std::string username = ui.usernameLineEdit->text().toStdString();
    std::string password = ui.passwordLineEdit->text().toStdString();
    std::string confirmPassword = ui.confirmPasswordLineEdit->text().toStdString();

    try {
        System::String^ connectionString = CONNECTIONSTRING;
        SqlConnection sqlConnection(connectionString);
        sqlConnection.Open();
        /*
        System::String^ sqlQuery = SQL(
            USE [passwordManager]
SETUSER 'luke';
GO
INSERT INTO passwordManager.dbo.luke (url, username, password)
VALUES( 'url', 'luks', 'password');
SETUSER;
        );
        command.Parameters->AddWithValue("@url", msclr::interop::marshal_as<System::String^>(url));
        command.Parameters->AddWithValue("@username", msclr::interop::marshal_as<System::String^>(username));
        command.Parameters->AddWithValue("@password", msclr::interop::marshal_as<System::String^>(password));
        */

        std::string sqlQueryString =
            "USE[passwordManager]"
            "SETUSER '" + username + "';" //!!!!!!!!!!!!!!! need to change so using username from login
            "INSERT INTO passwordManager.dbo." + username + "(url, username, password)" //!!!!!!!!!!!!!!! need to change so using username from login
            "VALUES('" + url + "', '" + username + "', '" + password + "');";
        System::String^ sqlQuery = msclr::interop::marshal_as<System::String^>(sqlQueryString);
        SqlCommand command(sqlQuery, %sqlConnection);

        SqlDataReader^ reader = command.ExecuteReader();
        this->close();
    }
    catch (std::exception e) {
        QMessageBox::information(this, "Message", "Server connection error", QMessageBox::Ok);
    }
}

