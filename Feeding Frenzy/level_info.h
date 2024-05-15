#ifndef LEVEL_INFO_H
#define LEVEL_INFO_H
#include <QPixmap>

class level_info
{
//    Q_OBJECT
public:
    level_info(double myDifficulty, QPixmap myEnemy1, QPixmap myEnemy2, QPixmap myEnemy3);
    double difficulty;
    QPixmap Enemies[3];
};

#endif // LEVEL_INFO_H
