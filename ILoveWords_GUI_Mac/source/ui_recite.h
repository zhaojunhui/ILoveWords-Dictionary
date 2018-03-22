/********************************************************************************
** Form generated from reading UI file 'recite.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECITE_H
#define UI_RECITE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Recite
{
public:
    QLabel *label;
    QTextBrowser *textBrowser;
    QPushButton *ok_btn;
    QPushButton *not_btn;
    QPushButton *undo_btn;
    QPushButton *next_btn;
    QPushButton *add_btn;
    QCommandLinkButton *start_btn;

    void setupUi(QWidget *Recite)
    {
        if (Recite->objectName().isEmpty())
            Recite->setObjectName(QStringLiteral("Recite"));
        Recite->resize(285, 233);
        label = new QLabel(Recite);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 54, 12));
        textBrowser = new QTextBrowser(Recite);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 60, 151, 151));
        ok_btn = new QPushButton(Recite);
        ok_btn->setObjectName(QStringLiteral("ok_btn"));
        ok_btn->setGeometry(QRect(190, 70, 75, 23));
        not_btn = new QPushButton(Recite);
        not_btn->setObjectName(QStringLiteral("not_btn"));
        not_btn->setGeometry(QRect(190, 100, 75, 23));
        undo_btn = new QPushButton(Recite);
        undo_btn->setObjectName(QStringLiteral("undo_btn"));
        undo_btn->setGeometry(QRect(190, 160, 75, 23));
        next_btn = new QPushButton(Recite);
        next_btn->setObjectName(QStringLiteral("next_btn"));
        next_btn->setGeometry(QRect(190, 130, 75, 23));
        add_btn = new QPushButton(Recite);
        add_btn->setObjectName(QStringLiteral("add_btn"));
        add_btn->setGeometry(QRect(70, 20, 101, 23));
        start_btn = new QCommandLinkButton(Recite);
        start_btn->setObjectName(QStringLiteral("start_btn"));
        start_btn->setGeometry(QRect(190, 20, 81, 51));

        retranslateUi(Recite);

        QMetaObject::connectSlotsByName(Recite);
    } // setupUi

    void retranslateUi(QWidget *Recite)
    {
        Recite->setWindowTitle(QApplication::translate("Recite", "Form", 0));
        label->setText(QApplication::translate("Recite", "\350\203\214\345\215\225\350\257\215", 0));
        ok_btn->setText(QApplication::translate("Recite", "\350\256\244\350\257\206", 0));
        not_btn->setText(QApplication::translate("Recite", "\344\270\215\350\256\244\350\257\206", 0));
        undo_btn->setText(QApplication::translate("Recite", "\346\222\244\351\224\200", 0));
        next_btn->setText(QApplication::translate("Recite", "\344\270\213\344\270\200\344\270\252", 0));
        add_btn->setText(QApplication::translate("Recite", "\346\267\273\345\212\240\345\210\260\345\215\225\350\257\215\346\234\254", 0));
        start_btn->setText(QApplication::translate("Recite", "Start", 0));
    } // retranslateUi

};

namespace Ui {
    class Recite: public Ui_Recite {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECITE_H
