#include "score.h"
#include "player.cpp"
#include <QGraphicsItem>
#include<QGraphicsTextItem>



score::score(QGraphicsItem* parent):QGraphicsTextItem(parent) {
    setPlainText(QString("score: ")+ QString::number(scoreofplayer));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}
void score::increase(int sizeenemy){
    scoreofplayer=scoreofplayer+sizeenemy;
    //scoreofplayer ++;
    setPlainText(QString("score: ")+ QString::number(scoreofplayer));
}

