#include "level.h"
#include <QTimer>
#include "player.h"
#include "level_info.h"

level::level(QPixmap background, QUrl myAudio): view(background, myAudio) {

    // level template
    level_info *i = new level_info(1, QPixmap(":/Images/Minnow.png"),QPixmap( ":/Images/BoxFishRed.png"), QPixmap(":/Images/LionfishYellow.png"));

    player *p = new player(QPixmap(":/Images/player1 small.png"), QPixmap(":/Images/player1 medium.png"), QPixmap(":/Images/player1 large.png"),i );
    levelScore =new score;
    scene->addItem(levelScore);
    levelHealth= new health;
    scene->addItem(levelHealth);
    scene->addItem(p);


    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), p, SLOT(createEnemy()));
    timer->start(2000);

}

void level:: mediaPlay()
{
    mediaPlayer->play();
}

void level::pausePanel()
{
    for(int x = 0; x< scene->items().size();x++)
    {
        scene->items()[x]->setEnabled(false);
    }
}
