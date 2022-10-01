#include <QMessageBox>
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include "newUser.h"
#include "defines.h"

#define SQL(...) #__VA_ARGS__


NewUser::NewUser(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.confirmButton, SIGNAL(clicked()), this, SLOT(confirmPress()));
}

NewUser::~NewUser()
{}

void NewUser::confirmPress() {
    std::string username = ui.usernameLineEdit->text().toStdString();
    std::string password = ui.passwordLineEdit->text().toStdString();
    try {
        System::String^ connectionString = CONNECTIONSTRING;
        SqlConnection sqlConnection(connectionString);
        sqlConnection.Open();

        System::String^ sqlQuery = SQL(
            SELECT name
            FROM master.sys.server_principals
            WHERE name = @username
        );
        SqlCommand checkUserCommand(sqlQuery, % sqlConnection);
        checkUserCommand.Parameters->AddWithValue("@username", msclr::interop::marshal_as<System::String^>(username));
        /*System::String^ sqlQuery = "GRANT CONNECT TO username=@username IDENTIFIED BY password=@password;";
        SqlCommand command(sqlQuery, % sqlConnection);
        command.Parameters->AddWithValue("@username", msclr::interop::marshal_as<System::String^>(username));
        command.Parameters->AddWithValue("@password", msclr::interop::marshal_as<System::String^>(password));
        */
        SqlDataReader^ checkUserReader = checkUserCommand.ExecuteReader();
        if (!checkUserReader->Read()) {
            //checkUserCommand.Dispose();
            checkUserReader->Close();
            /*
            * for some reason AddWithValue isnt replacing the parameters so starting with string then will convert to String^
             std::string sqlQueryString = SQL(
                USE passwordManager;
                CREATE LOGIN @username WITH PASSWORD = @password;
                CREATE USER @username FOR LOGIN @username;
                CREATE TABLE[dbo].[@username](
                    [Id]       INT           IDENTITY(1, 1) NOT NULL,
                    [username]     VARCHAR(100) NOT NULL,
                    [password] VARCHAR(MAX) NOT NULL,
                    PRIMARY KEY CLUSTERED([Id] ASC),
                    UNIQUE NONCLUSTERED([username] ASC)
                    );
                GRANT ALTER, CONTROL, REFERENCES, DELETE, INSERT, REFERENCES, SELECT, TAKE OWNERSHIP, UPDATE, VIEW CHANGE TRACKING, VIEW DEFINITION ON[dbo].[@username] TO[@username];
            );
            newUserCommand.Parameters->AddWithValue("@username", msclr::interop::marshal_as<System::String^>(username));
            newUserCommand.Parameters->AddWithValue("@password", msclr::interop::marshal_as<System::String^>(password));
            
            */
            std::string sqlQueryString =
                "USE passwordManager; "
                "CREATE LOGIN " + username + " WITH PASSWORD = \'" + password + "\'; "
                "CREATE USER " + username + " FOR LOGIN " + username + "; "
                "CREATE TABLE[dbo].[" + username + "]( "
                " [Id]       INT           IDENTITY(1, 1) NOT NULL, "
                " [username]     VARCHAR(100) NOT NULL, "
                " [password] VARCHAR(MAX) NOT NULL, "
                "   PRIMARY KEY CLUSTERED([Id] ASC), "
                " UNIQUE NONCLUSTERED([username] ASC) "
                " ); "
                "GRANT ALTER, CONTROL, REFERENCES, DELETE, INSERT, REFERENCES, SELECT, TAKE OWNERSHIP, UPDATE, VIEW CHANGE TRACKING, VIEW DEFINITION ON[dbo].[" + username + "] TO[" + username + "]; ";
            QMessageBox::information(this, "Message", QString::fromStdString(sqlQueryString), QMessageBox::Ok);
            sqlQuery = msclr::interop::marshal_as<System::String^>(sqlQueryString);
            // GRANT SELECT ON[schemaName].[tableName] to[username]
            //https://stackoverflow.com/questions/9787047/sql-server-can-you-limit-access-to-only-one-table#:~:text=Using%20the%20UI%20you%20can,%22%20button%20under%20Securables%20tab).
            SqlCommand newUserCommand(sqlQuery, % sqlConnection);

            SqlDataReader^ newUserReader = newUserCommand.ExecuteReader();
            if (newUserReader->Read()) {
                this->hide();
                emit changeToPasswordManager();
            }
            else {
                QMessageBox::information(this, "Message", "error with user creation", QMessageBox::Ok);
            }
        }
        else {
            checkUserReader->Close();
            QMessageBox::information(this, "Message", "username already exists", QMessageBox::Ok);
        }
    }
    catch (std::exception e) {
        QMessageBox::information(this, "Message", "Server connection error", QMessageBox::Ok);
    }
}