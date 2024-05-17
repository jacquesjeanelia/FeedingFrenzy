#include "shop.h"
#include "levels.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include "button.h"
#include "levels.h"
#include "view.h"
#include <QTime>
#include <QObject>
#include <mainmenu.h>
#include "shop.h"
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QVector>



extern mainmenu *MainMenu;
extern levels* LevelsMenu;
extern shop *ShopMenu;

QFile totalFile("C:\\Users\\jacqu\\Documents\\FeedingFrenzy - Copy\\Feeding Frenzy\\totalpoints.txt");
QFile currentFile("C:\\Users\\jacqu\\Documents\\FeedingFrenzy - Copy\\Feeding Frenzy\\currentfish.txt");
QFile ownedFile("C:\\Users\\jacqu\\Documents\\FeedingFrenzy - Copy\\Feeding Frenzy\\ownedfish.txt");

QTextStream totalIn(&totalFile);
QTextStream currentIn(&currentFile);
QTextStream ownedIn(&ownedFile);

shop::shop(QPixmap background): view(QPixmap(background),QUrl("qrc:/new/prefix1/Audio/main menu music.mp3")) {

    // shop menu
    text = new QGraphicsTextItem("SHOP");
    text->setPos((this->width()/2)-(text->boundingRect().width())/2, 100);
    mainButton = new button("MAIN MENU", 50, 50);
    scene->addItem(mainButton);
    Total->setFont(QFont("times", 28));
    Total->setDefaultTextColor(Qt::white);
    totalFile.open(QIODevice::ReadOnly);
    ownedFishString = totalIn.readLine();
    intScore = ownedFishString.toInt();
    totalFile.close();
    Total->setPlainText("Total Points: " + ownedFishString);
    Total->setPos(900,50);
    scene->addItem(Total);

    QPixmap pixmap1(":/Images/player2 large.png");
    QGraphicsPixmapItem * Fish1 = new QGraphicsPixmapItem;
    Fish1->setPixmap(pixmap1);
    Fish1->setPos(200,280);
    scene->addItem(Fish1);
    QPixmap pixmap2(":/Images/player3 large.png");
    QGraphicsPixmapItem * Fish2 = new QGraphicsPixmapItem;
    Fish2->setPixmap(pixmap2);
    Fish2->setPos(500,300);
    scene->addItem(Fish2);
    QPixmap pixmap3(":/Images/player4 large.png");
    QGraphicsPixmapItem * Fish3 = new QGraphicsPixmapItem;
    Fish3->setPixmap(pixmap3);
    Fish3->setPos(800,250);
    scene->addItem(Fish3);

    ownedFile.open(QIODevice::ReadOnly);
    bool have[3] = {false, false, false};
    for(int i = 0; i<3;i++)
    {
        QString line = ownedIn.readLine();
        if (line.contains("1")) {
            have[0] = true;
        } else if (line.contains("2")) {
            have[1] = true;
        } else if (line.contains("3")) {
            have[2] = true;
        }
    }

    ownedFile.close();
    for(int i = 0; i < 3; i++) {
        if(have[i] == false) {
            if (i == 0) {
                button* Buy1 = new button("BUY", 200, 450);
                buybuttons[0] = Buy1;
                scene->addItem(Buy1);
                QObject::connect(Buy1, &button::clicked, [this]() { this->buyItem(200); });
            } else if (i == 1) {
                button* Buy2 = new button("BUY", 500, 450);
                buybuttons[1] = Buy2;
                scene->addItem(Buy2);
                QObject::connect(Buy2, &button::clicked, [this]() { this->buyItem(400); });
            } else {
                button* Buy3 = new button("BUY", 800, 450);
                buybuttons[2] = Buy3;
                scene->addItem(Buy3);
                QObject::connect(Buy3, &button::clicked, [this]() { this->buyItem(600); });
            }
        } else {
            if (i == 0) {
                button* Select1 = new button("SELECT", 200, 450);
                scene->addItem(Select1);
                QObject::connect(Select1, &button::clicked, [this]() { this->SelectItem(200); });
            } else if (i == 1) {
                button* Select2 = new button("SELECT", 500, 450);
                scene->addItem(Select2);
                QObject::connect(Select2, &button::clicked, [this]() { this->SelectItem(400); });
            } else {
                button* Select3 = new button("SELECT", 800, 450);
                scene->addItem(Select3);
                QObject::connect(Select3, &button::clicked, [this]() { this->SelectItem(600); });
            }
        }
    }
}
void shop::buyItem(int price){

    if (intScore < price){
        QMessageBox::information(this, "Error", "You do not have sufficent funds");
    } else {
        currentFile.open(QIODevice::WriteOnly);
        ownedFile.open(QIODevice::WriteOnly | QIODevice::Append);
        QTextStream ownedOut(&ownedFile);
        QTextStream currentOut(&currentFile);
        if(price == 200) {
            currentOut<<QString::number(1);
            scene->removeItem(buybuttons[0]);
            button* Select1 = new button("SELECT", 200, 450);
            scene->addItem(Select1);
            QObject::connect(Select1, &button::clicked, [this]() { this->SelectItem(200); });
            ownedOut<<"1" << '\n';
        } else if(price == 400) {
            currentOut<<QString::number(2);
            scene->removeItem(buybuttons[1]);
            button* Select2 = new button("SELECT", 500, 450);
            scene->addItem(Select2);
            QObject::connect(Select2, &button::clicked, [this]() { this->SelectItem(400); });
            ownedOut<<"2"<< '\n';
        } else {
            ownedOut<<QString::number(3);
            scene->removeItem(buybuttons[2]);
            button* Select3 = new button("SELECT", 800, 450);
            scene->addItem(Select3);
            QObject::connect(Select3, &button::clicked, [this]() { this->SelectItem(600); });
            currentOut<<"3"<< '\n';
        }
        ownedFile.close();
        currentFile.close();
        intScore = intScore - price;
        totalFile.open(QIODevice::WriteOnly);
        QTextStream totalOut(&totalFile);
        totalOut<<QString::number(intScore);
        totalFile.close();
        Total->setPlainText("Total Points: "+ QString::number(intScore));
    }
}

void shop::SelectItem(int price) {
    currentFile.open(QIODevice::WriteOnly);
    QTextStream currentOut(&currentFile);
    if(price == 200) {
        currentOut<<QString::number(1);
    } else if(price == 400) {
        currentOut<<QString::number(2);
    } else {
        currentOut<<QString::number(3);
    }
    QMessageBox::information(this, "Fish Selected", "You have successfully selected this fish");
    currentFile.close();
}

