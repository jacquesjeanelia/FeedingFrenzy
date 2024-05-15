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

extern mainmenu *MainMenu;
extern levels* LevelsMenu;
extern shop *ShopMenu;
extern level* level1;
extern level* level2;
extern level* level3;
extern level* level4;
extern level* level5;


//screen with all levels

levels::levels(QPixmap background): view(QPixmap(background), QUrl("qrc:/new/prefix1/Audio/main menu music.mp3")) {

    // levels menu

    mainButton = new button("MAIN MENU", 50, 50, LevelsMenu, MainMenu);
    scene->addItem(mainButton);

    level1Button = new button("LEVEL 1", 500, 50, LevelsMenu, level1);
    scene->addItem(level1Button);

    level2Button = new button("LEVEL 2", 950, 50, LevelsMenu, level2 );
    scene->addItem(level2Button);

    level3Button = new button("LEVEL 3", 50, 400,LevelsMenu, level3);
    scene->addItem(level3Button);

    level4Button = new button("LEVEL 4", 500, 400,LevelsMenu, level4);
    scene->addItem(level4Button);

    level5Button = new button("LEVEL 5", 950, 400,LevelsMenu, level5);
    scene->addItem(level5Button);
}



