#include "level.h"
#include <QTimer>
#include "player.h"
#include "level_info.h"
#include "gameover.h"
#include "victory.h"

extern gameover* gameover1;

level::level(QPixmap myBackground, QUrl myAudio, level_info *myinfo, gameover* myGameOver, victory* myVictory): view(myBackground, myAudio) {

    // level template

    myPlayer = new player(QPixmap(":/Images/player2 small.jpeg"), QPixmap(":/Images/player2 medium.jpeg"), QPixmap(":/Images/player3 large.jpeg"),info, Gameover, Victory);
    background = myBackground;
    audio = myAudio;
    info = myinfo;
    Gameover = myGameOver;
    Victory = myVictory;
}

void level:: Play()
{
    scene->clear();
    myPlayer = new player(QPixmap(":/Images/player4 small.png"), QPixmap(":/Images/player4 medium.png"), QPixmap(":/Images/player4 large.png"),info, Gameover,Victory);
    scene->addItem(myPlayer);
    scene->addItem(myPlayer->myHealth);
    scene->addItem(myPlayer->myScore);
    QTimer *timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), myPlayer, SLOT(createEnemy()));
    timer->start(2000 / (info->difficulty*info->difficulty) );
    mediaPlayer->play();
    QObject::connect(myPlayer, SIGNAL(lose()), this, SLOT(mediaStop()));
    QObject::connect(myPlayer, SIGNAL(lose()), this, SLOT(Stop()));
    QObject::connect(myPlayer, SIGNAL(lose()), this, SLOT(hide()));
    QObject::connect(myPlayer, SIGNAL(lose()), Gameover, SLOT(show()));

    QObject::connect(myPlayer, SIGNAL(win()), this, SLOT(mediaStop()));
    QObject::connect(myPlayer, SIGNAL(win()), this, SLOT(Stop()));
    QObject::connect(myPlayer, SIGNAL(win()), this, SLOT(hide()));
    QObject::connect(myPlayer, SIGNAL(win()), Victory, SLOT(show()));
    show();

}

void level:: Stop()
{
    mediaStop();
    hide();
    //delete(this);

}


