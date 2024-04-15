#include "enemy.h"
#include <QGraphicsScene>
#include "player.h"

enemy::enemy(QPixmap image): seaCreature(image) {

    int randomNumber = rand() % 500;
    if(randomNumber % 2 == 0)
    {
        setPos(800, randomNumber);
        side = false;
    }
    else
    {
        setPixmap(pixmap().transformed(QTransform().scale(-1,1)));
        setPos(0, randomNumber);
        side = true;
    }


    QTimer *timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void enemy::move()
{
    if(!side)
    {
        setPos(x()-5,y());
    }
    else
    {
        setPos(x()+5,y());

    }
    if(x() + 50 < 0)
    {
        scene()->removeItem(this);
        delete this;
    }

    QList<QGraphicsItem*> collidingitems = collidingItems();
    for(int x = 0; x< collidingitems.size(); x++)
    {
        if(typeid(*(collidingitems[x])) == typeid(player))
        {
            scene()->removeItem(this);
            delete this;
        }
    }

}



