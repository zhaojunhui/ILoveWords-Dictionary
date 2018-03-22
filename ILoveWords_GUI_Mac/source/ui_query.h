/********************************************************************************
** Form generated from reading UI file 'query.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERY_H
#define UI_QUERY_H

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

class Ui_Query
{
public:
    QLineEdit *query_word;
    QLabel *label;
    QTextBrowser *query_ans;
    QPushButton *word_btn;
    QPushButton *file_btn;
    QPushButton *log_btn;

    void setupUi(QWidget *Query)
    {
        if (Query->objectName().isEmpty())
            Query->setObjectName(QStringLiteral("Query"));
        Query->resize(276, 232);
        query_word = new QLineEdit(Query);
        query_word->setObjectName(QStringLiteral("query_word"));
        query_word->setGeometry(QRect(20, 50, 241, 31));
        label = new QLabel(Query);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 20, 151, 16));
        query_ans = new QTextBrowser(Query);
        query_ans->setObjectName(QStringLiteral("query_ans"));
        query_ans->setGeometry(QRect(20, 90, 241, 91));
        word_btn = new QPushButton(Query);
        word_btn->setObjectName(QStringLiteral("word_btn"));
        word_btn->setGeometry(QRect(20, 190, 81, 23));
        file_btn = new QPushButton(Query);
        file_btn->setObjectName(QStringLiteral("file_btn"));
        file_btn->setGeometry(QRect(100, 190, 81, 23));
        log_btn = new QPushButton(Query);
        log_btn->setObjectName(QStringLiteral("log_btn"));
        log_btn->setGeometry(QRect(180, 190, 81, 23));

        retranslateUi(Query);

        QMetaObject::connectSlotsByName(Query);
    } // setupUi

    void retranslateUi(QWidget *Query)
    {
        Query->setWindowTitle(QApplication::translate("Query", "Form", 0));
        label->setText(QApplication::translate("Query", "<html><head/><body><p><span style=\" font-size:14pt;\">\350\257\267\345\234\250\346\255\244\350\276\223\345\205\245\346\237\245\350\257\242\345\215\225\350\257\215\357\274\232</span></p></body></html>", 0));
        word_btn->setText(QApplication::translate("Query", "\345\215\225\350\257\215\346\237\245\350\257\242", 0));
        file_btn->setText(QApplication::translate("Query", "\346\226\207\344\273\266\346\237\245\350\257\242", 0));
        log_btn->setText(QApplication::translate("Query", "\346\237\245\347\234\213\345\216\206\345\217\262", 0));
    } // retranslateUi

};

namespace Ui {
    class Query: public Ui_Query {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERY_H
