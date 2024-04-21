#ifndef MAINMENU_H
#define MAINMENU_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include "button.h"
#include "levels.h"
#include "view.h"
#include <QTime>
#include <QObject>
class mainmenu: public view
{
    Q_OBJECT
public:
    mainmenu(QPixmap background);
    QGraphicsTextItem *text;
    button* levelsButton;
    button* shopButton;
};

#endif // MAINMENU_H
