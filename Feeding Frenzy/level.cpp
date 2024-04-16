#include "level.h"
#include <QTimer>
#include "player.h"

level::level(QPixmap background, double difficulty): view(background) {

    // level template
    player *p = new player(QPixmap(":/new/prefix1/player1 small.png"), QPixmap(":/new/prefix1/player1 medium.png"), QPixmap(":/new/prefix1/player1 large.png"));
    p->setFlag(QGraphicsItem::ItemIsFocusable);
    p->setFocus();
    scene->addItem(p);

    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), p, SLOT(createEnemy()));
    timer->start(2000);
}
