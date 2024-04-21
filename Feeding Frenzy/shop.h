#ifndef SHOP_H
#define SHOP_H
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include "button.h"
#include "view.h"

class shop: public view
{
    Q_OBJECT
public:
    shop(QPixmap background);
    QGraphicsTextItem *text;
    button* mainButton;
};

#endif // SHOP_H
