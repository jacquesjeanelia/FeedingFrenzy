#ifndef LEVEL_H
#define LEVEL_H
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include "view.h"
#include "enemy.h"
#include "player.h"

class level: public view
{
    friend player;

public:
    level(QPixmap background);

};

#endif // LEVEL_H
