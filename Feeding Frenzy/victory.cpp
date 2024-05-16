#include "victory.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "button.h"
#include "view.h"
#include <QTime>
#include <QObject>
#include <mainmenu.h>
#include "levels.h"

// Declare the external variables
extern mainmenu* MainMenu;
extern levels* LevelsMenu;


// Constructor for the victory class
victory::victory(QPixmap background): view(QPixmap(background), QUrl("qrc:/new/prefix1/Audio/level end.mp3")) {

    // Create a new QGraphicsTextItem for the victory message
    text = new QGraphicsTextItem;
    text->setFont(QFont("Fantasy",42, QFont::Fantasy));
    text->setPlainText(QString("YOU WON!"));
    text->setDefaultTextColor(Qt::black);
    text->setPos(450,30);
    scene->addItem(text);


    // Create a new button for the "Next Level" option
    levelsButton = new button("LEVELS", 300, 250);
    scene->addItem(levelsButton);

    // Create a new button for the "Next Level" option
    nextButton = new button("NEXT", 660, 250);
    scene->addItem(nextButton);

    QObject::connect(levelsButton, SIGNAL(clicked()), this, SLOT(hide()));
    QObject::connect(levelsButton, SIGNAL(clicked()), LevelsMenu, SLOT(show()));
    QObject::connect(levelsButton, SIGNAL(clicked()), MainMenu, SLOT(mediaPlay()));

}
