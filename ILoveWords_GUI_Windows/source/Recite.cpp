#include <QInputDialog>
#include <QDebug>
#include <QMessageBox>
#include <string>
#include <ctime>
#include "mainwindow.h"
#include "Wordbook.h"
#include "Log.h"
#include "Recite.h"
#include "ui_recite.h"
using namespace std;

Recite::Recite(MainWindow *wnd, QWidget *parent) :
    QWidget(parent), ui(new Ui::Recite), processor_ (wnd)
{
    ui->setupUi(this);
    wordbook_ = processor_ -> GetWordBook();

    ui -> ok_btn -> setEnabled(false);
    ui -> not_btn -> setEnabled(false);
    ui -> undo_btn -> setEnabled(false);
    ui -> next_btn -> setEnabled(false);
    ui -> add_btn -> setEnabled(false);

    initConnect();
}

Recite::~Recite()
{
    delete ui;
}


bool Recite::Init()
{
    time_t time_ = time(NULL);
    cur_time_ = localtime(&time_);

    legal_next_ = legal_undo_ = legal_YN_ = false;
    ui -> next_btn -> setEnabled(false); ui -> undo_btn -> setEnabled(false);
    ui -> ok_btn -> setEnabled(false);   ui -> not_btn -> setEnabled(false);
    ui -> add_btn -> setEnabled(false);

    qDebug() << (void*)(processor_ -> GetDataBase()) << endl;
    if (processor_ -> GetDataBase() -> CheckTodayFinish(*cur_time_))
    {
        QMessageBox::information(this, tr("完成"), tr("您已完成今日任务"), QMessageBox::Ok);
        return false;
    }

    period_ = 0;
    cur_word_ = processor_ -> GetDataBase() -> GetReciteWord(*cur_time_);
    word_period_ = cur_word_.GetPeriod();
    return true;
}


void Recite::initConnect()
{
    connect(ui -> start_btn, SIGNAL(clicked()), this, SLOT(StartRecite()));
    connect(ui -> ok_btn,    SIGNAL(clicked()), this, SLOT(StepYes()));
    connect(ui -> not_btn,   SIGNAL(clicked()), this, SLOT(StepNo()));
    connect(ui -> next_btn,  SIGNAL(clicked()), this, SLOT(Next()));
    connect(ui -> undo_btn,  SIGNAL(clicked()), this, SLOT(Undo()));
    connect(ui -> add_btn,   SIGNAL(clicked()), this, SLOT(AddToWordBook()));
}


void Recite::StartRecite()
{
    processor_ -> GetDataBase() -> SetNewWord();
    ui -> start_btn -> setEnabled(false);

    ui -> ok_btn -> setEnabled(true);
    ui -> not_btn -> setEnabled(true);
    ui -> undo_btn -> setEnabled(true);

    Step0();
}


void Recite::Step0()
{
    if (!Init()) return;
    QString msg = QString((cur_word_.GetWord() + ' ' + cur_word_.GetPronnounce()).c_str());
    if (word_period_ == 1) msg += QString(cur_word_.GetSentence().c_str());

    ui -> textBrowser -> setText(msg);

    legal_YN_ = true;
    ui -> ok_btn -> setEnabled(true); ui -> not_btn -> setEnabled(true);
}

void Recite::StepYes()
{
    legal_YN_ = false;
    ui -> ok_btn -> setEnabled(false); ui -> not_btn -> setEnabled(false);
    processor_ -> GetDataBase() -> ChangeFeature(-1);
    qDebug() << cur_word_.GetFeature() << endl;

    ui -> textBrowser -> setText(cur_word_.GetInfo().c_str());
    if (period_ == 0)
    {
        if (word_period_ == 0)
        {
            QMessageBox::information(this, tr("完成"), tr("您已完成这个单词在今日的背诵，如果希望继续背诵请点击“撤销”"), QMessageBox::Ok);
            legal_next_ = legal_undo_ = true;
            ui -> next_btn -> setEnabled(true); ui -> undo_btn -> setEnabled(true);
        } else
        {
            legal_next_ = true;
            ui -> next_btn -> setEnabled(true);
            processor_ -> GetDataBase() -> SetWordPeriod(0, *cur_time_);
        }
    } else
    {
        legal_next_ = true;
        processor_ -> GetDataBase() -> SetWordPeriod(cur_word_.GetPeriod(), *cur_time_);
        ui -> next_btn -> setEnabled(true);
    }
    ui -> add_btn -> setEnabled(true);
}

void Recite::StepNo()
{
    legal_YN_ = false;
    ui -> ok_btn -> setEnabled(false); ui -> not_btn -> setEnabled(false);
    processor_ -> GetDataBase() -> ChangeFeature(1);
    qDebug() << cur_word_.GetFeature() << endl;

    if (period_ == 0 && word_period_ == 0 && cur_word_.GetSentenceNum() != 0)
    {
        ui -> textBrowser -> setText(cur_word_.GetSentence().c_str());
        period_ = 1;
        legal_YN_ = true;
        ui -> ok_btn -> setEnabled(true); ui -> not_btn -> setEnabled(true);
    } else
    {
        ui -> textBrowser -> setText(cur_word_.GetInfo().c_str());
        processor_ -> GetDataBase() -> SetWordPeriod(1, *cur_time_);
        legal_next_ = true;
        ui -> next_btn -> setEnabled(true);
        ui -> add_btn -> setEnabled(true);
    }
}


void Recite::Next()
{
    legal_next_ = false;
    ui -> next_btn -> setEnabled(false);
    if (legal_undo_)
    {
        legal_undo_ = false; ui -> undo_btn -> setEnabled(false);
        processor_ -> GetDataBase() -> SetWordPeriod(2, *cur_time_);
    }

    Step0();
}


void Recite::Undo()
{
    legal_undo_ = legal_next_ = false;
    ui -> next_btn -> setEnabled(false); ui -> undo_btn -> setEnabled(false);

    legal_next_ = true;
    ui -> next_btn -> setEnabled(true);
    processor_ -> GetDataBase() -> SetWordPeriod(cur_word_.GetPeriod(), *cur_time_);
}


void Recite::AddToWordBook()
{
    int feature = cur_word_.GetFeature();
    string word = cur_word_.GetWord();

    if (feature < threshold1) wordbook_ -> log_1_ -> AddRecord (word);
    else if (feature > threshold2) wordbook_ -> log_2_ -> AddRecord (word);
    else wordbook_ -> log_3_ -> AddRecord (word);
}
