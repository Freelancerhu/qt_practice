#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>

Dialog::Dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Dialog)
{
  ui->setupUi(this);
}

Dialog::~Dialog()
{
  delete ui;
}

void Dialog::paintEvent(QPaintEvent *p)
{
  QPainter painter(this);
  QPixmap pix;
  pix.load("../printer_2/reg.png");
  painter.drawPixmap(0, 0, 129, 125, pix);

  // translate pic
  painter.translate(100, 100);
  painter.drawPixmap(0, 0, 129, 125, pix);

  qreal width = pix.width();
  qreal height = pix.height();
  pix = pix.scaled(width * 2, height * 2, Qt::KeepAspectRatio);
  painter.drawPixmap(170, 170, pix);

  painter.translate(64, 33);
  // rotate the pic clockwise
  painter.rotate(90);
  painter.translate(-64, -33);
  painter.drawPixmap(200, 20, 125, 129, pix);

  painter.shear(0.5, 0);
  painter.drawPixmap(300, 0, 129, 66, pix);
}
