#include "view.h"

view::view(QPixmap background) {
    this->setFixedSize(800,600);
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,800,600);
    scene->setBackgroundBrush(QPixmap(background));
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setScene(scene);
}
