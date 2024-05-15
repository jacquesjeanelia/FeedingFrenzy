#include "mainmenu.h"
#include "levels.h"
#include <QApplication>
#include "shop.h"
#include "level.h"
#include <QSplashScreen>
#include "gameover.h"
#include "victory.h"
#include "level_info.h"


mainmenu *MainMenu;
levels* LevelsMenu;
shop *ShopMenu;

level* level1;
level* level2;
level* level3;
level* level4;
level* level5;

gameover* gameover1;
victory* victory1;

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
    level_2_info = new level_info(1.3, QPixmap(":/Images/Minnow.png"),QPixmap( ":/Images/BoxFishRed.png"), QPixmap(":/Images/JohnDoryGreen.png"));
    level_3_info = new level_info(1.5, QPixmap(":/Images/RedCod.png"),QPixmap( ":/Images/BasicCod.png"), QPixmap(":/Images/JohnDoryGreen.png"));
    level_4_info = new level_info(1.7, QPixmap(":/Images/PufferYellow.png"),QPixmap( ":/Images/MarlinBlue.png"), QPixmap(":/Images/TunaBlue.png"));
    level_5_info = new level_info(1.9, QPixmap(":/Images/BarracudaBlue.png"),QPixmap( ":/Images/TunaBlue Big.png"), QPixmap(":/Images/OrcaPlain.png"));

    MainMenu =  new mainmenu(QPixmap(":/Images/title screen.jpeg"));
    LevelsMenu = new levels(QPixmap(":/Images/background1.png"));
    ShopMenu = new shop(QPixmap(":/Images/background1.png"));

    level1 = new level(QPixmap(":/Images/background1.png"), QUrl("qrc:/new/prefix1/Audio/level music 1.mp3"), level_1_info);
    level2 = new level(QPixmap(":/Images/background1.png"), QUrl("qrc:/new/prefix1/Audio/level music 1.mp3"), level_2_info);
    level3 = new level(QPixmap(":/Images/background1.png"), QUrl("qrc:/new/prefix1/Audio/level music 3.mp3"), level_3_info);
    level4 = new level(QPixmap(":/Images/background1.png"), QUrl("qrc:/new/prefix1/Audio/level music 3.mp3"), level_4_info);
    level5 = new level(QPixmap(":/Images/background1.png"), QUrl("qrc:/new/prefix1/Audio/level music 4.mp3"), level_5_info);

    gameover1 = new gameover(QPixmap(":/Images/background1.png"));
    victory1 = new victory(QPixmap(":/Images/background1.png"));


    MainMenu->show();
    //splash.finish(m);

    // connect the buttons

    QObject::connect(MainMenu->levelsButton, SIGNAL(clicked()), MainMenu, SLOT(hide()));
    QObject::connect(MainMenu->levelsButton, SIGNAL(clicked()), LevelsMenu, SLOT(show()));

    QObject::connect(MainMenu->shopButton, SIGNAL(clicked()), MainMenu, SLOT(hide()));
    QObject::connect(MainMenu->shopButton, SIGNAL(clicked()), ShopMenu, SLOT(show()));

    QObject::connect(LevelsMenu->mainButton, SIGNAL(clicked()), LevelsMenu, SLOT(hide()));
    QObject::connect(LevelsMenu->mainButton, SIGNAL(clicked()), MainMenu, SLOT(show()));

    QObject::connect(ShopMenu->mainButton, SIGNAL(clicked()), ShopMenu, SLOT(hide()));
    QObject::connect(ShopMenu->mainButton, SIGNAL(clicked()), MainMenu, SLOT(show()));

    QObject::connect(LevelsMenu->level1Button, SIGNAL(clicked()), LevelsMenu, SLOT(hide()));
    QObject::connect(LevelsMenu->level1Button, SIGNAL(clicked()), level1, SLOT(Play()));
    QObject::connect(LevelsMenu->level1Button, SIGNAL(clicked()), MainMenu, SLOT(mediaStop()));

    QObject::connect(LevelsMenu->level2Button, SIGNAL(clicked()), LevelsMenu, SLOT(hide()));
    QObject::connect(LevelsMenu->level2Button, SIGNAL(clicked()), level2, SLOT(Play()));
    QObject::connect(LevelsMenu->level2Button, SIGNAL(clicked()), MainMenu, SLOT(mediaStop()));

    QObject::connect(LevelsMenu->level3Button, SIGNAL(clicked()), LevelsMenu, SLOT(hide()));
    QObject::connect(LevelsMenu->level3Button, SIGNAL(clicked()), level3, SLOT(Play()));
    QObject::connect(LevelsMenu->level3Button, SIGNAL(clicked()), MainMenu, SLOT(mediaStop()));

    QObject::connect(LevelsMenu->level4Button, SIGNAL(clicked()), LevelsMenu, SLOT(hide()));
    QObject::connect(LevelsMenu->level4Button, SIGNAL(clicked()), level4, SLOT(Play()));
    QObject::connect(LevelsMenu->level4Button, SIGNAL(clicked()), MainMenu, SLOT(mediaStop()));

    QObject::connect(LevelsMenu->level5Button, SIGNAL(clicked()), LevelsMenu, SLOT(hide()));
    QObject::connect(LevelsMenu->level5Button, SIGNAL(clicked()), level5, SLOT(Play()));
    QObject::connect(LevelsMenu->level5Button, SIGNAL(clicked()), MainMenu, SLOT(mediaStop()));

    QObject::connect(victory1->menuButton, SIGNAL(clicked()), level1, SLOT(Stop()));
    QObject::connect(victory1->menuButton, SIGNAL(clicked()), level2, SLOT(Stop()));
    QObject::connect(victory1->menuButton, SIGNAL(clicked()), level3, SLOT(Stop()));
    QObject::connect(victory1->menuButton, SIGNAL(clicked()), level4, SLOT(Stop()));
    QObject::connect(victory1->menuButton, SIGNAL(clicked()), level5, SLOT(Stop()));

    return a.exec();
}
