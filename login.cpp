#include <string>
#include <QMessageBox>
#include <msclr\marshal_cppstd.h>
#include "login.h"


Login::Login(QWidget* parent) :
    QMainWindow(parent)
{
    ui.setupUi(this);
    second = new PasswordManager();
    timer = new QTimer();
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(confirmPress()));
    connect(timer, &QTimer::timeout, this, &Login::changeWindow);
    timer->start(1000); // 1000 ms
}

Login::~Login()
{}

void Login::changeWindow()
{
    if (second->isVisible()) {
        second->hide();
        this->show();
    }
}

void Login::confirmPress() {
    std::string username = ui.lineEdit_user->text().toStdString();
    std::string password = ui.lineEdit_pass->text().toStdString();
    try {
        System::String^ connectionString = "Data Source=DESKTOP-GN4TKUU;Initial Catalog=passwordManager;Integrated Security=True";
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
            second->show();
        }
        else {
            QMessageBox::information(this, "Message", "Email or password is incorrect", QMessageBox::Ok);
        }
    }
    catch (std::exception e) {
        QMessageBox::information(this, "Message", "Server connection error", QMessageBox::Ok);
    }
}
