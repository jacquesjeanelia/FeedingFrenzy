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
extern mainmenu *m;
extern levels* l;
extern shop *s;
extern level* level1;

mainmenu::mainmenu(QPixmap background, QUrl myAudio) :view(QPixmap(background), myAudio){

    levelsButton = new button("LEVELS", 50, 300,m,l);
    scene->addItem(levelsButton);

    shopButton = new button("SHOP", 1050, 300,m,s);
    scene->addItem(shopButton);



    this->setScene(scene);
}



