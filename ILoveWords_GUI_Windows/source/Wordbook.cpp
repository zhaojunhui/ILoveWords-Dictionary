#include "Wordbook.h"
#include "ui_wordbook.h"
#include "Log.h"

WordBook::WordBook(const QString& user, MainWindow* wnd, QWidget *parent) :
    QWidget(parent), ui(new Ui::WordBook), username_ (user), processor_ (wnd)
{
    ui->setupUi(this);
    log_1_ = new Log (("record/wordbook/book1/" + username_ + "_book1").toStdString());
    log_2_ = new Log (("record/wordbook/book2/" + username_ + "_book2").toStdString());
    log_3_ = new Log (("record/wordbook/book3/" + username_ + "_book3").toStdString());
    ui -> tabWidget -> addTab(log_1_, tr("不熟词"));
    ui -> tabWidget -> addTab(log_2_, tr("陌生词"));
    ui -> tabWidget -> addTab(log_3_, tr("易忘词"));
}

WordBook::~WordBook()
{
    delete ui;
}

