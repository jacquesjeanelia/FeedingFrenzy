#ifndef LEVEL_H
#define LEVEL_H
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include "view.h"
#include "player.h"
#include "level_info.h"
#include "gameover.h"
#include "victory.h"

class level: public view
{
    Q_OBJECT
public:
    level(QPixmap myBackground, QUrl myAudio, level_info *myinfo, gameover* myGameOver, victory* myVictory );
    QPixmap background;
    QUrl audio;
    level* Level;
    player* myPlayer;
    level_info *info;
    void gameOver();
    gameover* Gameover;
    victory* Victory;


public slots:
    void Play();
    void Stop();
    //void win();
    //void lose();
};

#endif // LEVEL_H
