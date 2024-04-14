#ifndef MAINMENU_H
#define MAINMENU_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include "button.h"
#include "levels.h"
#include "view.h"
class mainmenu:public view
{
public:
    mainmenu(QPixmap background);
    QGraphicsTextItem *text;
    button* levelsButton;
    button* shopButton;
    void toLevels(levels* l)
    {
        l->show();
        hide();
    }
};

#endif // MAINMENU_H
