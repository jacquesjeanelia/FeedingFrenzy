#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QPixmap>

class view: public QGraphicsView
{
public:
    view(QPixmap background);
    QGraphicsScene* scene;
};

#endif // VIEW_H
