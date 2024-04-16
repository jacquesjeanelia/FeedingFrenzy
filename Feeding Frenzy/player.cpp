#include "player.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include "enemy.h"

player::player(QPixmap mySmall, QPixmap myMedium, QPixmap myLarge): seaCreature(mySmall) {

    small = mySmall;
    medium = myMedium;
    large = myLarge;
    size = 1;
}

//keyPress events
void player::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_Left)
    {
        if(x() > 0)
    {
        setPos(x()-5,y());
        if(!flipped)
        {
            setPixmap(pixmap().transformed(QTransform().scale(-1,1)));
            flipped = true;
        }
    }
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(x() < 750)
        {
            setPos(x()+5,y());
            if(flipped)
            {
                setPixmap(pixmap().transformed(QTransform().scale(-1,1)));
                flipped = false;
            }
        }
    }
    else if(event->key() == Qt::Key_Down)
    {
        if(y() + 75 < 600)
        {setPos(x(),y()+5);}
    }
    else if(event->key() == Qt::Key_Up)
    {
        if(y() > -25)
        {setPos(x(),y()-5);}
    }

    QList<QGraphicsItem*> collidingitems = collidingItems();
    for(int x = 0; x< collidingitems.size(); x++)
    {
        if(typeid(*(collidingitems[x])) == typeid(enemy))
        {
            if(size == 1)
            {
                if(flipped)
                {
                    setPixmap(medium.scaled(-1,1));
                    size++;
                }
                else
                {
                    setPixmap(medium);
                    size++;
                }
            }
            else if(size == 2)
            {
                if(flipped)
                {
                    setPixmap(large.scaled(-1,1));
                    size++;
                }
                else
                {
                    setPixmap(large);
                    size++;
                }
            }
            scene()->removeItem(collidingitems[x]);
            delete collidingitems[x];

        }
    }

}

//create enemy
void player::createEnemy()
{
    enemy *Enemy = new enemy(QPixmap(":/new/prefix1/small fish 1.png"), 1);
    scene()->addItem(Enemy);
}

