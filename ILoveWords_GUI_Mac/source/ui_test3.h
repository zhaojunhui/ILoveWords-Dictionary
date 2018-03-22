/********************************************************************************
** Form generated from reading UI file 'test3.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST3_H
#define UI_TEST3_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Test3
{
public:
    QLabel *label;
    QLabel *test_word;
    QLineEdit *lineEdit;
    QTextBrowser *textBrowser;
    QLabel *ans;
    QPushButton *detail_btn;
    QPushButton *next_btn;
    QPushButton *submit_btn;

    void setupUi(QWidget *Test3)
    {
        if (Test3->objectName().isEmpty())
            Test3->setObjectName(QStringLiteral("Test3"));
        Test3->resize(553, 360);
        label = new QLabel(Test3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 40, 131, 16));
        test_word = new QLabel(Test3);
        test_word->setObjectName(QStringLiteral("test_word"));
        test_word->setGeometry(QRect(60, 70, 221, 61));
        lineEdit = new QLineEdit(Test3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(60, 150, 161, 20));
        textBrowser = new QTextBrowser(Test3);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(330, 180, 191, 141));
        ans = new QLabel(Test3);
        ans->setObjectName(QStringLiteral("ans"));
        ans->setGeometry(QRect(330, 110, 191, 51));
        detail_btn = new QPushButton(Test3);
        detail_btn->setObjectName(QStringLiteral("detail_btn"));
        detail_btn->setGeometry(QRect(330, 70, 75, 23));
        next_btn = new QPushButton(Test3);
        next_btn->setObjectName(QStringLiteral("next_btn"));
        next_btn->setGeometry(QRect(440, 70, 75, 23));
        submit_btn = new QPushButton(Test3);
        submit_btn->setObjectName(QStringLiteral("submit_btn"));
        submit_btn->setGeometry(QRect(60, 200, 75, 23));

        retranslateUi(Test3);

        QMetaObject::connectSlotsByName(Test3);
    } // setupUi

    void retranslateUi(QWidget *Test3)
    {
        Test3->setWindowTitle(QApplication::translate("Test3", "Form", 0));
        label->setText(QApplication::translate("Test3", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\350\257\267\350\276\223\345\205\245\346\255\243\347\241\256\347\232\204\346\213\274\345\206\231\357\274\232</span></p></body></html>", 0));
        test_word->setText(QApplication::translate("Test3", "TextLabel", 0));
        ans->setText(QApplication::translate("Test3", "TextLabel", 0));
        detail_btn->setText(QApplication::translate("Test3", "\346\237\245\347\234\213\350\257\246\347\273\206", 0));
        next_btn->setText(QApplication::translate("Test3", "\344\270\213\344\270\200\351\241\265", 0));
        submit_btn->setText(QApplication::translate("Test3", "\346\217\220\344\272\244", 0));
    } // retranslateUi

};

namespace Ui {
    class Test3: public Ui_Test3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST3_H
