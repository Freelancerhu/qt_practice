#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include <QLineEdit>
#include <QDialog>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  isUntitled = true;
  curFile = tr("untitled1.txt");
  setWindowTitle(curFile);

  // set new action
  QAction *openAction = new QAction(tr("&open"), this);
  // set icon
  QIcon icon(":/myImages/images/7b80d82afa3927b3ee4d2614deb35e3c");
  openAction->setIcon(icon);
  // set shortcut
  openAction->setShortcut((QKeySequence(tr("Ctrl+O"))));
  // add action to menu
  ui->menufile_F->addAction(openAction);

  //find dialog
  findDlg = new QDialog(this);
  findDlg->setWindowTitle(tr("find"));
  findLineEdit = new QLineEdit(findDlg);
  QPushButton * btn = new QPushButton(tr("find next"), findDlg);
  QVBoxLayout *layout = new QVBoxLayout(findDlg);
  layout->addWidget(findLineEdit);
  layout->addWidget(btn);
  connect(btn, SIGNAL(clicked()), this, SLOT(showFindText()));

  //show message
  //ui->statusBar->showMessage(tr("Shengjie Hu"), 3000);
  statusLabel = new QLabel(this);
  // set minimun size of label
  statusLabel->setMinimumSize(100, 20);
  // set shape of frame
  statusLabel->setFrameShape(QFrame::WinPanel);
  // set shadow
  statusLabel->setFrameShadow(QFrame::Sunken);
  statusLabel->setText(tr("Shengjie Hu"));
  ui->statusBar->addWidget(statusLabel);


  //show permanent message
  QLabel *permanent = new QLabel(this);
  permanent->setFrameStyle(QFrame::Box | QFrame::Sunken);
  permanent->setText(tr("https://github.com/Freelancerhu"));
  permanent->setTextFormat(Qt::RichText);
  permanent->setOpenExternalLinks(true);
  ui->statusBar->addPermanentWidget(permanent);
}

void MainWindow::newFile() {
  if (maybeSave()) {
    isUntitled = true;
    curFile = tr("untitled.txt");
    setWindowTitle(curFile);
    ui->textEdit->clear();
    ui->textEdit->setVisible(true);
  }
}

bool MainWindow::maybeSave() {
  // if the file is modified
  if (ui->textEdit->document()->isModified()) {
    QMessageBox box;
    box.setWindowTitle(tr("warning"));
    box.setIcon(QMessageBox::Warning);
    box.setText(curFile + tr(" is not saved, save it?"));
    QPushButton *yesBtn = box.addButton(tr("Yes(&Y"),
                                        QMessageBox::YesRole);
    box.addButton(tr("No(&N"),
                  QMessageBox::NoRole);
    QPushButton *cancelBut = box.addButton(tr("cancle"),
                                            QMessageBox::RejectRole);
    box.exec();
    if (box.clickedButton() == yesBtn)
      return save();
    else if (box.clickedButton() == cancelBut)
      return false;
  }
  return true;
}

bool MainWindow::save() {
  if (isUntitled) {
    return saveAs();
  } else {
    return saveFile(curFile);
  }
}

bool MainWindow::saveAs() {
  QString fileName = QFileDialog::getSaveFileName(this,
                                                  tr("Save As"),
                                                  curFile);
  if (fileName.isEmpty()) return false;
  return saveFile(fileName);
}

bool MainWindow::saveFile(const QString &fileName) {
  QFile file (fileName);
  if (!file.open(QFile::WriteOnly | QFile::Text)) {
    QMessageBox::warning(this,
                         tr("mutifile manager"),
                         tr("cannot write file %1: /n %2")
                         .arg(fileName).arg(file.errorString()));
    return false;
  }
  QTextStream out(&file);
  //change the state of mouse to waiting
  QApplication::setOverrideCursor(Qt::WaitCursor);
  out << ui->textEdit->toPlainText();
  //change to orignal mouse
  QApplication::restoreOverrideCursor();
  isUntitled = false;
  //get path
  curFile = QFileInfo(fileName).canonicalFilePath();
  setWindowTitle(curFile);
  return true;
}

bool MainWindow::loadFile(const QString &fileName) {
  QFile file(fileName);
  if (!file.open(QFile::ReadOnly | QFile::Text)) {
    QMessageBox::warning (this, tr("mutifile manager"),
                          tr("cannot read file %1:\n %2.")
                          .arg(fileName).arg(file.errorString()));
    return false;
  }
  // new teststream object
  QTextStream in(&file);
  QApplication::setOverrideCursor(Qt::WaitCursor);
  ui->textEdit->setPlainText(in.readAll());
  QApplication::restoreOverrideCursor();
  curFile = QFileInfo(fileName).canonicalFilePath();
  setWindowTitle(curFile);
  return true;
}




MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::on_actionNew_File_N_triggered()
{
    newFile();
}

void MainWindow::on_actionSave_S_triggered()
{
    save();
}

void MainWindow::on_actionSaveAS_A_triggered()
{
    saveAs();
}

void MainWindow::on_actionOpen_File_O_triggered()
{
  if (maybeSave()) {
    QString fileName = QFileDialog::getOpenFileName(this);
    // if file name is not empty
    if (!fileName.isEmpty()) {
      loadFile(fileName);
      ui->textEdit->setVisible(true);
    }
  }
}

void MainWindow::on_actionExit_X_triggered()
{
  on_actionClose_File_C_triggered();
  qApp->quit();
}

void MainWindow::on_actionUndo_Z_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionCut_C_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_C_triggered()
{
  ui->textEdit->copy();
}

void MainWindow::on_actionPaste_V_triggered()
{
  ui->textEdit->paste();
}

void MainWindow::on_actionClose_File_C_triggered()
{
  if (maybeSave()) {
    ui->textEdit->setVisible(false);
  }
}

void MainWindow::showFindText()
{
  QString str = findLineEdit->text();
  if (!ui->textEdit->find(str, QTextDocument::FindBackward)) {
    QMessageBox::warning(this, tr("find"),
                         tr("%1 cannot be found.").arg(str));
  }
}

void MainWindow::closeEvent(QCloseEvent *event) {
  if (maybeSave()) {
    event->accept();
  } else {
    event->ignore();
  }
}



void MainWindow::on_actionfind_F_triggered()
{
    findDlg->show();
}
