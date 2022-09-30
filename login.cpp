#include <string>
#include <QMessageBox>
#include <msclr\marshal_cppstd.h>
#include "login.h"


Login::Login(QWidget* parent) :
    QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.confirmButton, SIGNAL(clicked()), this, SLOT(confirmPress()));
    connect(ui.newUserButton, SIGNAL(clicked()), this, SLOT(newUserPress()));
}

Login::~Login()
{}


void Login::confirmPress() {
    std::string username = ui.usernameLineEdit->text().toStdString();
    std::string password = ui.passwordLineEdit->text().toStdString();
    try {
        System::String^ connectionString = "Data Source=DESKTOP-GN4TKUU;Initial Catalog=passwordManager;Integrated Security=True"; // change for your machine
        SqlConnection sqlConnection(connectionString);
        sqlConnection.Open();

        System::String^ sqlQuery = "SELECT * FROM users WHERE username=@username AND password=@password;";
        SqlCommand command(sqlQuery, %sqlConnection);
        command.Parameters->AddWithValue("@username", msclr::interop::marshal_as<System::String^>(username));
        command.Parameters->AddWithValue("@password", msclr::interop::marshal_as<System::String^>(password));

        SqlDataReader^ reader = command.ExecuteReader();
        if (reader->Read()) {
            User^ user = gcnew User;
            user->id = reader->GetInt32(0);
            user->username = reader->GetString(1);
            user->password = reader->GetString(2);

            this->hide();
            emit changeToPasswordManager();
        }
        else {
            QMessageBox::information(this, "Message", "Email or password is incorrect", QMessageBox::Ok);
        }
    }
    catch (std::exception e) {
        QMessageBox::information(this, "Message", "Server connection error", QMessageBox::Ok);
    }
}

void Login::newUserPress() {
    emit changeToNewUser();
}
