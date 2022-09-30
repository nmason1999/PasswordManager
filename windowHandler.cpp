#include "windowHandler.h"

WindowHandler::WindowHandler(QWidget* parent)
    : QMainWindow(parent)
{
    loginWindow = new Login();
    newUserWindow = new NewUser();
    passwordManagerWindow = new PasswordManager();

    loginWindow->show();

    connect(loginWindow, SIGNAL(changeToNewUser()), this, SLOT(openNewUser()));
    connect(loginWindow, SIGNAL(changeToPasswordManager()), this, SLOT(openPasswordManager()));
    connect(newUserWindow, SIGNAL(clicked()), this, SLOT(confirmPress()));
}

WindowHandler::~WindowHandler()
{}

void WindowHandler::openLogin() {
    if (newUserWindow->isVisible()) {
        newUserWindow->hide();
    }

    if (passwordManagerWindow->isVisible()) {
        passwordManagerWindow->hide();
    }

    loginWindow->show();
}

void WindowHandler::openNewUser() {
        if (loginWindow->isVisible()) {
            loginWindow->hide();
        }

        if (passwordManagerWindow->isVisible()) {
            passwordManagerWindow->hide();
        }

        newUserWindow->show();
}

void WindowHandler::openPasswordManager() {
    if (newUserWindow->isVisible()) {
        newUserWindow->hide();
    }

    if (loginWindow->isVisible()) {
        loginWindow->hide();
    }

    passwordManagerWindow->show();
}

