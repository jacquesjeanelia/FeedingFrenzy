#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>
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
public slots:
    void mediaPlay();
    void mediaStop();

};

#endif // VIEW_H
