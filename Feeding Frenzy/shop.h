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
    void buyItem(int);
    void SelectItem(int);
    QString ownedFishString;
    QGraphicsTextItem * Total = new QGraphicsTextItem;
    button* buybuttons[3] = {nullptr, nullptr, nullptr};
    int intScore;

};

#endif // SHOP_H
