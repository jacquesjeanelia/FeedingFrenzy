#include "level.h"
#include <QTimer>
#include "player.h"
#include "level_info.h"

level::level(QPixmap myBackground, QUrl myAudio): view(myBackground, myAudio) {

    background = myBackground;
    audio = myAudio;
    // level template
    level_info *i = new level_info(1, QPixmap(":/Images/Minnow.png"),QPixmap( ":/Images/BoxFishRed.png"), QPixmap(":/Images/LionfishYellow.png"));

    myPlayer = new player(QPixmap(":/Images/player1 small.png"), QPixmap(":/Images/player1 medium.png"), QPixmap(":/Images/player1 large.png"),i );


    scene->addItem(myPlayer);
    scene->addItem(myPlayer->myHealth);
    scene->addItem(myPlayer->myScore);


    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), myPlayer, SLOT(createEnemy()));
    timer->start(2000);


}

void level:: Play()
{
    mediaPlayer->play();
    Level = new level(background, audio);
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
