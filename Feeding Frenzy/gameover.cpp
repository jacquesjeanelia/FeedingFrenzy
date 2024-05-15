#include "gameover.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "button.h"
#include "view.h"
#include <QTime>
#include <QObject>
#include <mainmenu.h>
#include "level.h"
#include "levels.h"

// External Declarations
extern mainmenu *MainMenu;
extern levels* LevelsMenu;

// Constructor for gameover class
gameover::gameover(QPixmap background, level *myLevel): view(QPixmap(background),QUrl("qrc:/new/prefix1/Audio/gameover.mp3")) {

    // Initialize gameover screen
    text = new QGraphicsTextItem;
    text->setFont(QFont("Fantasy",38, QFont::Fantasy));
    text->setPlainText(QString("GAME OVER"));
    text->setDefaultTextColor(Qt::black);
    text->setPos(500,30);
    scene->addItem(text);
    QFont font("Jersey", 25, QFont::DemiBold);
    text->setFont(font);
    Level = myLevel;

    // Create a quit button
    levelsButton = new button("LEVELS", 500, 250,this,MainMenu);
    scene->addItem(levelsButton);

    // Create a try again button
    //tryButton = new button("TRY AGAIN", 660, 250,this, myLevel);
    //scene->addItem(tryButton);

    QObject::connect(levelsButton, SIGNAL(clicked()), this, SLOT(hide()));
    QObject::connect(levelsButton, SIGNAL(clicked()), LevelsMenu, SLOT(show()));
    QObject::connect(levelsButton, SIGNAL(clicked()), LevelsMenu, SLOT(mediaPlay()));

}
