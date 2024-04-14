#include "mainmenu.h"
#include <QGraphicsScene>
#include<QGraphicsTextItem>
#include "button.h"
#include "player.h"
#include "enemy.h"

mainmenu::mainmenu(QPixmap background) :view(QPixmap(background)){

    levelsButton = new button("LEVELS", 50, 300);
    scene->addItem(levelsButton);

    shopButton = new button("SHOP", 650, 300);
    scene->addItem(shopButton);



    this->setScene(scene);
}



