#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QFontDatabase>

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::paintEvent(QPaintEvent *p) {
  QPainter painter(this);

  QPainterPath path;
  path.addEllipse(100, 100, 50, 50);
  path.lineTo(200, 200);
  painter.setPen(Qt::blue);
  painter.setBrush(Qt::red);
  painter.drawPath(path);

  //copy path
  QPainterPath path2;
  path2.addPath(path);
  path2.translate(100, 0);
  painter.drawPath(path2);

  //draw rectangle
  QPainterPath rec;
  rec.addRect(50, 50, 40, 40);
  rec.moveTo(100, 100);
  rec.lineTo(200, 200);
  painter.drawPath(rec);





}
