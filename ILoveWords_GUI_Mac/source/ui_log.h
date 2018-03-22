/********************************************************************************
** Form generated from reading UI file 'log.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_H
#define UI_LOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Log
{
public:
    QTextBrowser *textBrowser;
    QPushButton *next_btn;
    QPushButton *del_btn;
    QPushButton *del_all_btn;
    QPushButton *quit_btn;

    void setupUi(QWidget *Log)
    {
        if (Log->objectName().isEmpty())
            Log->setObjectName(QStringLiteral("Log"));
        Log->resize(254, 182);
        QIcon icon;
        icon.addFile(QStringLiteral(":/File/images/coffee.png"), QSize(), QIcon::Normal, QIcon::Off);
        Log->setWindowIcon(icon);
        textBrowser = new QTextBrowser(Log);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 20, 121, 141));
        next_btn = new QPushButton(Log);
        next_btn->setObjectName(QStringLiteral("next_btn"));
        next_btn->setGeometry(QRect(160, 20, 75, 23));
        del_btn = new QPushButton(Log);
        del_btn->setObjectName(QStringLiteral("del_btn"));
        del_btn->setGeometry(QRect(160, 60, 75, 23));
        del_all_btn = new QPushButton(Log);
        del_all_btn->setObjectName(QStringLiteral("del_all_btn"));
        del_all_btn->setGeometry(QRect(160, 100, 75, 23));
        quit_btn = new QPushButton(Log);
        quit_btn->setObjectName(QStringLiteral("quit_btn"));
        quit_btn->setGeometry(QRect(160, 140, 75, 23));

        retranslateUi(Log);

        QMetaObject::connectSlotsByName(Log);
    } // setupUi

    void retranslateUi(QWidget *Log)
    {
        Log->setWindowTitle(QApplication::translate("Log", "Log", 0));
        next_btn->setText(QApplication::translate("Log", "\344\270\213\344\270\200\351\241\265", 0));
        del_btn->setText(QApplication::translate("Log", "\345\210\240\351\231\244...", 0));
        del_all_btn->setText(QApplication::translate("Log", "\346\270\205\351\231\244\345\216\206\345\217\262", 0));
        quit_btn->setText(QApplication::translate("Log", "\350\277\224\345\233\236", 0));
    } // retranslateUi

};

namespace Ui {
    class Log: public Ui_Log {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_H
