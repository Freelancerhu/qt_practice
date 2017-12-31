#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>
#include <QDebug>

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
  QPixmap pix(200,200);
  qDebug() << pix.size();
  painter.scale(2, 2);
  pix.fill(Qt::red);
  QPainter pp(&pix);
  pp.drawLine(0, 0, 50, 50);
  qDebug() << pix.size();
  painter.drawPixmap(0, 0, pix);

}

void Dialog::mousePressEvent(QMouseEvent *m)
{
  // show position of mouse
  qDebug() << m->pos();
}
