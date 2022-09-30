#ifndef NEWUSER_H
#define NEWUSER_H

#include "ui_newUser.h"

namespace Ui {
	class NewUser;
}

class NewUser : public QMainWindow
{
	Q_OBJECT

public:
	explicit NewUser(QWidget* parent = 0);
	~NewUser();
private:
	Ui::newUserClass ui;
};

#endif // NEWUSER_H
