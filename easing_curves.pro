QT -= \
    core \
    gui

CONFIG += \
    console

TARGET = easing_curves
TEMPLATE = app

HEADERS += *.h

SOURCES += *.cpp


HEADERS += \
    EasingCurveFunction.h


SOURCES += \
    EasingCurveFunction.cpp
