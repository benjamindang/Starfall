TEMPLATE = app
TARGET = Baloons

QT = core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    opening.cpp

HEADERS += \
    opening.h
