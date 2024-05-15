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
#include "level_info.h"

class level: public view
{
    Q_OBJECT
public:
    level(QPixmap myBackground, QUrl myAudio, level_info *myinfo);
    QPixmap background;
    QUrl audio;
    level* Level;
    player* myPlayer;
    level_info *info;

public slots:
    void Play();
    //void Stop();

};

#endif // LEVEL_H
