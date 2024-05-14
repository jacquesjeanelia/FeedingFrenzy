#include "enemy.h"
#include <QGraphicsScene>
#include "player.h"

//create enemies
enemy::enemy(QPixmap myImage, int mySize, double difficulty): seaCreature(myImage) {

    size = mySize;
    int randomNumber = rand() % 600;
    if(randomNumber % 2 == 0)
    {
        setPos(1300, randomNumber);
        side = false;
    }
    else
    {
        setPixmap(pixmap().transformed(QTransform().scale(-1,1)));
        setPos(-100, randomNumber);
        side = true;
    }


    QTimer *timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    if(size==1)
    {
        timer->start(12 / difficulty);
    }
    else if(size == 2)
    {
        timer->start(10 / difficulty);
    }
    else if(size==3)
   {
        timer->start(16 / difficulty);
    }

}
//moving the enemies
void enemy::move()
{
    {
        if(!side)
        {
            setPos(x()-1,y());
        }
        else
        {
            setPos(x()+1,y());

        }
        if(x() < -100|| x()> 1300)
        {
            scene()->removeItem(this);
            delete this;
        }

    }


}


