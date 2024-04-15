#include "player.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include "enemy.h"

player::player(QPixmap image): seaCreature(image) {


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
        if(y() + 50 < 600)
        {setPos(x(),y()+5);}
    }
    else if(event->key() == Qt::Key_Up)
    {
        if(y() > 000)
        {setPos(x(),y()-5);}
    }


}

//create enemy
void player::createEnemy()
{
    enemy *Enemy = new enemy(QPixmap(":/new/prefix1/small fish 1.png"));
    scene()->addItem(Enemy);
}

