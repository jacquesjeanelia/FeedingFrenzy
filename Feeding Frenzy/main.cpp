#include "mainmenu.h"
#include "levels.h"
#include <QApplication>
#include "shop.h"
#include "level.h"

mainmenu *m;
levels* l;
shop *s;
level* level1;
int main(int argc, char *argv[])
{
    //main menu
    QApplication a(argc, argv);
    m =  new mainmenu(QPixmap(":/new/prefix1/mainmenu_image2.jpeg").scaled(800,600));
    l= new levels(QPixmap(":/new/prefix1/shop_background.png").scaled(800,600));
    s = new shop(QPixmap(":/new/prefix1/shop_background.png").scaled(800,600));
    level1 = new level(QPixmap(":/new/prefix1/shop_background.png").scaled(800,600), 2);

    m->show();

    // connect the buttons
    QObject::connect(m->levelsButton, SIGNAL(clicked()), m, SLOT(hide()));
    QObject::connect(m->levelsButton, SIGNAL(clicked()), l, SLOT(show()));

    QObject::connect(m->shopButton, SIGNAL(clicked()), m, SLOT(hide()));
    QObject::connect(m->shopButton, SIGNAL(clicked()), s, SLOT(show()));

    QObject::connect(l->mainButton, SIGNAL(clicked()), l, SLOT(hide()));
    QObject::connect(l->mainButton, SIGNAL(clicked()), m, SLOT(show()));

    QObject::connect(s->mainButton, SIGNAL(clicked()), s, SLOT(hide()));
    QObject::connect(s->mainButton, SIGNAL(clicked()), m, SLOT(show()));

    QObject::connect(l->level1Button, SIGNAL(clicked()), l, SLOT(hide()));
    QObject::connect(l->level1Button, SIGNAL(clicked()), level1, SLOT(show()));
    return a.exec();
}
