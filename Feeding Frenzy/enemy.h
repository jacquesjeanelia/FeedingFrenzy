#ifndef ENEMY_H
#define ENEMY_H
#include "seacreature.h"
#include <QPixmap>
#include <QTimer>
class enemy:public seaCreature
{
    Q_OBJECT
public:
    enemy(QPixmap image);
    bool side = true;
public slots:
    void move();
};

#endif // ENEMY_H
