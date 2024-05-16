#ifndef PLAYER_H
#define PLAYER_H
#include "seacreature.h"
#include <QPixmap>
#include <QKeyEvent>
#include <mainmenu.h>
#include "level_info.h"
#include "health.h"
#include "score.h"
#include "gameover.h"
#include "victory.h"
class player: public seaCreature
{
    Q_OBJECT

public:
    player(QPixmap mySmall, QPixmap myMedium, QPixmap myLarge, level_info *myInfo, gameover* myGameOver, victory* myVictory);
    health* myHealth = new health;
    score* myScore = new score;
    int n = 2;
    int enemyFrequency = 0;
    level_info *Info;
    QPixmap small, medium, large;
    QUrl eatList[7] = { QUrl("qrc:/new/prefix1/Audio/crunch.mp3"), QUrl("qrc:/new/prefix1/Audio/crunch 2.mp3"), QUrl("qrc:/new/prefix1/Audio/small eat.mp3"), QUrl(":/new/prefix1/Audio/medium eat.mp3"), QUrl("qrc:/new/prefix1/Audio/burp.mp3"), QUrl("qrc:/new/prefix1/Audio/big eat.mp3"), QUrl("qrc:/new/prefix1/Audio/bigger eat.mp3")};
    int size = 1;
    bool flipped = false;
    victory* Victory;
    gameover* Gameover;

public slots:
    void createEnemy();
    void keyPressEvent(QKeyEvent *event);

signals:
    void over();
    void lose();
    void win();
};

#endif // PLAYER_H
