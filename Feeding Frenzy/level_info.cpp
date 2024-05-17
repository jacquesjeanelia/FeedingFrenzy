#include "level_info.h"


//level info (enemy QPixmaps, difficulty - implemented later when multiple levels are created)
level_info::level_info(double myDifficulty, int maxScore, QPixmap myEnemy1, QPixmap myEnemy2, QPixmap myEnemy3) {
    difficulty = myDifficulty;
    Enemies[0] = myEnemy1;
    Enemies[1] = myEnemy2;
    Enemies[2] = myEnemy3;
    max = maxScore;
}

