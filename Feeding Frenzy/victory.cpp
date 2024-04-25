#include "victory.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "button.h"
#include "view.h"
#include <QTime>
#include <QObject>
#include <mainmenu.h>

// Declare the external variables
extern mainmenu *m;
extern levels* l;


// Constructor for the victory class
victory::victory(QPixmap background): view(QPixmap(background), QUrl("qrc:/new/prefix1/Audio/level end.mp3")) {

    // Create a new QGraphicsTextItem for the victory message
    text = new QGraphicsTextItem;
    text->setFont(QFont("Fantasy",42, QFont::Fantasy));
    text->setPlainText(QString("YOU WON!"));
    text->setDefaultTextColor(Qt::black);
    text->setPos(500,30);
    scene->addItem(text);

    // Create a new button for the "Menu" option

    menuButton = new button("Menu", 300, 250,this,m);
    scene->addItem(menuButton);

    // Create a new button for the "Next Level" option
    nextButton = new button("Next Level", 660, 250,this,l);
    scene->addItem(nextButton);

}
