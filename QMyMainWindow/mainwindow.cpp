#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  // set new action
  QAction *openAction = new QAction(tr("&open"), this);
  // set icon
  QIcon icon(":/myImages/images/7b80d82afa3927b3ee4d2614deb35e3c");
  openAction->setIcon(icon);
  // set shortcut
  openAction->setShortcut((QKeySequence(tr("Ctrl+O"))));
  // add action to menu
  ui->menufile_F->addAction(openAction);

}

MainWindow::~MainWindow()
{
  delete ui;
}
