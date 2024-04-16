#ifndef PLAYER_H
#define PLAYER_H
#include "seacreature.h"
#include <QPixmap>
#include <QKeyEvent>
#include "enemy.h"
#include <mainmenu.h>
#include "level_info.h"
class player: public seaCreature
{
    Q_OBJECT

public:
    player(QPixmap mySmall, QPixmap myMedium, QPixmap myLarge, level_info *myInfo);
    int n = 2;
    level_info *Info;
    QPixmap small, medium, large;
    int size;
    bool flipped = false;
public slots:
    void createEnemy();
    void keyPressEvent(QKeyEvent *event);
};

#endif // PLAYER_H
