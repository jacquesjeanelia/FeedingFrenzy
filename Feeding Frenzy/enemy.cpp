#include "enemy.h"
#include <QGraphicsScene>

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


    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    //speed depending on fish size
    if(size==1)
    {
        timer->start(7/difficulty);
    }
    else if(size == 2)
    {
        timer->start(10 / difficulty);
    }
    else if(size==3)
    {
        timer->start(20 / difficulty);
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



