TEMPLATE = app
TARGET = Starfall

QT = core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    opening.cpp \
    gamescene.cpp \
    stars.cpp

HEADERS += \
    opening.h \
    gamescene.h \
    stars.h

RESOURCES +=
