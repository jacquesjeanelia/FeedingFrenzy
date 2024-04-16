#include "enemy.h"
#include <QGraphicsScene>
#include "player.h"

enemy::enemy(QPixmap myImage, int mySize): seaCreature(myImage) {

    size = mySize;
    if(size == 2)
    {
        //setPixmap(image.scaled(x*1.5,y*1.5));
    }
    else if(size == 3)
    {
        //setPixmap(image.scaled(x*1.5*1.5,y*1.5*1.5));
    }
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

}



