#include "seacreature.h"
#include <QAudioOutput>
#include <QMediaPlayer>

seaCreature::seaCreature(){

}
seaCreature::seaCreature(QPixmap image) {
    // set image of sea creature
    setPixmap(image);
}

void seaCreature::playSound(QUrl myAudio)
{
    QUrl audio;
    QMediaPlayer* mediaPlayer;
    QAudioOutput * output;
    audio = myAudio;
    mediaPlayer = new QMediaPlayer;
    output = new QAudioOutput;
    mediaPlayer->setAudioOutput(output);
    mediaPlayer->setSource(myAudio);
    output->setVolume(30);
    mediaPlayer->play();
}
