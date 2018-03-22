/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *add_act;
    QAction *set_act;
    QAction *add_word_act;
    QWidget *centralWidget;
    QTabWidget *processor_;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(330, 326);
        QIcon icon;
        icon.addFile(QStringLiteral(":/File/images/coffee.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        add_act = new QAction(MainWindow);
        add_act->setObjectName(QStringLiteral("add_act"));
        set_act = new QAction(MainWindow);
        set_act->setObjectName(QStringLiteral("set_act"));
        add_word_act = new QAction(MainWindow);
        add_word_act->setObjectName(QStringLiteral("add_word_act"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        processor_ = new QTabWidget(centralWidget);
        processor_->setObjectName(QStringLiteral("processor_"));
        processor_->setGeometry(QRect(20, 10, 291, 261));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 330, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(set_act);
        menu->addAction(add_act);
        menu->addAction(add_word_act);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "I Love Words", 0));
        add_act->setText(QApplication::translate("MainWindow", "\345\242\236\345\212\240\344\276\213\345\217\245... (&P)", 0));
        set_act->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\346\257\217\346\227\245\350\257\215\346\225\260(&D)", 0));
        add_word_act->setText(QApplication::translate("MainWindow", "\345\242\236\345\212\240\345\215\225\350\257\215... (&E)", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\351\200\211\351\241\271", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
