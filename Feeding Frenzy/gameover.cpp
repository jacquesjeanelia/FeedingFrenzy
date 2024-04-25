#include "gameover.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "button.h"
#include "view.h"
#include <QTime>
#include <QObject>
#include <mainmenu.h>

// External Declarations
extern mainmenu *m;
extern levels* l;
extern gameover *g;

// Constructor for gameover class
gameover::gameover(QPixmap background): view(QPixmap(background),QUrl("qrc:/new/prefix1/Audio/gameover.mp3")) {

    // Initialize gameover screen
    text = new QGraphicsTextItem;
    text->setFont(QFont("Fantasy",38, QFont::Fantasy));
    text->setPlainText(QString("GAME OVER"));
    text->setDefaultTextColor(Qt::black);
    text->setPos(500,30);
    scene->addItem(text);
    QFont font("Jersey", 25, QFont::DemiBold);
    text->setFont(font);

    // Create a quit button
    quitButton = new button("QUIT", 300, 250,this,m);
    scene->addItem(quitButton);

    // Create a try again button
    tryButton = new button("LEVELS", 660, 250,this,l);
    scene->addItem(tryButton);
}
