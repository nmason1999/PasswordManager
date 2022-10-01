#include <QMessageBox>
#include "passwordManager.h"

PasswordManager::PasswordManager(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.addButton, SIGNAL(clicked()), this, SLOT(addPress()));
    connect(ui.deleteButton, SIGNAL(clicked()), this, SLOT(deletePress()));
    connect(ui.editButton, SIGNAL(clicked()), this, SLOT(editPress()));
}

PasswordManager::~PasswordManager()
{}

void PasswordManager::getUser(std::string user) {
    this->user = user;
}


void PasswordManager::addPress() {
    addItemWindow = new AddItem(user);
    addItemWindow->show();
    // having issues preventing multiple windows
    // singleton?
    /*
    if (addItemWindow == nullptr) {
        addItemWindow = new AddItem(user);
        addItemWindow->show();
    }
    else if (addItemWindow->isVisible()) {
        QMessageBox::information(this, "Message", "window is currently open", QMessageBox::Ok);
    }
    */
}

void PasswordManager::deletePress() {

}

void PasswordManager::editPress() {

}
