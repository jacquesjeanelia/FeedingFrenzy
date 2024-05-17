#ifndef FILESTREAM_H
#define FILESTREAM_H
#include <QString>
#include <QFile>
#include <QStandardPaths>
#include <QTextStream>

extern QString desktop;
extern QString totalPath;
extern QString currentPath;
extern QString ownedPath;

extern QFile totalFile;
extern QFile currentFile;
extern QFile ownedFile;

extern QTextStream totalIn;
extern QTextStream currentIn;
extern QTextStream ownedIn;

extern int totalpoints;

#endif // FILESTREAM_H
