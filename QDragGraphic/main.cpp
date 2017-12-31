#include "widget.h"
#include <QApplication>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "myitem.h"

int main(int argc, char *argv[])
{
  QApplication app(argc,argv);

  qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
  QGraphicsScene *scene = new QGraphicsScene;
  for(int i=0; i<5; i++)
  {
   MyItem *item = new MyItem;
   item->setPos(i*50+20,100);
   scene->addItem(item);
  }
  RectItem *rect = new RectItem;
  rect->setPos(100,200);
  scene->addItem(rect);
  QGraphicsView *view = new QGraphicsView;
  view->setScene(scene);
  view->resize(400,300);
  view->show();

  return app.exec();
}
