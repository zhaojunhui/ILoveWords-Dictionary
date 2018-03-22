#include <QString>
#include <cstdlib>
#include "Test1.h"
#include "Word.h"
#include "Quiz.h"
#include "DataBase.h"
#include "ui_test1.h"


extern myrand ran;

Test1::Test1(Quiz *quiz, SingleWord &word, QWidget *parent) :
    Test(quiz, word), ui(new Ui::Test1)
{
    ui->setupUi(this);
    btn_list_.append(ui -> A); text_list_.append(ui -> A_text);
    btn_list_.append(ui -> B); text_list_.append(ui -> B_text);
    btn_list_.append(ui -> C); text_list_.append(ui -> C_text);
    btn_list_.append(ui -> D); text_list_.append(ui -> D_text);
    for (int i = 0; i < 4; i++)
        text_list_[i] -> setWordWrap(true);

    ui -> ans -> hide();
    ui -> textBrowser -> hide();
    ui -> detail_btn -> setEnabled(false);
    ui -> next_btn -> setEnabled(false);

    CreateProb();
    initConnect();
}

Test1::~Test1()
{
    delete ui;
}


void Test1::initConnect()
{
    for (int i = 0; i < btn_list_.size(); i++)
        connect(btn_list_[i], SIGNAL(clicked()), this, SLOT(CheckResponse()));
    connect(ui -> detail_btn, SIGNAL(clicked()), this, SLOT(ShowDetail()));
    connect(ui -> next_btn,   SIGNAL(clicked()), this, SIGNAL(NextPage()));
}

void Test1::CreateProb()
{
    ui -> test_word -> setText(QString(cur_word_.GetWord().c_str()));
    quiz_ -> GetDataBase() -> Similar(cur_word_.GetWord(), list_);


    int num = ran.rand() % 4;
    char cnt = 'A';
    ans_ = (QChar)(cnt + num);
    for (int i = 0; i < num; ++i)
        text_list_[i] -> setText(' ' + QString(list_[i + 1].GetMeaning().c_str()) + '\n');
        text_list_[num] -> setText(' ' + QString(list_[0].GetMeaning().c_str()) + '\n');
    for (int i = num + 1; i <= sum; ++i)
        text_list_[i] -> setText(' ' + QString(list_[i].GetMeaning().c_str()) + '\n');
}


void Test1::CheckResponse()
{
    QString checked = this -> sender() -> objectName();
    if (checked != ans_)
    {
        emit AnsWrong();
        this -> ShowAns(false);
    } else
    {
        emit AnsRight();
        this -> ShowAns(true);
    }
    ui -> detail_btn -> setEnabled(true);
    ui -> next_btn -> setEnabled(true);
    for (int i = 0; i < btn_list_.size(); i++)
        btn_list_[i] -> setEnabled(false);
}
