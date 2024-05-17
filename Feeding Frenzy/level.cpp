#include "level.h"
#include <QTimer>
#include "player.h"
#include "level_info.h"
#include <QFile>
#include <QString>
#include <QDebug>
#include "filestream.h"
#include "shop.h"

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

extern shop* ShopMenu;

//level class
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


    //delete old player if exists
    delete myPlayer;

    //creates new player depending on which is the currentplayer
    currentFile.open(QIODevice::ReadOnly);
    QString line = currentIn.readLine();
    currentFile.close();
    if (line == '1') {
        myPlayer = new player(QPixmap("://Images/player2 small.png"), QPixmap("://Images/player2 medium.png"), QPixmap("://Images/player2 large.png"),info, Gameover, Victory );
    } else if (line == '2') {
        myPlayer = new player(QPixmap("://Images/player3 small.png"), QPixmap("://Images/player3 medium.png"), QPixmap("://Images/player3 large.png"),info, Gameover, Victory );
    } else if (line == '3') {
        myPlayer = new player(QPixmap("://Images/player4 small.png"), QPixmap("://Images/player4 medium.png"), QPixmap("://Images/player4 large.png"),info, Gameover, Victory );
    } else {
        myPlayer = new player(QPixmap(":/Images/player1 small.png"), QPixmap(":/Images/player1 medium.png"), QPixmap(":/Images/player1 large.png"),info, Gameover, Victory );
    }


    scene->addItem(myPlayer);
    scene->addItem(myPlayer->myHealth);
    scene->addItem(myPlayer->myScore);
    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), myPlayer, SLOT(createEnemy())); //creates enemies
    timer->start(2000 / info->difficulty);
    mediaPlayer->play();

    // when game is over, music stop, hide level
    QObject::connect(myPlayer, SIGNAL(over()), this, SLOT(mediaStop()));
    QObject::connect(myPlayer, SIGNAL(over()), this, SLOT(Stop()));
    // victory or gameover screen
    QObject::connect(myPlayer, SIGNAL(lose()), Gameover, SLOT(show()));
    QObject::connect(myPlayer, SIGNAL(win()), Victory, SLOT(show()));
    //update the score
    QObject::connect(myPlayer, SIGNAL(over()),ShopMenu, SLOT(updateScore()));
    show();

}

void level:: Stop()
{
    mediaStop();
    hide();
    timer->stop();

}
