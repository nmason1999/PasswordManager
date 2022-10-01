#ifndef ADDITEM_H
#define ADDITEM_H

#include "ui_addItem.h"

namespace Ui {
    class AddItem;
}

using System::Data::SqlClient::SqlConnection;
using System::Data::SqlClient::SqlCommand;
using System::Data::SqlClient::SqlDataReader;

class AddItem : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddItem(QWidget* parent = nullptr);
    ~AddItem();

signals:
    void changeToPasswordManager();

private slots:
    void confirmPress();

private:
    Ui::addItemClass ui;
};

#endif // ADDITEM_H