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
    QString totalString;
    QGraphicsTextItem * Total = new QGraphicsTextItem;
    button* buybuttons[3] = {nullptr, nullptr, nullptr};
    int intScore;
    QGraphicsTextItem *message,*textItem1,*textItem2, *textItem3;

public slots:
    void updateScore();

};

#endif // SHOP_H
