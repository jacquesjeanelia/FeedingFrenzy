#ifndef HEALTH_H
#define HEALTH_H
#include<QGraphicsTextItem>

class health:public QGraphicsTextItem
{
public:
    health(QGraphicsItem *parent = 0);
    int healthofplayer=1;
    void decrease();
    int getHealth();
};


#endif // HEALTH_H
