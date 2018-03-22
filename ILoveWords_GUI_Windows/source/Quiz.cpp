#include <QMessageBox>
#include <QString>
#include <string>
#include <set>
#include "Test1.h"
#include "Test2.h"
#include "Test3.h"
#include "database.h"
#include "mainwindow.h"
#include "Word.h"
#include "Quiz.h"
#include "ui_quiz.h"
using namespace std;

Quiz::Quiz(const QString &user, MainWindow *wnd, QWidget *parent) :
    QWidget(parent), ui(new Ui::Quiz), username_ (user), processor_ (wnd),
    sum_ (0), pos_ (0), correct_ (0), wrong_ (0)
{
    ui->setupUi(this);
    num_list_.append(ui -> num1); ui -> num1 -> setRange(0, 20);
    num_list_.append(ui -> num2); ui -> num2 -> setRange(0, 20);
    num_list_.append(ui -> num3); ui -> num3 -> setRange(0, 20);
    /**
      此处需要加入范围限制！！！
    **/
    connect(ui -> start_btn, SIGNAL(clicked()), this, SLOT(StartQuiz()));
}

Quiz::~Quiz()
{
    delete ui;
    destroyTest();
}


DataBase* Quiz::GetDataBase() const
{
    return processor_ -> GetDataBase();
}


void Quiz::initConnect()
{
    for (int i = 0; i < prob_list_.size(); i++)
    {
        connect(prob_list_[i], SIGNAL(AnsRight()), this, SLOT(StepRight()));
        connect(prob_list_[i], SIGNAL(AnsWrong()), this, SLOT(StepWrong()));
        connect(prob_list_[i], SIGNAL(NextPage()), this, SLOT(NextPage()));
        connect(prob_list_[i], SIGNAL(ExitQuiz()), this, SLOT(destroyTest()));
    }
}


void Quiz::StartQuiz()
{
    for (int i = 0; i < num_list_.size(); i++)
        num_[i] = num_list_[i] -> value(), sum_ += num_[i];

    if (sum_ == 0)
    {
        QMessageBox::critical(this, tr("错误"), tr("题目总数不能为0"));
        return;
    }

    for (int i = 0; i < 3; i++) CreateQuiz(i);
    initConnect();
    if (pos_ < sum_) prob_list_[pos_] -> show();
}


void Quiz::CreateQuiz(int idx)
{
    set<string> s;
    for (int i = 0; i < num_[idx]; i++)
    {
        /**
        此处之后应该为RandReciteWord()
        **/
        SingleWord word = processor_ -> GetDataBase() -> RandWord();
        if (!s.count (word.GetWord()))
        {
            s.insert (word.GetWord());
            if (idx == 0) prob_list_.append(new Test1(this, word));
            if (idx == 1) prob_list_.append(new Test2(this, word));
            if (idx == 2) prob_list_.append(new Test3(this, word));
        } else i--;
    }
}


void Quiz::Info() const
{
    QString msg;
    msg = tr("测试结束！") + '\n'
        + tr("用户：%1").arg(username_) + '\n'
        + tr("正确：%1").arg(correct_)  + '\n'
        + tr("错误：%1").arg(wrong_)    + '\n'
        + tr("总数：%1").arg(sum_)      + '\n'
        + tr("得分：%1").arg(sum_ == 0 ? 0 : ((double)correct_ / sum_) * 100.0) + '\n';
    QMessageBox::information(NULL, tr("测试结果"), msg);
}


void Quiz::StepRight() {
    correct_++; pos_++;
}

void Quiz::StepWrong() {
    wrong_++;   pos_++;
}

void Quiz::destroyTest()
{
    for (int i = 0; i < prob_list_.size(); i++)
        delete prob_list_[i];
    prob_list_.clear();
    sum_ = correct_ = wrong_ = pos_ = 0;
}

void Quiz::NextPage()
{
    if (pos_ == sum_)
    {
        Info();
        destroyTest();
        return;
    }
    prob_list_[pos_ - 1] -> hide();
    prob_list_[pos_]     -> show();
}
