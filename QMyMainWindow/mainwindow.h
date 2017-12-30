#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
class QLineEdit;
class QDialog;
class QLabel;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

protected:
  // close event
  void closeEvent(QCloseEvent *event);

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  void newFile();
  bool maybeSave();
  bool save();
  bool saveAs();
  bool saveFile (const QString &fileName);
  bool loadFile(const QString &fileName);

private slots:
  void on_actionNew_File_N_triggered();

  void on_actionSave_S_triggered();

  void on_actionSaveAS_A_triggered();

  void on_actionOpen_File_O_triggered();

  void on_actionExit_X_triggered();

  void on_actionUndo_Z_triggered();

  void on_actionCut_C_triggered();

  void on_actionCopy_C_triggered();

  void on_actionPaste_V_triggered();

  void on_actionClose_File_C_triggered();

  void showFindText();

  void on_actionfind_F_triggered();

private:
  Ui::MainWindow *ui;
  // whether the file is saved
  bool isUntitled;
  // path of the file
  QString curFile;
  QLineEdit *findLineEdit;
  QDialog *findDlg;
  QLabel *statusLabel;
};

#endif // MAINWINDOW_H
