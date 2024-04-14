#include "button.h"

button::button(QString message, int x, int y) {


    this->setRect(0, 0, 100, 50);
    title = new QGraphicsTextItem(message,this);
    int xTitle = rect().width()/2 - title->boundingRect().width()/2;
    int yTitle = rect().height()/2 - title->boundingRect().height()/2;
    QBrush brush;
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);
    setBrush(brush);

    title->setPos(xTitle,yTitle);
    title->show();
    title->setDefaultTextColor(Qt::white);
    setAcceptHoverEvents(true);
    setAcceptTouchEvents(true);

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPos(x,y);



}
void clicked(){}
void button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}
void button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setColor(Qt::lightGray);
    brush.setStyle(Qt::SolidPattern);
    setBrush(brush);
}
void button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);
    setBrush(brush);
}

