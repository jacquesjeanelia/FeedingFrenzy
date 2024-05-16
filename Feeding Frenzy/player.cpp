#include "player.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include <QString>
#include "enemy.h"
#include "gameover.h"
#include "victory.h"
#include <QFile>
#include <QDebug>



//extern level* level1;
extern gameover* gameover1;
extern victory* victory1;

// player class
player::player(QPixmap mySmall, QPixmap myMedium, QPixmap myLarge, level_info *myInfo, gameover* myGameOver, victory* myVictory): seaCreature(mySmall) {

    small = mySmall;
    medium = myMedium;
    large = myLarge;
    size = 1;
    Info = myInfo;
    setPos(600 - this->boundingRect().width(),350 - this->boundingRect().height());
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    Victory = myVictory;
    Gameover = myGameOver;

}


void over()
{
}
void lose()
{

}

void win()
{

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
        if(y() < 650 )
        {setPos(x(),y()+5);}
    }
    else if(event->key() == Qt::Key_Up)
    {
        if(y() > 0)
        {setPos(x(),y()-5);}
    }
    //collision handling

    QList<QGraphicsItem*> collidingitems = collidingItems();
    enemy* list[collidingitems.size()];
    for(int x = 0; x < collidingitems.size(); x++)
    {
        if(typeid(*(collidingitems[x])) == typeid(enemy))
        {

            list[x] = dynamic_cast<enemy*>(collidingitems[x]);

            // if enemy is smaller
            if(size >= list[x]->size)
            {
                myScore->increase(list[x]->size);
                int random = rand() % 7;
                playSound(eatList[random]);
                if(myScore->scoreofplayer == 3)
                {

                    playSound(QUrl("qrc:/new/prefix1/Audio/grow up 1.mp3"));
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
                    n++;

                }
                else if(size == 2 && myScore->scoreofplayer >= 10)
                {

                    {
                        playSound(QUrl("qrc:/new/prefix1/Audio/grow up 1.mp3"));
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
                }
                else if(size == 3 && myScore->scoreofplayer >= 19)
                {

                    {
                        //gameover code
                        for(int x = 0; x< scene()->items().size(); x++)
                        {
                            scene()->items()[x]->hide();

                        }
                        playSound(QUrl("qrc:/new/prefix1/Audio/level end.mp3"));
                        //Victory->show();
                        emit win();


                    }
                }
                scene()->removeItem(collidingitems[x]);
                delete collidingitems[x];
            }
            // if enemy is bigger
            else
            {
                myHealth->decrease();
                if (myHealth->healthofplayer == 0)
                {
                    playSound(QUrl("qrc:/new/prefix1/Audio/gameover.mp3"));
                    for(int x = 0; x< scene()->items().size(); x++)
                    {
                        scene()->items()[x]->hide();

                    }
                    //gameover1->show();
                    //emit over();
                    emit lose();


                }
                else

                {
                    playSound(QUrl("qrc:/new/prefix1/Audio/life lost.mp3"));

                    hide();
                    setPos(600,350);
                    QTime respawnTime = QTime::currentTime().addMSecs(2000);
                    while(QTime::currentTime() < respawnTime)
                    {
                        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
                    }
                    show();
                    setFocus();
                }
            }
        }

    }
}

//create enemy
void player::createEnemy()
{

        int random = rand() % n ;
        enemy *Enemy = new enemy(Info->Enemies[random], random+1, Info->difficulty);
        scene()->addItem(Enemy);


}
