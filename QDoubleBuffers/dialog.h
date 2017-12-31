#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMouseEvent>
#include <QPushButton>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
  Q_OBJECT

public:
  explicit Dialog(QWidget *parent = 0);
  ~Dialog();

protected:
  void paintEvent(QPaintEvent *event);
  void mousePressEvent(QMouseEvent *m);
  void mouseMoveEvent(QMouseEvent *m);
  void mouseReleaseEvent(QMouseEvent *m);

private slots:
  void zoomIn();

private:
  Ui::Dialog *ui;
  QPixmap pix;
  QPoint lastPoint;
  QPoint endPoint;
  qreal scale;
  QPushButton *button;

  QPixmap tempPix;
  bool isDrawing;
};

#endif // DIALOG_H
