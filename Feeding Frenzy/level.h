#ifndef LEVEL_H
#define LEVEL_H
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include "view.h"
#include "enemy.h"
#include "player.h"

class level: public view
{
    Q_OBJECT
    friend player;

public:
    level(QPixmap background, QUrl myAudio);
public slots:
    void mediaPlay();


};

#endif // LEVEL_H
