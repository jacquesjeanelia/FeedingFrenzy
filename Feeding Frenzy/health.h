#ifndef HEALTH_H
#define HEALTH_H
#include<QGraphicsTextItem>

class health:public QGraphicsTextItem
{
public:
    health(QGraphicsItem *parent = 0);
    int healthofplayer = 3;
    void decrease();
    int getHealth();
    QGraphicsPixmapItem* Heart1;
    QGraphicsPixmapItem* Heart2;
    QGraphicsPixmapItem* Heart3;
};


#endif // HEALTH_H
