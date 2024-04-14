QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    button.cpp \
    enemy.cpp \
    level.cpp \
    levels.cpp \
    main.cpp \
    mainmenu.cpp \
    player.cpp \
    seacreature.cpp \
    shop.cpp \
    view.cpp

HEADERS += \
    button.h \
    enemy.h \
    level.h \
    levels.h \
    mainmenu.h \
    player.h \
    seacreature.h \
    shop.h \
    view.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    multimedia.qrc
