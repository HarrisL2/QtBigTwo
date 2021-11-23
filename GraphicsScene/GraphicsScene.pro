QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    client/basecard.cpp \
    client/combination.cpp \
    client/mainwindow.cpp \
    client/playingcard.cpp \
    main.cpp \
    server/client.cpp \
    server/gameengine.cpp \
    server/server.cpp \
    server/worker.cpp \
    ui/tablegraphics.cpp \
    ui/visualcard.cpp \
    ui/visualhand.cpp

HEADERS += \
    client/basecard.h \
    client/combination.h \
    client/mainwindow.h \
    client/playingcard.h \
    server/client.h \
    server/gameengine.h \
    server/server.h \
    server/worker.h \
    ui/tablegraphics.h \
    ui/visualcard.h \
    ui/visualhand.h

FORMS += \
    client/mainwindow.ui
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
