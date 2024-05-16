#ifndef VICTORY_H
#define VICTORY_H
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include "button.h"
#include "view.h"

class victory: public view
{
    Q_OBJECT
public:
    victory(QPixmap background);
    QGraphicsTextItem *text;
    button* nextButton;
    button* levelsButton;

};

#endif // VICTORY_H
