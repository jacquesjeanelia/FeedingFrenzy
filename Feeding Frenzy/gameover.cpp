#include "gameover.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "button.h"
#include "view.h"
#include <QTime>
#include <QObject>
#include <mainmenu.h>
#include "level.h"

// External Declarations
extern mainmenu *MainMenu;

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
    quitButton = new button("QUIT", 300, 250,this,MainMenu);
    scene->addItem(quitButton);

    // Create a try again button
    tryButton = new button("TRY AGAIN", 660, 250,this, Level);
    scene->addItem(tryButton);

    QObject::connect(quitButton, SIGNAL(clicked()), this, SLOT(hide()));
    QObject::connect(quitButton, SIGNAL(clicked()), MainMenu, SLOT(show()));
    QObject::connect(quitButton, SIGNAL(clicked()), MainMenu, SLOT(mediaPlay()));
    QObject::connect(tryButton, SIGNAL(clicked()), this, SLOT(hide()));
    QObject::connect(tryButton, SIGNAL(clicked()), Level, SLOT(Play()));
}
