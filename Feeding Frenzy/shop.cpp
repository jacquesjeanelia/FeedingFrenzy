#include "shop.h"
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

//shop later to be implemented
extern mainmenu *MainMenu;
extern levels* LevelsMenu;
extern shop *ShopMenu;

shop::shop(QPixmap background): view(QPixmap(background),QUrl("qrc:/new/prefix1/Audio/main menu music.mp3")) {

    // shop menu
    text = new QGraphicsTextItem("SHOP");
    text->setPos((this->width()/2)-(text->boundingRect().width())/2, 100);
    mainButton = new button("MAIN MENU", 50, 50);
    scene->addItem(mainButton);
}
