#ifndef BUTTON_H
#define BUTTON_H
#include <QObject>
#include <QGraphicsObject>
#include <QString>
#include <QGraphicsTextItem>
#include <QBrush>
#include <QPushButton>
#include<QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QKeyEvent>
#include "view.h"

class button:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    button(QString message, int x, int y, view* in, view* out);
    QGraphicsTextItem *title;
    view *viewIn, *viewOut;
    //View = myView;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    button* newButton(QString name, int x, int y);


signals:
    void clicked();


};

#endif // BUTTON_H
