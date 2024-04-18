#include "level.h"
#include <QTimer>
#include "player.h"
#include "level_info.h"

level::level(QPixmap background, QUrl myAudio): view(background, myAudio) {

    // level template
    level_info *i = new level_info(1, QPixmap(":/new/prefix1/small fish 1.png"),QPixmap( ":/new/prefix1/enemy2.png"), QPixmap(":/new/prefix1/enemy3.png"));
    player *p = new player(QPixmap(":/new/prefix1/player1 small.png"), QPixmap(":/new/prefix1/player1 medium.png"), QPixmap(":/new/prefix1/player1 large.png"),i );
    p->setFlag(QGraphicsItem::ItemIsFocusable);
    p->setFocus();
    scene->addItem(p);


    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), p, SLOT(createEnemy()));
    timer->start(2000);

}

void level:: mediaPlay()
{
    mediaPlayer->play();
}
