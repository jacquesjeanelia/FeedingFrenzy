#include "mainmenu.h"
#include "levels.h"
#include <QApplication>
#include "shop.h"
#include "level.h"
#include <QSplashScreen>

mainmenu *m;
levels* l;
shop *s;
level* level1;

int main(int argc, char *argv[])
{
    //main menu
    QApplication a(argc, argv);
    //QSplashScreen splash(QPixmap(":/Images/title screen.jpeg"));
    //splash.show();
    //a.processEvents();
    m =  new mainmenu(QPixmap(":/Images/title screen.jpeg"));
    l= new levels(QPixmap(":/Images/background1.png"));
    s = new shop(QPixmap(":/Images/background1.png"));
    level1 = new level(QPixmap(":/Images/background1.png"), QUrl("qrc:/new/prefix1/Audio/level music 1.mp3"));

    m->show();
    //splash.finish(m);

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
    QObject::connect(l->level1Button, SIGNAL(clicked()), level1, SLOT(mediaPlay()));
    QObject::connect(l->level1Button, SIGNAL(clicked()), m, SLOT(mediaStop()));

    return a.exec();
}
