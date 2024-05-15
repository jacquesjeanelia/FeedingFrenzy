#ifndef GAMEOVER_H
#define GAMEOVER_H
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include "button.h"
#include "view.h"
#include "level.h"

class gameover: public view
{
    Q_OBJECT
public:
    gameover(QPixmap background);
    QGraphicsTextItem *text;
    level* Level;
    button* levelsButton;
    //button* tryButton;
};

#endif // GAMEOVER_H
