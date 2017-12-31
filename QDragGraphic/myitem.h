#ifndef MYITEM_H
#define MYITEM_H
#include <QtGui>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QDrag>
#include <QMimeData>

class MyItem : public QGraphicsItem
{
public:
  // the bounding of rectangle
  QRectF boundingRect() const;
  // the function of painter
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget*widget);
  MyItem();

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event);
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
  QColor color;

};

class RectItem : public QGraphicsItem
{
public:
   RectItem();
   QRectF boundingRect() const;
   void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);
protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
    void dropEvent(QGraphicsSceneDragDropEvent *event);
private:
    QColor color;
    bool dragOver;
};

#endif // MYITEM_H
