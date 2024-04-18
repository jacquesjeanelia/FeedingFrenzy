#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QPixmap>
#include <QtMultimediaWidgets/QtMultimediaWidgets>
#include <QtMultimedia/QtMultimedia>
#include <QMediaPlayer>

class view: public QGraphicsView
{
    Q_OBJECT
public:
    view(QPixmap background, QUrl myAudio);
    QGraphicsScene* scene;
    QUrl audio;
    QMediaPlayer* mediaPlayer;
    QAudioOutput * output;
};

#endif // VIEW_H
