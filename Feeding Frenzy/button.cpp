#include "button.h"
#include <QFont>


//buttons to switch from screen to screen
button::button(QString message, int x, int y) {

    this->setRect(0, 0, 200, 100);
    title = new QGraphicsTextItem(message,this);
    QFont font("Jersey", 25, QFont::DemiBold);
    title->setFont(font);
    int xTitle = rect().width()/2 - title->boundingRect().width()/2;
    int yTitle = rect().height()/2 - title->boundingRect().height()/2;
    QBrush brush;
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);
    setBrush(brush);

    title->setPos(xTitle,yTitle);
    title->show();
    title->setDefaultTextColor(Qt::white);
    setAcceptHoverEvents(true);
    setAcceptTouchEvents(true);

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    setPos(x,y);



}
void clicked(){
}
//mouse pressed event
void button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QMediaPlayer *buttonClickPlayer = new QMediaPlayer;
    QAudioOutput *buttonClickOutput = new QAudioOutput;

    buttonClickPlayer->setAudioOutput(buttonClickOutput);
    buttonClickPlayer->setSource(QUrl("qrc:/new/prefix1/Audio/big bubble.mp3"));
    buttonClickPlayer->play();
    emit clicked();
}

//mouse hover event
void button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QMediaPlayer *buttonHoverPlayer = new QMediaPlayer;
    QAudioOutput *buttonHoverOutput = new QAudioOutput;

    buttonHoverPlayer->setAudioOutput(buttonHoverOutput);
    buttonHoverPlayer->setSource(QUrl("qrc:/new/prefix1/Audio/small bubble.mp3"));
    buttonHoverPlayer->play();
    QBrush brush;
    brush.setColor(Qt::lightGray);
    brush.setStyle(Qt::SolidPattern);
    setBrush(brush);
}
void button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setColor(Qt::blue);
    brush.setStyle(Qt::SolidPattern);
    setBrush(brush);
}

void button::playSound(QUrl myAudio)
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
