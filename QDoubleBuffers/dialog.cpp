#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>


Dialog::Dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::Dialog)
{
  ui->setupUi(this);
  resize(600, 500);
  pix = QPixmap(200, 200);
  pix.fill(Qt::white);
  // new a button
  scale = 1;
  button = new QPushButton(this);
  button->setText(tr("zoomIn"));
  button->move(500, 450);
  connect(button, SIGNAL(clicked()), this, SLOT(zoomIn()));
  isDrawing = false;
}

Dialog::~Dialog()
{
  delete ui;
}

void Dialog::paintEvent(QPaintEvent *event) {
//Auxiliary canvas
  int x, y, w, h;
  x = lastPoint.x();
  y = lastPoint.y();
  w = endPoint.x() - x;
  h = endPoint.y() - y;
  QPainter painter(this);
  if (isDrawing) {
    tempPix = pix;
    QPainter pp(&tempPix);
    pp.drawRect(x, y, w, h);
    painter.drawPixmap(0, 0, tempPix);
  } else {
    QPainter pp(&pix);
    pp.drawRect(x, y, w, h);
    painter.drawPixmap(0, 0, pix);
  }

}

void Dialog::mousePressEvent(QMouseEvent *m) {
  if (m->button() == Qt::LeftButton) {
    lastPoint = m->pos();
    isDrawing = true;
  }
}

void Dialog::mouseMoveEvent(QMouseEvent *m) {
  if (m->buttons()&Qt::LeftButton) {
    endPoint = m->pos();
    update();
  }
}

void Dialog::mouseReleaseEvent(QMouseEvent *m) {
  if (m->button() == Qt::LeftButton) {
    endPoint = m->pos();
    isDrawing = false;
    update();
  }
}

void Dialog::zoomIn() {
  scale *= 2;
  update();
}


