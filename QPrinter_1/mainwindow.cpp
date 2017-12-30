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


