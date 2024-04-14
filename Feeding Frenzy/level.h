#ifndef LEVEL_H
#define LEVEL_H
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include "view.h"

class level: public view
{
public:
    level(QPixmap background, double difficulty);
};

#endif // LEVEL_H
