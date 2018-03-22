/********************************************************************************
** Form generated from reading UI file 'test1.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST1_H
#define UI_TEST1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Test1
{
public:
    QRadioButton *A;
    QLabel *label;
    QRadioButton *B;
    QRadioButton *C;
    QRadioButton *D;
    QLabel *test_word;
    QPushButton *detail_btn;
    QPushButton *next_btn;
    QLabel *A_text;
    QLabel *B_text;
    QLabel *C_text;
    QLabel *D_text;
    QLabel *ans;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *Test1)
    {
        if (Test1->objectName().isEmpty())
            Test1->setObjectName(QStringLiteral("Test1"));
        Test1->resize(553, 360);
        A = new QRadioButton(Test1);
        A->setObjectName(QStringLiteral("A"));
        A->setGeometry(QRect(40, 80, 31, 31));
        label = new QLabel(Test1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 20, 231, 16));
        B = new QRadioButton(Test1);
        B->setObjectName(QStringLiteral("B"));
        B->setGeometry(QRect(40, 140, 31, 31));
        C = new QRadioButton(Test1);
        C->setObjectName(QStringLiteral("C"));
        C->setGeometry(QRect(40, 200, 41, 41));
        D = new QRadioButton(Test1);
        D->setObjectName(QStringLiteral("D"));
        D->setGeometry(QRect(40, 270, 41, 31));
        test_word = new QLabel(Test1);
        test_word->setObjectName(QStringLiteral("test_word"));
        test_word->setGeometry(QRect(40, 50, 91, 31));
        detail_btn = new QPushButton(Test1);
        detail_btn->setObjectName(QStringLiteral("detail_btn"));
        detail_btn->setGeometry(QRect(340, 50, 81, 23));
        next_btn = new QPushButton(Test1);
        next_btn->setObjectName(QStringLiteral("next_btn"));
        next_btn->setGeometry(QRect(440, 50, 71, 23));
        A_text = new QLabel(Test1);
        A_text->setObjectName(QStringLiteral("A_text"));
        A_text->setGeometry(QRect(80, 70, 231, 71));
        B_text = new QLabel(Test1);
        B_text->setObjectName(QStringLiteral("B_text"));
        B_text->setGeometry(QRect(80, 130, 231, 71));
        C_text = new QLabel(Test1);
        C_text->setObjectName(QStringLiteral("C_text"));
        C_text->setGeometry(QRect(80, 190, 231, 81));
        D_text = new QLabel(Test1);
        D_text->setObjectName(QStringLiteral("D_text"));
        D_text->setGeometry(QRect(80, 260, 231, 71));
        ans = new QLabel(Test1);
        ans->setObjectName(QStringLiteral("ans"));
        ans->setGeometry(QRect(340, 100, 181, 51));
        textBrowser = new QTextBrowser(Test1);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(335, 170, 191, 141));

        retranslateUi(Test1);

        QMetaObject::connectSlotsByName(Test1);
    } // setupUi

    void retranslateUi(QWidget *Test1)
    {
        Test1->setWindowTitle(QApplication::translate("Test1", "Form", 0));
        A->setText(QApplication::translate("Test1", "A", 0));
        label->setText(QApplication::translate("Test1", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\344\270\213\345\210\227\345\223\252\344\270\200\344\270\252\346\230\257\346\211\200\347\273\231\345\215\225\350\257\215\347\232\204\344\270\255\346\226\207\351\207\212\344\271\211\357\274\237</span></p></body></html>", 0));
        B->setText(QApplication::translate("Test1", "B", 0));
        C->setText(QApplication::translate("Test1", "C", 0));
        D->setText(QApplication::translate("Test1", "D", 0));
        test_word->setText(QApplication::translate("Test1", "TextLabel", 0));
        detail_btn->setText(QApplication::translate("Test1", "\350\257\246\347\273\206\351\207\212\344\271\211", 0));
        next_btn->setText(QApplication::translate("Test1", "\344\270\213\344\270\200\351\242\230", 0));
        A_text->setText(QApplication::translate("Test1", "TextLabel", 0));
        B_text->setText(QApplication::translate("Test1", "TextLabel", 0));
        C_text->setText(QApplication::translate("Test1", "TextLabel", 0));
        D_text->setText(QApplication::translate("Test1", "TextLabel", 0));
        ans->setText(QApplication::translate("Test1", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class Test1: public Ui_Test1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST1_H
