#include "mainmenu.h"
#include "levels.h"
#include <QApplication>
#include "shop.h"
#include "level.h"
#include <QSplashScreen>
#include "gameover.h"
#include "victory.h"
#include "level_info.h"
#include <QDebug>
#include "filestream.h"

extern QString desktop;
extern QString totalPath;
extern QString currentPath;
extern QString ownedPath;

extern QFile totalFile;
extern QFile currentFile;
extern QFile ownedFile;

extern QTextStream totalIn;
extern QTextStream currentIn;
extern QTextStream ownedIn;

extern int totalpoints;


mainmenu *MainMenu;
levels* LevelsMenu;
shop *ShopMenu;

level* level1;
level* level2;
level* level3;
level* level4;
level* level5;

gameover* gameover1;
gameover* gameover2;
gameover* gameover3;
gameover* gameover4;
gameover* gameover5;

victory* victory1;
victory* victory2;
victory* victory3;
victory* victory4;
victory* victory5;


level_info* level_1_info;
level_info* level_2_info;
level_info* level_3_info;
level_info* level_4_info;
level_info* level_5_info;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    totalFile.open(QIODevice::ReadOnly);
    QString points = totalIn.readLine();
    totalpoints = points.toInt();
    totalFile.close();

    level_1_info = new level_info(1, 20, QPixmap(":/Images/Minnow.png"),QPixmap( ":/Images/BoxFishRed.png"), QPixmap(":/Images/LionfishYellow.png"));
    level_2_info = new level_info(1.3, 40, QPixmap(":/Images/Minnow.png"),QPixmap( ":/Images/BoxFishRed.png"), QPixmap(":/Images/JohnDoryGreen.png"));
    level_3_info = new level_info(1.5, 60, QPixmap(":/Images/RedCod.png"),QPixmap( ":/Images/BasicCod.png"), QPixmap(":/Images/JohnDoryGreen.png"));
    level_4_info = new level_info(1.7, 80, QPixmap(":/Images/PufferYellow.png"),QPixmap( ":/Images/MarlinBlue.png"), QPixmap(":/Images/TunaBlue.png"));
    level_5_info = new level_info(1.9, 100, QPixmap(":/Images/BarracudaBlue.png"),QPixmap( ":/Images/TunaBlue Big.png"), QPixmap(":/Images/OrcaPlain.png"));

    MainMenu =  new mainmenu(QPixmap(":/Images/title screen.png"));
    LevelsMenu = new levels(QPixmap(":/Images/background1.png"));
    ShopMenu = new shop(QPixmap(":/Images/background1.png"));

    gameover1 = new gameover(QPixmap(":/Images/background1.png"));
    gameover2 = new gameover(QPixmap(":/Images/background1.png"));
    gameover3 = new gameover(QPixmap(":/Images/background1.png"));
    gameover4 = new gameover(QPixmap(":/Images/background1.png"));
    gameover5 = new gameover(QPixmap(":/Images/background1.png"));

    victory1 = new victory(QPixmap(":/Images/background1.png"));
    victory2 = new victory(QPixmap(":/Images/background1.png"));
    victory3 = new victory(QPixmap(":/Images/background1.png"));
    victory4 = new victory(QPixmap(":/Images/background1.png"));
    victory5 = new victory(QPixmap(":/Images/background1.png"));

    victory5->scene->clear();
    victory5->text = new QGraphicsTextItem;
    victory5->text->setFont(QFont("Fantasy",38, QFont::Fantasy));
    victory5->text->setPlainText(QString("CONGRATULATIONS"));
    victory5->text->setDefaultTextColor(Qt::black);
    victory5->text->setPos(450,30);
    victory5->scene->addItem(victory5->text);
    QFont font("Jersey", 25, QFont::DemiBold);
    victory5->text->setFont(font);
    // Create a Main Menu button
    victory5->nextButton = new button("MAIN MENU", 500, 250);
    victory5->scene->addItem(victory5->nextButton);


    QObject::connect(victory5->nextButton, SIGNAL(clicked()), victory5, SLOT(hide()));
    QObject::connect(victory5->nextButton, SIGNAL(clicked()), MainMenu, SLOT(show()));
    QObject::connect(victory5->nextButton, SIGNAL(clicked()), MainMenu, SLOT(mediaPlay()));

    level1 = new level(QPixmap(":/Images/background1.png"), QUrl("qrc:/new/prefix1/Audio/level music 1.mp3"), level_1_info, gameover1, victory1);
    level2 = new level(QPixmap(":/Images/background1.png"), QUrl("qrc:/new/prefix1/Audio/level music 1.mp3"), level_2_info, gameover2, victory2);
    level3 = new level(QPixmap(":/Images/background1.png"), QUrl("qrc:/new/prefix1/Audio/level music 3.mp3"), level_3_info, gameover3, victory3);
    level4 = new level(QPixmap(":/Images/background1.png"), QUrl("qrc:/new/prefix1/Audio/level music 3.mp3"), level_4_info, gameover4, victory4);
    level5 = new level(QPixmap(":/Images/background1.png"), QUrl("qrc:/new/prefix1/Audio/level music 4.mp3"), level_5_info, gameover5, victory5);

    MainMenu->show();

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

    QObject::connect(gameover1->tryButton, SIGNAL(clicked()), gameover1, SLOT(hide()));
    QObject::connect(gameover1->tryButton, SIGNAL(clicked()), level1, SLOT(Play()));
    QObject::connect(victory1->nextButton, SIGNAL(clicked()), victory1, SLOT(hide()));
    QObject::connect(victory1->nextButton, SIGNAL(clicked()), level2, SLOT(Play()));

    QObject::connect(gameover2->tryButton, SIGNAL(clicked()), gameover2, SLOT(hide()));
    QObject::connect(gameover2->tryButton, SIGNAL(clicked()), level2, SLOT(Play()));
    QObject::connect(victory2->nextButton, SIGNAL(clicked()), victory2, SLOT(hide()));
    QObject::connect(victory2->nextButton, SIGNAL(clicked()), level3, SLOT(Play()));

    QObject::connect(gameover3->tryButton, SIGNAL(clicked()), gameover3, SLOT(hide()));
    QObject::connect(gameover3->tryButton, SIGNAL(clicked()), level3, SLOT(Play()));
    QObject::connect(victory3->nextButton, SIGNAL(clicked()), victory3, SLOT(hide()));
    QObject::connect(victory3->nextButton, SIGNAL(clicked()), level4, SLOT(Play()));

    QObject::connect(gameover4->tryButton, SIGNAL(clicked()), gameover4, SLOT(hide()));
    QObject::connect(gameover4->tryButton, SIGNAL(clicked()), level4, SLOT(Play()));
    QObject::connect(victory4->nextButton, SIGNAL(clicked()), victory4, SLOT(hide()));
    QObject::connect(victory4->nextButton, SIGNAL(clicked()), level5, SLOT(Play()));

    QObject::connect(gameover5->tryButton, SIGNAL(clicked()), gameover5, SLOT(hide()));
    QObject::connect(gameover5->tryButton, SIGNAL(clicked()), level5, SLOT(Play()));
    QObject::connect(victory5->nextButton, SIGNAL(clicked()), victory5, SLOT(hide()));
    QObject::connect(victory5->nextButton, SIGNAL(clicked()), MainMenu, SLOT(show()));

    return a.exec();
}
