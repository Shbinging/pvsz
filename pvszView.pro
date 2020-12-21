QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bullet.cpp \
    card.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    object.cpp \
    plant.cpp \
    pzcreator.cpp \
    shop.cpp \
    shovel.cpp \
    timerUse.cpp \
    zombie.cpp

HEADERS += \
    bullet.h \
    card.h \
    config.h \
    mainwindow.h \
    map.h \
    object.h \
    plant.h \
    pzcreator.h \
    shop.h \
    shovel.h \
    timerUse.h \
    zombie.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    picture.qrc

DISTFILES += \
    gitUse.txt
