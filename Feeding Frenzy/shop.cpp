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
#include "level.h"
extern mainmenu *m;
extern levels* l;
extern shop *s;
extern level* level1;
shop::shop(QPixmap background, QUrl myAudio): view(QPixmap(background),myAudio) {

    // shop menu
    text = new QGraphicsTextItem("SHOP");
    text->setPos((this->width()/2)-(text->boundingRect().width())/2, 100);
    mainButton = new button("MAIN MENU", 50, 50,s,m);
    scene->addItem(mainButton);
}
