#include "levels.h"

levels::levels(QPixmap background): view(QPixmap(background)) {

    text = new QGraphicsTextItem("LEVELS");
    text->setPos((this->width()/2)-(text->boundingRect().width())/2, 100);
    scene->addItem(text);

    mainButton = new button("MAIN MENU", 50, 50);
    scene->addItem(mainButton);

    level1Button = new button("LEVEL 1", 200, 100);
    scene->addItem(level1Button);

    level2Button = new button("LEVEL 2", 350, 100);
    scene->addItem(level2Button);

    level3Button = new button("LEVEL 3", 500, 100);
    scene->addItem(level3Button);

    level4Button = new button("LEVEL 4", 200, 200);
    scene->addItem(level4Button);

    level5Button = new button("LEVEL 5", 350, 200);
    scene->addItem(level5Button);
}
