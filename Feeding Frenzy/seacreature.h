#ifndef SEACREATURE_H
#define SEACREATURE_H
#include <QPixmap>
#include <QObject>
#include <QGraphicsPixmapItem>

class seaCreature: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    seaCreature(QPixmap image);
    int width, length;
};

#endif // SEACREATURE_H
