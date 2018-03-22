#-------------------------------------------------
#
# Project created by QtCreator 2016-05-17T10:33:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ILoveWords
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    entrance.cpp \
    Word.cpp \
    Database.cpp \
    Query.cpp \
    Quiz.cpp \
    Test.cpp \
    Test1.cpp \
    Test2.cpp \
    Test3.cpp \
    Recite.cpp \
    Wordbook.cpp \
    Log.cpp

HEADERS  += mainwindow.h \
    entrance.h \
    Word.h \
    Database.h \
    Query.h \
    func.h \
    Quiz.h \
    Test.h \
    Test1.h \
    Test2.h \
    Test3.h \
    Recite.h \
    Wordbook.h \
    Log.h

FORMS    += mainwindow.ui \
    entrance.ui \
    query.ui \
    quiz.ui \
    test.ui \
    test1.ui \
    test2.ui \
    test3.ui \
    recite.ui \
    wordbook.ui \
    log.ui

DISTFILES += \
    CET4.txt

RESOURCES += \
    icon.qrc \
    img.qrc

RC_FILE += coffee.rc
