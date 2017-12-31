#include "myitem.h"
#include <QVariant>
#include <QGraphicsItemAnimation>

MyItem::MyItem()
{
  setToolTip("click and drag me.");
  setCursor(Qt::OpenHandCursor);
  color = QColor(qrand() % 256, qrand() % 256, qrand() % 256);
  setFlag(QGraphicsItem::ItemIsFocusable); //图形项可获得焦点
   setFlag(QGraphicsItem::ItemIsMovable); //图形项可移动
   QGraphicsItemAnimation *anim = new QGraphicsItemAnimation; //新建动画类对象
   anim->setItem(this);  //将该图形项加入动画类对象中
   QTimeLine *timeLine = new QTimeLine(1000);  //新建长为1秒的时间线
   timeLine->setLoopCount(0);  //动画循环次数为0，表示无限循环
   anim->setTimeLine(timeLine); //将时间线加入动画类对象中
   anim->setRotationAt(0.5,180); //在动画时间的一半时图形项旋转180度
   anim->setRotationAt(1,360);  //在动画执行完时图形项旋转360度
   timeLine->start();  //开始动画
}

//void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
//{
//  if (event->button() != Qt::LeftButton) {
//    event->ignore();
//    return;
//  }
//  setCursor(Qt::ClosedHandCursor);
//}

void MyItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  moveBy(10, 0);
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

void MyItem::keyPressEvent(QKeyEvent *event)
{
  moveBy(0, 10);
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
  painter->setBrush(!collidingItems().isEmpty()?Qt::red : Qt::green);
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



