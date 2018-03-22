/********************************************************************************
** Form generated from reading UI file 'test2.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST2_H
#define UI_TEST2_H

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

class Ui_Test2
{
public:
    QLabel *label;
    QRadioButton *A;
    QRadioButton *B;
    QRadioButton *C;
    QRadioButton *D;
    QLabel *A_text;
    QLabel *B_text;
    QLabel *C_text;
    QLabel *D_text;
    QPushButton *detail_btn;
    QPushButton *next_btn;
    QTextBrowser *textBrowser;
    QLabel *test_word;
    QLabel *ans;

    void setupUi(QWidget *Test2)
    {
        if (Test2->objectName().isEmpty())
            Test2->setObjectName(QStringLiteral("Test2"));
        Test2->resize(553, 360);
        label = new QLabel(Test2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 30, 201, 16));
        A = new QRadioButton(Test2);
        A->setObjectName(QStringLiteral("A"));
        A->setGeometry(QRect(40, 110, 31, 31));
        B = new QRadioButton(Test2);
        B->setObjectName(QStringLiteral("B"));
        B->setGeometry(QRect(40, 170, 31, 21));
        C = new QRadioButton(Test2);
        C->setObjectName(QStringLiteral("C"));
        C->setGeometry(QRect(40, 230, 31, 21));
        D = new QRadioButton(Test2);
        D->setObjectName(QStringLiteral("D"));
        D->setGeometry(QRect(40, 290, 31, 21));
        A_text = new QLabel(Test2);
        A_text->setObjectName(QStringLiteral("A_text"));
        A_text->setGeometry(QRect(90, 100, 211, 61));
        B_text = new QLabel(Test2);
        B_text->setObjectName(QStringLiteral("B_text"));
        B_text->setGeometry(QRect(90, 160, 211, 51));
        C_text = new QLabel(Test2);
        C_text->setObjectName(QStringLiteral("C_text"));
        C_text->setGeometry(QRect(90, 220, 221, 51));
        D_text = new QLabel(Test2);
        D_text->setObjectName(QStringLiteral("D_text"));
        D_text->setGeometry(QRect(90, 280, 211, 61));
        detail_btn = new QPushButton(Test2);
        detail_btn->setObjectName(QStringLiteral("detail_btn"));
        detail_btn->setGeometry(QRect(330, 80, 75, 23));
        next_btn = new QPushButton(Test2);
        next_btn->setObjectName(QStringLiteral("next_btn"));
        next_btn->setGeometry(QRect(440, 80, 75, 23));
        textBrowser = new QTextBrowser(Test2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(340, 190, 181, 121));
        test_word = new QLabel(Test2);
        test_word->setObjectName(QStringLiteral("test_word"));
        test_word->setGeometry(QRect(40, 60, 271, 41));
        ans = new QLabel(Test2);
        ans->setObjectName(QStringLiteral("ans"));
        ans->setGeometry(QRect(330, 130, 191, 41));

        retranslateUi(Test2);

        QMetaObject::connectSlotsByName(Test2);
    } // setupUi

    void retranslateUi(QWidget *Test2)
    {
        Test2->setWindowTitle(QApplication::translate("Test2", "Form", 0));
        label->setText(QApplication::translate("Test2", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\344\270\213\351\235\242\345\223\252\344\270\200\344\270\252\344\270\216\346\211\200\347\273\231\344\270\255\346\226\207\347\233\270\345\214\271\351\205\215\357\274\237</span></p></body></html>", 0));
        A->setText(QApplication::translate("Test2", "A", 0));
        B->setText(QApplication::translate("Test2", "B", 0));
        C->setText(QApplication::translate("Test2", "C", 0));
        D->setText(QApplication::translate("Test2", "D", 0));
        A_text->setText(QApplication::translate("Test2", "<html><head/><body><p><span style=\" font-size:11pt;\">TextLabel</span></p></body></html>", 0));
        B_text->setText(QApplication::translate("Test2", "<html><head/><body><p><span style=\" font-size:11pt;\">TextLabel</span></p></body></html>", 0));
        C_text->setText(QApplication::translate("Test2", "<html><head/><body><p><span style=\" font-size:11pt;\">TextLabel</span></p></body></html>", 0));
        D_text->setText(QApplication::translate("Test2", "<html><head/><body><p><span style=\" font-size:11pt;\">TextLabel</span></p></body></html>", 0));
        detail_btn->setText(QApplication::translate("Test2", "\350\257\246\347\273\206\351\207\212\344\271\211", 0));
        next_btn->setText(QApplication::translate("Test2", "\344\270\213\344\270\200\351\241\265", 0));
        test_word->setText(QApplication::translate("Test2", "TextLabel", 0));
        ans->setText(QApplication::translate("Test2", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class Test2: public Ui_Test2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST2_H
