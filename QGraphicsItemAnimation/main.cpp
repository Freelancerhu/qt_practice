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

     QGraphicsScene *scene = new QGraphicsScene;
     MyItem *item =new MyItem;
     QGraphicsLineItem *line = new QGraphicsLineItem(0, 50, 300, 50);
     scene->addItem(item);
     scene->addItem(line);
     QGraphicsView *view = new QGraphicsView;
     view->setScene(scene);
     view->show();

     return app.exec();
}
