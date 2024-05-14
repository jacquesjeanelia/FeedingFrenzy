#include "progressbar.h"
#include <QFont>
#include <QBrush>

progressbar::progressbar(QGraphicsItem* parent):QGraphicsRectItem(parent) {
    setRect(0,0,0,10);
    setPos(5,5);
    QBrush brush;
    brush.setColor(Qt::white);
    brush.setStyle(Qt::SolidPattern);
    setBrush(brush);
}

void progressbar::increase(double percentage)
{
    current += percentage;
    setRect(0,0, current*2, 10);
    setPos(5,10);
}
