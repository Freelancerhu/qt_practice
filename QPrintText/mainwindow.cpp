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

  // define a rectangle
  QRectF rect(20, 20, 300, 200);
  // draw a rect
  painter.drawRect(rect);
  painter.setPen(QColor(Qt::red));
  // set text position
  painter.drawText(rect, Qt::AlignCenter, "Shengjie Hu");


  // set text font
  QFont font("Arabic", 15, QFont::Bold, true);
  // set under line
  font.setUnderline(true);
  // set over line
  font.setOverline(true);
  // set capitalization
  font.setCapitalization(QFont::SmallCaps);
  // set letter space
  font.setLetterSpacing(QFont::AbsoluteSpacing, 10);
  painter.setFont(font);
  painter.setPen(Qt::green);
  painter.drawText(120, 80, tr("Shengjie Hu"));
  painter.translate(50, 50);
  painter.rotate(90);
  painter.drawText(0, 0, tr("Burning"));



}
