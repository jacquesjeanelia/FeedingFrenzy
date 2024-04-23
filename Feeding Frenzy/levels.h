#ifndef LEVELS_H
#define LEVELS_H
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include "button.h"
#include "view.h"

class levels: public view
{
    Q_OBJECT
public:
    levels(QPixmap background);
    QGraphicsTextItem *text;
    button* mainButton;
    button* level1Button;
    button* level2Button;
    button* level3Button;
    button* level4Button;
    button* level5Button;




};

#endif // LEVELS_H
