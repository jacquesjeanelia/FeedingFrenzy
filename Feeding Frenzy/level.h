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
    score *levelScore;
    health *levelHealth;
    level(QPixmap background, QUrl myAudio);
    void pausePanel();
public slots:
    void mediaPlay();


};

#endif // LEVEL_H
