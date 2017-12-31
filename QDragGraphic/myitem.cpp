#include "myitem.h"
#include <QVariant>

MyItem::MyItem()
{
  setToolTip("click and drag me.");
  setCursor(Qt::OpenHandCursor);
  color = QColor(qrand() % 256, qrand() % 256, qrand() % 256);

}

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
  if (event->button() != Qt::LeftButton) {
    event->ignore();
    return;
  }
  setCursor(Qt::ClosedHandCursor);
}

void MyItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
  if (QLineF(event->scenePos(), event->buttonDownScenePos(Qt::LeftButton))
      .length() < QApplication::startDragDistance()) {
    return;
  }
  QDrag *drag = new QDrag((QObject*)event->widget());
  QMimeData *mime = new QMimeData;
  drag->setMimeData(mime);
  mime->setColorData(color);

  QPixmap pix(21, 21);
  pix.fill(Qt::white);
  QPainter painter(&pix);
  paint(&painter, 0, 0);
  drag->setPixmap(pix);

  drag->setHotSpot(QPoint(10, 15));
  drag->exec();
  setCursor(Qt::OpenHandCursor);

}

void MyItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
  setCursor(Qt::OpenHandCursor);
}


QRectF MyItem::boundingRect() const
{
  qreal penWidth = 1;
  return QRectF(0 - penWidth / 2, 0 -penWidth / 2,
             20 + penWidth, 20 + penWidth);
}


void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget)
{
  Q_UNUSED(option);
  Q_UNUSED(widget);
  painter->setBrush(color);
  painter->drawEllipse(0, 0, 20, 20);
}

RectItem::RectItem() {
  setAcceptDrops(true);
  color = QColor(Qt::lightGray);
}

QRectF RectItem::boundingRect() const {
  return QRectF(0, 0, 50, 50);
}

void RectItem::paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(dragOver? color.light(130) : color);
   painter->drawRect(0,0,50,50);
}

void RectItem::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
   if(event->mimeData()->hasColor())
    {
       event->setAccepted(true);
       dragOver = true;
       update();
    }
   else event->setAccepted(false);
}

void RectItem::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
   Q_UNUSED(event);
   dragOver = false;
   update();
}

void RectItem::dropEvent(QGraphicsSceneDragDropEvent*event)
{
   dragOver = false;
  if(event->mimeData()->hasColor()){
    color = (event->mimeData()->colorData()).value<QColor>();
  }
   update();
}



