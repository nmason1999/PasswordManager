#include "windowHandler.h"

WindowHandler::WindowHandler(QWidget* parent)
    : QMainWindow(parent)
{
    loginWindow = new Login();
    newUserWindow = new NewUser();
    passwordManagerWindow = new PasswordManager();

    loginWindow->show();

    connect(loginWindow, SIGNAL(changeToNewUser()), this, SLOT(openNewUser()));
    connect(loginWindow, SIGNAL(changeToPasswordManager(std::string)), this, SLOT(openPasswordManager(std::string)));
    connect(newUserWindow, SIGNAL(changeToPasswordManager(std::string)), this, SLOT(openPasswordManager(std::string)));
}

WindowHandler::~WindowHandler()
{}

void WindowHandler::openLogin() {
    if (newUserWindow->isVisible()) {
        newUserWindow->close();
    }

    if (passwordManagerWindow->isVisible()) {
        passwordManagerWindow->close();
    }

    loginWindow->show();
}

void WindowHandler::openNewUser() {
        if (loginWindow->isVisible()) {
            loginWindow->close();
        }

        if (passwordManagerWindow->isVisible()) {
            passwordManagerWindow->close();
        }

        newUserWindow->show();
}

void WindowHandler::openPasswordManager(std::string user) {
    if (newUserWindow->isVisible()) {
        newUserWindow->close();
    }

    if (loginWindow->isVisible()) {
        loginWindow->close();
    }

    passwordManagerWindow->getUser(user);
    passwordManagerWindow->show();
}

