/********************************************************************************
** Form generated from reading UI file 'quiz.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUIZ_H
#define UI_QUIZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Quiz
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QSpinBox *num1;
    QSpinBox *num2;
    QSpinBox *num3;
    QPushButton *start_btn;

    void setupUi(QWidget *Quiz)
    {
        if (Quiz->objectName().isEmpty())
            Quiz->setObjectName(QStringLiteral("Quiz"));
        Quiz->resize(281, 243);
        label = new QLabel(Quiz);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(100, 20, 121, 21));
        label_2 = new QLabel(Quiz);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 60, 91, 16));
        label_3 = new QLabel(Quiz);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 110, 101, 16));
        label_4 = new QLabel(Quiz);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 160, 121, 16));
        num1 = new QSpinBox(Quiz);
        num1->setObjectName(QStringLiteral("num1"));
        num1->setGeometry(QRect(200, 60, 42, 22));
        num2 = new QSpinBox(Quiz);
        num2->setObjectName(QStringLiteral("num2"));
        num2->setGeometry(QRect(200, 100, 42, 22));
        num3 = new QSpinBox(Quiz);
        num3->setObjectName(QStringLiteral("num3"));
        num3->setGeometry(QRect(200, 150, 42, 22));
        start_btn = new QPushButton(Quiz);
        start_btn->setObjectName(QStringLiteral("start_btn"));
        start_btn->setGeometry(QRect(110, 190, 75, 23));

        retranslateUi(Quiz);

        QMetaObject::connectSlotsByName(Quiz);
    } // setupUi

    void retranslateUi(QWidget *Quiz)
    {
        Quiz->setWindowTitle(QApplication::translate("Quiz", "Form", 0));
        label->setText(QApplication::translate("Quiz", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">\350\257\267\351\200\211\346\213\251\351\242\230\347\233\256\346\225\260\351\207\217\357\274\232</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("Quiz", "\351\242\230\345\236\213I(\350\213\261\350\257\221\346\261\211)\357\274\232", 0));
        label_3->setText(QApplication::translate("Quiz", "\351\242\230\345\236\213II\357\274\210\346\261\211\350\257\221\350\213\261\357\274\211\357\274\232", 0));
        label_4->setText(QApplication::translate("Quiz", "\351\242\230\345\236\213II\357\274\210\345\215\225\350\257\215\346\213\274\345\206\231\357\274\211\357\274\232", 0));
        start_btn->setText(QApplication::translate("Quiz", "\345\274\200\345\247\213\347\255\224\351\242\230", 0));
    } // retranslateUi

};

namespace Ui {
    class Quiz: public Ui_Quiz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUIZ_H
