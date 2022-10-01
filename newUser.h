#ifndef NEWUSER_H
#define NEWUSER_H

#include "ui_newUser.h"

using System::Data::SqlClient::SqlConnection;
using System::Data::SqlClient::SqlCommand;
using System::Data::SqlClient::SqlDataReader;

namespace Ui {
	class NewUser;
}

class NewUser : public QMainWindow
{
	Q_OBJECT

public:
	explicit NewUser(QWidget* parent = 0);
	~NewUser();

signals:
	void changeToPasswordManager();

private slots:
	void confirmPress();

private:
	Ui::newUserClass ui;
};

#endif // NEWUSER_H
