#ifndef PLAYER_H
#define PLAYER_H
#include "seacreature.h"
#include <QPixmap>
#include <QKeyEvent>
#include "enemy.h"
#include <mainmenu.h>
class player: public seaCreature
{
    Q_OBJECT
public:
    player(QPixmap image);
    bool flipped = false;
public slots:
    void createEnemy();
    void keyPressEvent(QKeyEvent *event);
};

#endif // PLAYER_H
