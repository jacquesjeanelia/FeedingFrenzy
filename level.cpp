#include "level.h"
#include <QTimer>
#include "player.h"
#include "level_info.h"

level::level(QPixmap myBackground, QUrl myAudio, level_info *myinfo): view(myBackground, myAudio) {

    background = myBackground;
    audio = myAudio;
    info = myinfo;
    // level template

    myPlayer = new player(QPixmap(":/Images/player1 small.png"), QPixmap(":/Images/player1 medium.png"), QPixmap(":/Images/player1 large.png"),info );


    scene->addItem(myPlayer);
    scene->addItem(myPlayer->myHealth);
    scene->addItem(myPlayer->myScore);


    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), myPlayer, SLOT(createEnemy()));
    timer->start(2000 / info->difficulty );


}

void level:: Play()
{
    mediaPlayer->play();
    Level = new level(background, audio, info);
    Level->show();

}

void level:: Stop()
{
    mediaPlayer->stop();
    Level->hide();

}


void level::pausePanel()
{
    for(int x = 0; x< scene->items().size();x++)
    {
        scene->items()[x]->setEnabled(false);
    }
}
