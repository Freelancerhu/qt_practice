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
}

Dialog::~Dialog()
{
  delete ui;
}

void Dialog::paintEvent(QPaintEvent *event) {

  if (scale != 1) {
    QPixmap copyPix(pix.size() * scale);
    QPainter pter(&copyPix);
    pter.scale(scale, scale);
    pter.drawPixmap(0, 0, pix);
    pix = copyPix;
    scale = 1;
  }

  QPainter pp(&pix);
  pp.scale(scale, scale);
  pp.drawLine(lastPoint/scale, endPoint/scale);
  lastPoint = endPoint;
  QPainter painter(this);

  //zoon in
  painter.drawPixmap(0, 0, pix);
}

void Dialog::mousePressEvent(QMouseEvent *m) {
  if (m->button() == Qt::LeftButton) {
    lastPoint = m->pos();
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
    update();
  }
}

void Dialog::zoomIn() {
  scale *= 2;
  update();
}


