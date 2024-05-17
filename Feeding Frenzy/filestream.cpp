#include "filestream.h"
#include <QDir>

//extern files for file input and output

QString sourcePath = QDir::currentPath();
QString totalPath =  sourcePath + "/totalpoints.txt";
QString currentPath = sourcePath + "/currentfish.txt";
QString ownedPath = sourcePath + "/ownedfish.txt";

QFile totalFile(totalPath);
QFile currentFile(currentPath);
QFile ownedFile(ownedPath);

QTextStream totalIn(&totalFile);
QTextStream currentIn(&currentFile);
QTextStream ownedIn(&ownedFile);


int totalpoints = 0;

