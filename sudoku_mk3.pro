#-------------------------------------------------
#
# Project created by QtCreator 2017-01-28T19:12:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sudoku_mk2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    nineSquareTable.cpp \
    sixteenSquareTable.cpp

HEADERS  += mainwindow.h \
    nineSquareTable.h \
    sixteenSquareTable.h

FORMS    += mainwindow.ui

DISTFILES += \
    sudokuTemplate.txt \
    sudokuTemplate_16.txt

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-sudoku_mk3-Desktop_Qt_5_8_0_clang_64bit-Release/release/ -lQtWidgets
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-sudoku_mk3-Desktop_Qt_5_8_0_clang_64bit-Release/debug/ -lQtWidgets
else:mac: LIBS += -F$$PWD/../build-sudoku_mk3-Desktop_Qt_5_8_0_clang_64bit-Release/ -framework QtWidgets
else:unix: LIBS += -L$$PWD/../build-sudoku_mk3-Desktop_Qt_5_8_0_clang_64bit-Release/ -lQtWidgets

INCLUDEPATH += $$PWD/../build-sudoku_mk3-Desktop_Qt_5_8_0_clang_64bit-Release
DEPENDPATH += $$PWD/../build-sudoku_mk3-Desktop_Qt_5_8_0_clang_64bit-Release
