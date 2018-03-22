/********************************************************************************
** Form generated from reading UI file 'wordbook.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORDBOOK_H
#define UI_WORDBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WordBook
{
public:
    QTabWidget *tabWidget;

    void setupUi(QWidget *WordBook)
    {
        if (WordBook->objectName().isEmpty())
            WordBook->setObjectName(QStringLiteral("WordBook"));
        WordBook->resize(291, 238);
        tabWidget = new QTabWidget(WordBook);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 251, 211));

        retranslateUi(WordBook);

        QMetaObject::connectSlotsByName(WordBook);
    } // setupUi

    void retranslateUi(QWidget *WordBook)
    {
        WordBook->setWindowTitle(QApplication::translate("WordBook", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class WordBook: public Ui_WordBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORDBOOK_H
