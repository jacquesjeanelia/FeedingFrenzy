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

levels::levels(QPixmap background, QUrl myAudio): view(QPixmap(background), myAudio) {

    // levels menu
    text = new QGraphicsTextItem("LEVELS");
    text->setPos((this->width()/2)-(text->boundingRect().width())/2, 100);
    scene->addItem(text);

    mainButton = new button("MAIN MENU", 50, 50, l, m);
    scene->addItem(mainButton);

    level1Button = new button("LEVEL 1", 200, 100, l, level1);
    scene->addItem(level1Button);

    level2Button = new button("LEVEL 2", 350, 100, l, level1 );
    scene->addItem(level2Button);

    level3Button = new button("LEVEL 3", 500, 100,l, level1);
    scene->addItem(level3Button);

    level4Button = new button("LEVEL 4", 200, 200,l, level1);
    scene->addItem(level4Button);

    level5Button = new button("LEVEL 5", 350, 200,l, level1);
    scene->addItem(level5Button);
}
