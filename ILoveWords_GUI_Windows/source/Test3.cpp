#include <QString>
#include <cstdlib>
#include <string>
#include "Test3.h"
#include "Word.h"
#include "Quiz.h"
#include "DataBase.h"
#include "ui_Test3.h"
using namespace std;

Test3::Test3(Quiz *quiz, SingleWord &word, QWidget *parent) :
    Test(quiz, word), ui(new Ui::Test3)
{
    ui->setupUi(this);

    ui -> ans -> hide();
    ui -> textBrowser -> hide();
    ui -> detail_btn -> setEnabled(false);
    ui -> next_btn -> setEnabled(false);

    ans_ = cur_word_.GetWord().c_str();
    ui -> test_word -> setWordWrap(true);
    ui -> test_word -> setText((cur_word_.GetPronnounce() + '\n' + cur_word_.GetMeaning()).c_str());
    initConnect();
}

Test3::~Test3()
{
    delete ui;
}


void Test3::initConnect()
{
    connect(ui -> submit_btn, SIGNAL(clicked()), this, SLOT(CheckResponse()));
    connect(ui -> detail_btn, SIGNAL(clicked()), this, SLOT(ShowDetail()));
    connect(ui -> next_btn,   SIGNAL(clicked()), this, SIGNAL(NextPage()));
}

void Test3::CheckResponse()
{
    QString checked = ui -> lineEdit->text();
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
