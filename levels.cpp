#include "levels.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "button.h"
#include "levels.h"
#include "view.h"
#include <QTime>
#include <QObject>
#include <mainmenu.h>
#include "shop.h"
#include "level.h"
extern mainmenu *m;
extern levels* l;
extern shop *s;
extern level* level1;

//screen with all levels

levels::levels(QPixmap background): view(QPixmap(background), QUrl("qrc:/new/prefix1/Audio/main menu music.mp3")) {

    // levels menu

    mainButton = new button("MAIN MENU", 50, 50, l, m);
    scene->addItem(mainButton);

    level1Button = new button("LEVEL 1", 500, 50, l, level1);
    scene->addItem(level1Button);

    level2Button = new button("LEVEL 2", 950, 50, l, level1 );
    scene->addItem(level2Button);

    level3Button = new button("LEVEL 3", 50, 400,l, level1);
    scene->addItem(level3Button);

    level4Button = new button("LEVEL 4", 500, 400,l, level1);
    scene->addItem(level4Button);

    level5Button = new button("LEVEL 5", 950, 400,l, level1);
    scene->addItem(level5Button);
}



