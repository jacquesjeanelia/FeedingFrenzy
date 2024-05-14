QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    button.cpp \
    enemy.cpp \
    gameover.cpp \
    health.cpp \
    level.cpp \
    level_info.cpp \
    levels.cpp \
    main.cpp \
    mainmenu.cpp \
    player.cpp \
    score.cpp \
    seacreature.cpp \
    shop.cpp \
    victory.cpp \
    view.cpp

HEADERS += \
    button.h \
    enemy.h \
    gameover.h \
    health.h \
    level.h \
    level_info.h \
    levels.h \
    mainmenu.h \
    player.h \
    score.h \
    seacreature.h \
    shop.h \
    victory.h \
    view.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    audio.qrc \
    images.qrc \
    scores.qrc

DISTFILES += \
    score.txt \
    totalscore