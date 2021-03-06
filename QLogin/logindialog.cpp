#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>
LoginDialog::LoginDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::LoginDialog)
{
  ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
  delete ui;
}


void LoginDialog::on_loginBtn_clicked()
{
  if (ui->usrLineEdit->text().trimmed() == tr("qwer") &&
      ui->pwdLineEdit->text() == tr("123")) {
    accept();
  } else {
    QMessageBox::warning(this, tr("warning"),
                         tr("user name or pwd error"),
                         QMessageBox::Yes);
    ui->usrLineEdit->clear();
    ui->pwdLineEdit->clear();
    ui->usrLineEdit->setFocus();
  }
}
