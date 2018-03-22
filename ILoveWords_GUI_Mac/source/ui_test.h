/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Test
{
public:
    QLabel *ans;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *Test)
    {
        if (Test->objectName().isEmpty())
            Test->setObjectName(QStringLiteral("Test"));
        Test->resize(553, 360);
        QIcon icon;
        icon.addFile(QStringLiteral(":/File/images/coffee.png"), QSize(), QIcon::Normal, QIcon::Off);
        Test->setWindowIcon(icon);
        ans = new QLabel(Test);
        ans->setObjectName(QStringLiteral("ans"));
        ans->setGeometry(QRect(340, 100, 181, 50));
        textBrowser = new QTextBrowser(Test);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(335, 170, 191, 141));

        retranslateUi(Test);

        QMetaObject::connectSlotsByName(Test);
    } // setupUi

    void retranslateUi(QWidget *Test)
    {
        Test->setWindowTitle(QApplication::translate("Test", "Test", 0));
        ans->setText(QApplication::translate("Test", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class Test: public Ui_Test {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
