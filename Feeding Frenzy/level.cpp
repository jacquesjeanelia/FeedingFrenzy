#include "level.h"
#include <QTimer>
#include "player.h"
#include "level_info.h"
#include <QFile>
#include <QString>
#include <QDebug>
QFile currentFile2("C:\\Users\\jacqu\\Documents\\FeedingFrenzy - Copy\\Feeding Frenzy\\currentfish.txt");


level::level(QPixmap myBackground, QUrl myAudio, level_info *myinfo, gameover* myGameOver, victory* myVictory): view(myBackground, myAudio) {

    // level template
    info = myinfo;
    myPlayer = new player(QPixmap(":/Images/player2 small.jpeg"), QPixmap(":/Images/player2 medium.jpeg"), QPixmap(":/Images/player3 large.jpeg"),info, Gameover, Victory);
    background = myBackground;
    audio = myAudio;
    Gameover = myGameOver;
    Victory = myVictory;

}


void level:: Play()
{
    QTextStream in2(&currentFile2);
    currentFile2.open(QIODevice::ReadOnly);
    QString line = in2.readLine();
    currentFile2.close();
    delete myPlayer;

    if (line == '0') {
        myPlayer = new player(QPixmap(":/Images/player1 small.png"), QPixmap(":/Images/player1 medium.png"), QPixmap(":/Images/player1 large.png"),info, Gameover, Victory );
    } else if (line == '1') {
        myPlayer = new player(QPixmap("://Images/player2 small.png"), QPixmap("://Images/player2 medium.png"), QPixmap("://Images/player2 large.png"),info, Gameover, Victory );
    } else if (line == '2') {
        myPlayer = new player(QPixmap("://Images/player3 small.png"), QPixmap("://Images/player3 medium.png"), QPixmap("://Images/player3 large.png"),info, Gameover, Victory );
    } else {
        myPlayer = new player(QPixmap("://Images/player4 small.png"), QPixmap("://Images/player4 medium.png"), QPixmap("://Images/player4 large.png"),info, Gameover, Victory );
    }


    scene->addItem(myPlayer);
    scene->addItem(myPlayer->myHealth);
    scene->addItem(myPlayer->myScore);
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), myPlayer, SLOT(createEnemy()));
    timer->start(2000 / info->difficulty);
    mediaPlayer->play();

    QObject::connect(myPlayer, SIGNAL(over()), this, SLOT(mediaStop()));
    QObject::connect(myPlayer, SIGNAL(over()), this, SLOT(Stop()));

    QObject::connect(myPlayer, SIGNAL(lose()), Gameover, SLOT(show()));
    QObject::connect(myPlayer, SIGNAL(win()), Victory, SLOT(show()));
    show();

}

void level:: Stop()
{
    mediaStop();
    hide();
    timer->stop();

}
