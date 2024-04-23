#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsItem>

class score:public QGraphicsTextItem
{
public:

    score(QGraphicsItem* parent=0);
    int scoreofplayer = 0 ;
    void increase(int);
};



#endif // SCORE_H
