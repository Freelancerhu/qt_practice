#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QDateTime>

Widget::Widget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Widget)
{
  ui->setupUi(this);
  id1 = startTimer(1000);
  id2 = startTimer(2000);
  id3 = startTimer(10000);
  //set seed of random
  qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(timerUpdate()));
  timer->start(1000);
}

Widget::~Widget()
{
  delete ui;
}

void Widget::timerEvent(QTimerEvent *t) {
  if (t->timerId() == id1) {
    ui->label->setText(tr("%1").arg(qrand() % 10));
  } else if (t->timerId() == id2) {
    ui->label_2->setText(tr("hello"));
  } else {
    qApp->quit();
  }
}

void Widget::timerUpdate() {
  // get the current of system
  QDateTime time = QDateTime::currentDateTime();
  // set the format of time
  QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
  // show time on label
  ui->lineEdit->setText(str);
  int rand = qrand() % 300;
  ui->lineEdit->move(rand, rand);
}
