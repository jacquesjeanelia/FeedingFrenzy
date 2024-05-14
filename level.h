#ifndef LEVEL_H
#define LEVEL_H
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include "view.h"
#include "enemy.h"
#include "player.h"
#include "sound.h"
#include "score.h"
#include "health.h"

class level: public view
{
    Q_OBJECT
    friend player;

public:
    level(QPixmap myBackground, QUrl myAudio, level_info *myinfo);
    QPixmap background;
    QUrl audio;
    void pausePanel();
    level* Level;
    player* myPlayer;
    level_info *info;

public slots:
    void Play();
    void Stop();

};

#endif // LEVEL_H
