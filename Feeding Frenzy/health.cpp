#include "health.h"
#include <QFont>

health::health(QGraphicsItem* parent):QGraphicsTextItem(parent) {
    setPlainText(QString("Health: ")+ QString::number(healthofplayer));
    setDefaultTextColor(Qt::red);
    setFont(QFont(("Fantasy"),16, QFont::Decorative));
    setPos(1100, 0);
}

void health::decrease(){
    healthofplayer--;
    setPlainText(QString("Health: ")+ QString::number(healthofplayer));
}

int health::getHealth (){ return healthofplayer;}
