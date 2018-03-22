/********************************************************************************
** Form generated from reading UI file 'entrance.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTRANCE_H
#define UI_ENTRANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Entrance
{
public:
    QPushButton *login_btn;
    QLineEdit *username;
    QLabel *label;
    QLabel *label_3;
    QPushButton *dict_btn;

    void setupUi(QWidget *Entrance)
    {
        if (Entrance->objectName().isEmpty())
            Entrance->setObjectName(QStringLiteral("Entrance"));
        Entrance->resize(356, 145);
        QIcon icon;
        icon.addFile(QStringLiteral(":/File/images/coffee.png"), QSize(), QIcon::Normal, QIcon::Off);
        Entrance->setWindowIcon(icon);
        login_btn = new QPushButton(Entrance);
        login_btn->setObjectName(QStringLiteral("login_btn"));
        login_btn->setGeometry(QRect(210, 90, 81, 31));
        username = new QLineEdit(Entrance);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(90, 50, 221, 31));
        label = new QLabel(Entrance);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 50, 54, 31));
        label_3 = new QLabel(Entrance);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(160, 10, 61, 31));
        dict_btn = new QPushButton(Entrance);
        dict_btn->setObjectName(QStringLiteral("dict_btn"));
        dict_btn->setGeometry(QRect(70, 90, 81, 31));

        retranslateUi(Entrance);

        QMetaObject::connectSlotsByName(Entrance);
    } // setupUi

    void retranslateUi(QWidget *Entrance)
    {
        Entrance->setWindowTitle(QApplication::translate("Entrance", "Login", 0));
        login_btn->setText(QApplication::translate("Entrance", "\347\231\273\345\275\225", 0));
        label->setText(QApplication::translate("Entrance", "<html><head/><body><p><span style=\" font-family:'\351\273\221\344\275\223 Arial'; font-size:11pt;\">\347\224\250\346\210\267\345\220\215</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("Entrance", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Login</span></p></body></html>", 0));
        dict_btn->setText(QApplication::translate("Entrance", "\351\200\211\346\213\251\350\257\215\345\205\270", 0));
    } // retranslateUi

};

namespace Ui {
    class Entrance: public Ui_Entrance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTRANCE_H
