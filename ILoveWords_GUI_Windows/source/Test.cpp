#include <QMessageBox>
#include "Test.h"
#include "ui_test.h"

Test::Test(Quiz* quiz, SingleWord& word, QWidget *parent) :
    QWidget(parent), ui(new Ui::Test), quiz_ (quiz), cur_word_ (word)
{
    ui->setupUi(this);
    ui -> ans -> hide();
    ui -> textBrowser -> hide();
}

Test::~Test()
{
    delete ui;
}

void Test::closeEvent(QCloseEvent*)
{
    emit ExitQuiz();
}

void Test::ShowAns (bool isCorrect)
{
    QString msg = tr("正确答案：") + ans_ + '\n';
    if (isCorrect) msg += tr("恭喜！本题正确");
    else           msg += tr("本题错误");
    ui -> ans -> setText(msg);
    ui -> ans -> show();
}

void Test::ShowDetail()
{
    ui -> textBrowser -> setText(cur_word_.GetInfo().c_str());
    ui -> textBrowser -> show();
}
