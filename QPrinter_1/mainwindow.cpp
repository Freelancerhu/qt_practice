#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

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

void MainWindow::paintEvent(QPaintEvent *p)
{
  QPainter painter(this);
  QRectF rectangle(10, 20, 80, 60);
  painter.drawLine(QPointF(0, 0), QPointF(100, 100));
  painter.drawEllipse(rectangle);

  // linear gradient
  QLinearGradient linearGradient(QPointF(40, 190), QPointF(70, 190));
  // insert color
  linearGradient.setColorAt(0, Qt::yellow);
  linearGradient.setColorAt(0.5, Qt::red);
  linearGradient.setColorAt(1, Qt::green);
  linearGradient.setSpread(QGradient::ReflectSpread);
  painter.setBrush(linearGradient);
  painter.drawRect(120, 50, 200, 80);

  // radial Gradient
  QRadialGradient radialGradient(QPointF(250, 500), 50, QPointF(275, 200));
  radialGradient.setColorAt(0, QColor(255, 255, 100, 150));
  radialGradient.setColorAt(1, QColor(0, 0, 0, 50));
  radialGradient.setSpread(QGradient::ReflectSpread);
  painter.setBrush(radialGradient);
  painter.drawEllipse(QPointF(250, 500), 150, 100);

  //conical gradient
  QConicalGradient conicalGradient(QPointF(500, 190), 60);
  conicalGradient.setColorAt(0.2, Qt::cyan);
  conicalGradient.setColorAt(0.9, Qt::black);
  painter.setBrush(conicalGradient);
  painter.drawEllipse(QPointF(500, 190), 150, 150);

  QPen pen;
  // set color of pen
  pen.setColor(QColor(255, 0, 0));
  // set line style of pen
  pen.setStyle(Qt::DashDotDotLine);
  // set color of brush
  QBrush brush(QColor(0, 255, 0, 125));
  // set style of brush
  brush.setStyle(Qt::HorPattern);
  painter.setPen(pen);
  painter.setBrush(brush);
  painter.drawRect(150, 150, 200, 100);

  QRectF rec(100, 200, 800, 600);
  int startAngle = 30 * 16;
  int spanAngle = 120 * 16;
  painter.drawArc(rec, startAngle, spanAngle);
}


