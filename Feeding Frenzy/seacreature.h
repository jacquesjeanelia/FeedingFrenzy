#ifndef SEACREATURE_H
#define SEACREATURE_H
#include <QPixmap>
#include <QObject>
#include <QGraphicsPixmapItem>

class seaCreature: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    seaCreature();
    seaCreature(QPixmap image,int mySize);
    void playSound(QUrl myAudio);
    int size;
};

#endif // SEACREATURE_H
