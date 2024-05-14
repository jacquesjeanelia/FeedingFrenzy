#include "view.h"
// abstract data type for all screens
view::view(QPixmap background, QUrl myAudio) {
    //setup the view
    this->setFixedSize(1200,700);
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0 ,1200,700);
    scene->setBackgroundBrush(QPixmap(background));
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setScene(scene);

    audio = myAudio;
    mediaPlayer = new QMediaPlayer;
    output = new QAudioOutput;
    mediaPlayer->setAudioOutput(output);
    mediaPlayer->setSource(myAudio);
    output->setVolume(20);

}

void view::mediaPlay()
{
    mediaPlayer->play();
}

void view::mediaStop()
{
    mediaPlayer->stop();
}