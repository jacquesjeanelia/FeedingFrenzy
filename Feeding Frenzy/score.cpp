#include "score.h"
#include "player.cpp"
#include <QGraphicsItem>
#include<QGraphicsTextItem>



score::score(QGraphicsItem* parent):QGraphicsRectItem(parent) {
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
    // setPlainText(QString("score: ")+ QString::number(scoreofplayer));
    // setDefaultTextColor(Qt::white);
    // setFont(QFont("Fantasy",16, QFont::Fantasy));
    // setPos(1100,30);
}

void score::increase(int sizeenemy){
    scoreofplayer=scoreofplayer+sizeenemy;
    if (scoreofplayer > 20) {
        scoreofplayer = 20;
    }
    progressBar -> setRect(200, 35, 40*scoreofplayer, 40);
    //scoreofplayer ++;
    scoreText -> setPlainText(QString("Score   ") + QString::number(scoreofplayer));
}

