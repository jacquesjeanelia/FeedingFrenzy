#include "player.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QDebug>
#include <QString>
#include "enemy.h"
#include "gameover.h"
//#include "main.cpp"
#include "victory.h"
#include <QFile>
#include <QDebug>
#include <QFile>
#include "filestream.h"

extern QString desktop;
extern QString totalPath;
extern QString currentPath;
extern QString ownedPath;

extern QFile totalFile;
extern QFile currentFile;
extern QFile ownedFile;

extern QTextStream totalIn;
extern QTextStream currentIn;
extern QTextStream ownedIn;

extern int totalpoints;

extern gameover* gameover1;
extern victory* victory1;

// player class
player::player(QPixmap mySmall, QPixmap myMedium, QPixmap myLarge, level_info *myInfo, gameover* myGameOver, victory* myVictory): seaCreature(mySmall, 1) {

    small = mySmall;
    medium = myMedium;
    large = myLarge;
    Info = myInfo;
    max = Info->max;
    setPos(600 - this->boundingRect().width(),350 - this->boundingRect().height());
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    Victory = myVictory;
    Gameover = myGameOver;
    myScore = new score(max);
}


void over()
{
}

void win()
{

}

void lose()
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

    QTextStream in2(&currentFile);
    currentFile.open(QIODevice::ReadOnly);
    QString line = in2.readLine();
    currentFile.close();

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
                if (line == '3') {

                    myScore->increase(list[x]->size*2);
                }
                else
                {
                    myScore->increase(list[x]->size);
                }


                int random = rand() % 7;
                playSound(eatList[random]);
                if((size == 1) && (myScore->scoreofplayer >= (max/4)))
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
                else if(size == 2 && myScore->scoreofplayer >= (max/2))
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
                else if(size == 3 && myScore->scoreofplayer >= max)
                {

                    {
                        //victory code
                        for(int x = 0; x< scene()->items().size(); x++)
                        {
                            scene()->items()[x]->hide();

                        }
                        playSound(QUrl("qrc:/new/prefix1/Audio/level end.mp3"));
                        //score is added to total points
                        totalFile.open(QIODevice::WriteOnly);
                        totalpoints += myScore->scoreofplayer;
                        totalIn << QString::number(totalpoints);
                        totalFile.close();
                        emit over();
                        emit win();
                    }
                }
                scene()->removeItem(collidingitems[x]);
                delete collidingitems[x];
            }
            // if enemy is bigger
            else
            {
                //gameover code
                myHealth->decrease();
                if (myHealth->healthofplayer == 0)
                {
                    playSound(QUrl("qrc:/new/prefix1/Audio/gameover.mp3"));
                    for(int x = 0; x< scene()->items().size(); x++)
                    {
                        scene()->items()[x]->hide();

                    }
                    emit over();
                    emit lose();
                }
                else

                {
                    //lose one life
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
    if (myHealth->healthofplayer != 0)
    {
        int random = rand() % n ;
        enemy *Enemy = new enemy(Info->Enemies[random], random+1, Info->difficulty);
        scene()->addItem(Enemy);
    }

}
