#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsItem>

class score:public QGraphicsRectItem
{
public:

    score(int maxScore, QGraphicsItem* parent=0);
    int scoreofplayer = 0 ;
    int max;
    void increase(int);
    void increasebar();
    QGraphicsRectItem* progressBar;
    QGraphicsTextItem* scoreText;
};



#endif // SCORE_H
