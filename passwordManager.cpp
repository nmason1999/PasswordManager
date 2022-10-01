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


void PasswordManager::addPress() {
    addItemWindow = new AddItem();
    addItemWindow->show();
}

void PasswordManager::deletePress() {

}

void PasswordManager::editPress() {

}
