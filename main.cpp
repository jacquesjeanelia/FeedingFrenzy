#include "mainmenu.h"
#include "levels.h"
#include <QApplication>
#include "shop.h"
#include "level.h"
#include <QSplashScreen>
#include "gameover.h"
#include "victory.h"
#include "level_info.h"


mainmenu *m;
levels* l;
shop *s;

level* level1;
level* level2;
level* level3;
level* level4;
level* level5;

gameover* g;
victory* lc;
level_info* level_1_info;
level_info* level_2_info;
level_info* level_3_info;
level_info* level_4_info;
level_info* level_5_info;


int main(int argc, char *argv[])
{
    //main menu
    QApplication a(argc, argv);
    //QSplashScreen splash(QPixmap(":/Images/title screen.jpeg"));
    //splash.show();
    //a.processEvents();
    level_1_info = new level_info(1, QPixmap(":/Images/Minnow.png"),QPixmap( ":/Images/BoxFishRed.png"), QPixmap(":/Images/LionfishYellow.png"));
    level_2_info = new level_info(1.3, QPixmap(":/Images/Minnow.png"),QPixmap( ":/Images/BoxFishRed.png"), QPixmap(":/Images/LionfishYellow.png"));
    level_3_info = new level_info(1.5, QPixmap(":/Images/Minnow.png"),QPixmap( ":/Images/BoxFishRed.png"), QPixmap(":/Images/LionfishYellow.png"));
    level_4_info = new level_info(1.7, QPixmap(":/Images/Minnow.png"),QPixmap( ":/Images/BoxFishRed.png"), QPixmap(":/Images/LionfishYellow.png"));
    level_5_info = new level_info(1.9, QPixmap(":/Images/Minnow.png"),QPixmap( ":/Images/BoxFishRed.png"), QPixmap(":/Images/LionfishYellow.png"));

    m =  new mainmenu(QPixmap(":/Images/title screen.jpeg"));
    l= new levels(QPixmap(":/Images/background1.png"));
    s = new shop(QPixmap(":/Images/background1.png"));
    level1 = new level(QPixmap(":/Images/background1.png"), QUrl("qrc:/new/prefix1/Audio/level music 1.mp3"), level_1_info);
    level2 = new level(QPixmap(":/Images/background1.png"), QUrl("qrc:/new/prefix1/Audio/level music 1.mp3"), level_2_info);
    level3 = new level(QPixmap(":/Images/background1.png"), QUrl("qrc:/new/prefix1/Audio/level music 1.mp3"), level_3_info);
    level4 = new level(QPixmap(":/Images/background1.png"), QUrl("qrc:/new/prefix1/Audio/level music 1.mp3"), level_4_info);
    level5 = new level(QPixmap(":/Images/background1.png"), QUrl("qrc:/new/prefix1/Audio/level music 1.mp3"), level_5_info);
    g = new gameover(QPixmap(":/Images/background1.png"));
    lc = new victory(QPixmap(":/Images/background1.png"));

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

    QObject::connect(g->quitButton, SIGNAL(clicked()), g, SLOT(hide()));
    QObject::connect(g->quitButton, SIGNAL(clicked()), m, SLOT(show()));
    QObject::connect(g->quitButton, SIGNAL(clicked()), level1, SLOT(Stop()));
    QObject::connect(g->quitButton, SIGNAL(clicked()), m, SLOT(mediaPlay()));



    QObject::connect(g->tryButton, SIGNAL(clicked()), g, SLOT(hide()));
    QObject::connect(g->tryButton, SIGNAL(clicked()), level1, SLOT(Stop()));
    QObject::connect(g->tryButton, SIGNAL(clicked()), level1, SLOT(Play()));



    QObject::connect(lc->menuButton, SIGNAL(clicked()), lc, SLOT(hide()));
    QObject::connect(lc->menuButton, SIGNAL(clicked()), l, SLOT(show()));
    QObject::connect(lc->menuButton, SIGNAL(clicked()), m, SLOT(mediaPlay()));
    QObject::connect(lc->menuButton, SIGNAL(clicked()), level1, SLOT(Stop()));

    QObject::connect(l->level1Button, SIGNAL(clicked()), l, SLOT(hide()));
    QObject::connect(l->level1Button, SIGNAL(clicked()), level1, SLOT(Play()));
    QObject::connect(l->level1Button, SIGNAL(clicked()), m, SLOT(mediaStop()));


    QObject::connect(l->level2Button, SIGNAL(clicked()), l, SLOT(hide()));
    QObject::connect(l->level2Button, SIGNAL(clicked()), level2, SLOT(Play()));
    QObject::connect(l->level2Button, SIGNAL(clicked()), m, SLOT(mediaStop()));


    QObject::connect(l->level3Button, SIGNAL(clicked()), l, SLOT(hide()));
    QObject::connect(l->level3Button, SIGNAL(clicked()), level3, SLOT(Play()));
    QObject::connect(l->level3Button, SIGNAL(clicked()), m, SLOT(mediaStop()));


    QObject::connect(l->level4Button, SIGNAL(clicked()), l, SLOT(hide()));
    QObject::connect(l->level4Button, SIGNAL(clicked()), level4, SLOT(Play()));
    QObject::connect(l->level4Button, SIGNAL(clicked()), m, SLOT(mediaStop()));

    QObject::connect(l->level5Button, SIGNAL(clicked()), l, SLOT(hide()));
    QObject::connect(l->level5Button, SIGNAL(clicked()), level5, SLOT(Play()));
    QObject::connect(l->level5Button, SIGNAL(clicked()), m, SLOT(mediaStop()));
    return a.exec();
}
