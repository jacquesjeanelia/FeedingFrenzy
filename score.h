#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsItem>

class score:public QGraphicsRectItem
{
public:

    score(QGraphicsItem* parent=0);
    int scoreofplayer = 0 ;
    void increase(int);
    void increasebar();
    QGraphicsRectItem* progressBar;
    QGraphicsTextItem* scoreText;
};



#endif // SCORE_H
