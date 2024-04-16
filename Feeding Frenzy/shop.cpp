#include "shop.h"

shop::shop(QPixmap background): view(QPixmap(background)) {

    // shop menu
    text = new QGraphicsTextItem("SHOP");
    text->setPos((this->width()/2)-(text->boundingRect().width())/2, 100);
    mainButton = new button("MAIN MENU", 50, 50);
    scene->addItem(mainButton);
}
