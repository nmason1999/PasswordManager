#include <string>
#include <QMessageBox>
#include <msclr\marshal_cppstd.h>
#include "defines.h"
#include "addItem.h"

#define SQL(...) #__VA_ARGS__

AddItem::AddItem(std::string user ,QWidget* parent) :
    QMainWindow(parent)
{
    this->user = user;
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
            SETUSER '@user';
            GO
            INSERT INTO passwordManager.dbo.@user (url, username, password)
            VALUES( '@url', '@username', '@password');
            SETUSER;
        );
        command.Parameters->AddWithValue("@url", msclr::interop::marshal_as<System::String^>(url));
        command.Parameters->AddWithValue("@user", msclr::interop::marshal_as<System::String^>(user));
        command.Parameters->AddWithValue("@username", msclr::interop::marshal_as<System::String^>(username));
        command.Parameters->AddWithValue("@password", msclr::interop::marshal_as<System::String^>(password));
        */

        std::string sqlQueryString =
            "USE[passwordManager]"
            "SETUSER '" + user + "';"
            "INSERT INTO passwordManager.dbo." + user + "(url, username, password)"
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

