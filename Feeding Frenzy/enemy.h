#ifndef ENEMY_H
#define ENEMY_H
#include "seacreature.h"
#include <QPixmap>
#include <QTimer>
#include "sound.h"

class enemy:public seaCreature
{
    Q_OBJECT
public:
    enemy(QPixmap image, int s);
    int size;
    bool side = true;
public slots:
    void move();
};

#endif // ENEMY_H
