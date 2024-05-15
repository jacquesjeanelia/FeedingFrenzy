#include "mainmenu.h"
#include <QGraphicsScene>
#include<QGraphicsTextItem>
#include "button.h"
#include "player.h"
#include "enemy.h"
#include <QtMultimedia>
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

//main menu screen
mainmenu::mainmenu(QPixmap background) :view(QPixmap(background), QUrl("qrc:/new/prefix1/Audio/main menu music.mp3")){

    levelsButton = new button("LEVELS", 50, 300,MainMenu,LevelsMenu);
    scene->addItem(levelsButton);

    shopButton = new button("SHOP", 950, 300,MainMenu,ShopMenu);
    scene->addItem(shopButton);
    mediaPlayer->play();



    this->setScene(scene);
}



