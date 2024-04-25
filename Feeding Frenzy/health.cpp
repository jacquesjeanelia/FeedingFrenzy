#include "health.h"
#include <QDebug>
#include <QFont>

health::health(QGraphicsItem* parent): QGraphicsTextItem(parent) {
    setPlainText(QString("Health"));
    setDefaultTextColor(Qt::red);
    setFont(QFont("Fantasy", 16, QFont::Decorative));
    setPos(1070, 2);

    QPixmap heart(":/Images/Heart.png"); // Make sure the path is correct
    heart = heart.scaled(50, 50); // You can scale in one step

    if (heart.isNull()) {
        qDebug() << "Failed to load the heart image!";
    }

    Heart1 = new QGraphicsPixmapItem(heart, this);
    Heart1->setPos(-30, 30);


    Heart2 = new QGraphicsPixmapItem(heart, this);
    Heart2->setPos(10, 30);
    Heart3 = new QGraphicsPixmapItem(heart, this);
    Heart3->setPos(50, 30);
}


void health::decrease(){
    healthofplayer--;
    if (healthofplayer == 2) {
        Heart3 -> setVisible(false);
    }
    else if (healthofplayer == 1) {
        Heart2 -> setVisible(false);
    } else if (healthofplayer == 0) {
        Heart1 -> setVisible(false);
    }
}

int health::getHealth (){ return healthofplayer;}
