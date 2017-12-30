#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
  Q_OBJECT

public:
  explicit Widget(QWidget *parent = 0);
  ~Widget();

protected:
  void mousePressEvent(QMouseEvent *e);
  void keyPressEvent(QKeyEvent *k);

private:
  Ui::Widget *ui;
};

#endif // WIDGET_H
