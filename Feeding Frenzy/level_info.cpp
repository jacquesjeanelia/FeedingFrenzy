#include "level_info.h"

level_info::level_info(double myDifficulty, QPixmap myEnemy1, QPixmap myEnemy2, QPixmap myEnemy3) {
    difficulty = myDifficulty;
    Enemies[0] = myEnemy1;
    Enemies[1] = myEnemy2;
    Enemies[1] = myEnemy3;
}
