#include "health.h"
#include <QDebug>
#include <QFont>
#include <QFile>
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

//health object created in level
health::health(QGraphicsItem* parent): QGraphicsTextItem(parent) {
    setPlainText(QString("Health"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Fantasy", 16, QFont::Decorative));
    setPos(1070, 2);
    //QTextStream in2(&fishoptionn);
    currentFile.open(QIODevice::ReadOnly);
    QString line = currentIn.readLine();
    currentFile.close();
    QPixmap heart(":/Images/Heart.png"); // Make sure the path is correct
    heart = heart.scaled(50, 50); // You can scale in one step

    if (line == '2') {
        healthofplayer = 4;
        Heart1 = new QGraphicsPixmapItem(heart, this);
        Heart1->setPos(-50, 30);
        Heart2 = new QGraphicsPixmapItem(heart, this);
        Heart2->setPos(-10, 30);
        Heart3 = new QGraphicsPixmapItem(heart, this);
        Heart3->setPos(30, 30);
        Heart4 = new QGraphicsPixmapItem(heart, this);
        Heart4->setPos(70, 30);
    } else {
        healthofplayer = 3;
        Heart1 = new QGraphicsPixmapItem(heart, this);
        Heart1->setPos(-30, 30);
        Heart2 = new QGraphicsPixmapItem(heart, this);
        Heart2->setPos(10, 30);
        Heart3 = new QGraphicsPixmapItem(heart, this);
        Heart3->setPos(50, 30);
    }
}

// helath decrease function
void health::decrease(){
    healthofplayer--;

    if (healthofplayer == 2) {
        Heart3 -> setVisible(false);
    }
    else if (healthofplayer == 1) {
        Heart2 -> setVisible(false);
    } else if (healthofplayer == 0) {
        Heart1 -> setVisible(false);
    } else if (healthofplayer == 3) {
        Heart4-> setVisible(false);
    }
}

int health::getHealth (){ return healthofplayer;}
