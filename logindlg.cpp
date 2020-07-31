#include "logindlg.h"
#include "ui_logindlg.h"
LoginDlg::LoginDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDlg)
{
    ui->setupUi(this);
    this->parent = parent;
}

LoginDlg::~LoginDlg()
{
    delete ui;
}
void LoginDlg::on_commandLinkButton_clicked()
{
    this->parent->show();
    QDialog::accept();
}
