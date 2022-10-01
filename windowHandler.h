#ifndef WINDOWHANDLER_H
#define WINDOWHANDLER_H

#include "login.h"
#include "newUser.h"
#include "passwordManager.h"

class WindowHandler : public QMainWindow
{
	Q_OBJECT

public:
	explicit WindowHandler(QWidget* parent = nullptr);
	~WindowHandler();

private slots:
	void openLogin();
	void openNewUser();
	void openPasswordManager(std::string user);

private:
	Login* loginWindow;
	NewUser* newUserWindow;
	PasswordManager* passwordManagerWindow;
};

#endif // WINDOWHANDLER_H
