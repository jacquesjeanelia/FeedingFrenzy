#include "player.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include "enemy.h"

player::player(QPixmap mySmall, QPixmap myMedium, QPixmap myLarge, level_info *myInfo): seaCreature(mySmall) {

    small = mySmall;
    medium = myMedium;
    large = myLarge;
    size = 1;
    Info = myInfo;
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
        if(x() + 100 < 1200)
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
        if(y() + 100 < 800 )
        {setPos(x(),y()+5);}
    }
    else if(event->key() == Qt::Key_Up)
    {
        if(y() > 0)
        {setPos(x(),y()-5);}
    }
    QList<QGraphicsItem*> collidingitems = collidingItems();
    enemy* list[collidingitems.size()];
    for(int x = 0; x< collidingitems.size(); x++)
    {
        if(typeid(*(collidingitems[x])) == typeid(enemy))
        {

            //QTimer::singleShot(2000, scene()->removeItem(this));
            list[x] = dynamic_cast<enemy*>(collidingitems[x]);
            if(size >= list[x]->size)
            {
                QMediaPlayer *buttonClickPlayer = new QMediaPlayer;
                QAudioOutput *buttonClickOutput = new QAudioOutput;
                int random = rand() % 7;
                buttonClickPlayer->setAudioOutput(buttonClickOutput);
                buttonClickPlayer->setSource(eatList[random]);
                buttonClickPlayer->play();
                if(size == 1)
                {
                    buttonClickPlayer->setSource(QUrl("qrc:/new/prefix1/Audio/grow up 1.mp3"));
                    buttonClickPlayer->play();
                    if(flipped)
                    {
                        setPixmap(medium);
                        setPixmap(pixmap().transformed(QTransform().scale(-1,1)));
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
                    buttonClickPlayer->setSource(QUrl("qrc:/new/prefix1/Audio/grow up 1.mp3"));
                    buttonClickPlayer->play();
                    if(flipped)
                    {
                        setPixmap(large);
                        setPixmap(pixmap().transformed(QTransform().scale(-1,1)));
                        size++;
                    }
                    else
                    {
                        setPixmap(large);
                        size++;
                    }

                }
                if(n<3)
                {
                    n++;
                }
                scene()->removeItem(collidingitems[x]);
                delete collidingitems[x];
            }
            else
            {
            }

        }
    }

}


//create enemy
void player::createEnemy()
{
    int random = rand() % n;
    enemy *Enemy = new enemy(Info->Enemies[random], random+1);
    scene()->addItem(Enemy);

}

