#include "score.h"
#include "player.cpp"
#include <QGraphicsItem>
#include<QGraphicsTextItem>


// score in numbers and translated to progress bar
score::score(int maxScore, QGraphicsItem* parent):QGraphicsRectItem(parent) {
    setRect(200, 35, 800, 40);
    progressBar = new QGraphicsRectItem(this);
    progressBar->setRect(200, 35, 0, 40);
    progressBar->setBrush(Qt::gray);
    scoreText = new QGraphicsTextItem(this);
    scoreText -> setPlainText(QString("Score   ") + QString::number(scoreofplayer));
    scoreText -> setDefaultTextColor(Qt::gray);
    QFont scoreFont("times", 16);
    scoreFont.setBold(true);
    scoreText->setFont(scoreFont);
    scoreText->setPos(200, 3);
    max = maxScore;
}

void score::increase(int sizeenemy){
    scoreofplayer=scoreofplayer + sizeenemy;
    progressBar -> setRect(200, 35, (800/max)*scoreofplayer, 40);
    scoreText -> setPlainText(QString("Score   ") + QString::number(scoreofplayer));
}
