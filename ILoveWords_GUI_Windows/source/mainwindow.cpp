#include <QString>
#include <QDebug>
#include <QInputDialog>
#include <QMessageBox>
#include <QDir>
#include <string>
#include "func.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DataBase.h"
#include "Wordbook.h"
#include "Recite.h"
#include "Query.h"
#include "Quiz.h"
using namespace std;

MainWindow::MainWindow (const QString &user, const QString &dict, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui -> setupUi(this);

    string username = user.toStdString();
    string dictname = dict.toStdString();

    wordbook_ = new WordBook (user, this);

    ui -> processor_ -> addTab (new Recite (this), tr("背单词"));
    ui -> processor_ -> addTab (new Query (user, dict, this), tr("查询"));
    ui -> processor_ -> addTab (new Quiz (user, this), tr("单词测试"));
    ui -> processor_ -> addTab (wordbook_, tr("单词本"));
    database_ = new DataBase (username, dictname);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete database_;
}

void MainWindow::closeEvent(QCloseEvent*)
{
    delete database_;
}

WordBook* MainWindow::GetWordBook() const
{
    return wordbook_;
}

void MainWindow::on_set_act_triggered()
{
    QInputDialog* input = new QInputDialog(this);
    input -> setWindowTitle(tr("设置词数")); input -> setLabelText(tr("请输入单词数目"));
    input -> setIntValue(50); input -> setIntRange(50, 300);
    if (input -> exec() == QDialog::Rejected) return;

    int num = input -> intValue();

    database_ -> SetNewWordPerDay(num);
}

void MainWindow::on_add_act_triggered()
{
    /*得到单词*/
    QInputDialog* input = new QInputDialog(this);
    input -> setWindowTitle(tr("添加例句")); input -> setLabelText(tr("请输入要添加例句的单词："));
    input -> setTextValue(tr("abandon"));
    if (input -> exec() == QDialog::Rejected) return;
    /*得到单词*/

    QString word = input -> textValue();
    string word_ = word.toStdString();  ToStdForm(word_);

    if (!(database_ -> CheckWord(word_)))
    {
        QMessageBox::StandardButton reply = QMessageBox::critical(this, tr("错误"),
                                            tr("该单词不存在，是否添加？"),
                                            QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes) on_add_word_act_triggered();
        return;
    }

    /*得到例句*/
    input = new QInputDialog(this);
    input -> setWindowTitle(tr("添加例句")); input -> setLabelText(tr("请输入要添加的例句："));
    input -> setTextValue(tr("After all, tomorrow is another day."));
    if (input -> exec() == QDialog::Rejected) return;
    /*得到例句*/
    QString sentence = input -> textValue();

    database_ -> SetSentence(word_, sentence.toStdString());
    QMessageBox::information(this, tr("添加例句"), tr("添加例句成功！"));
}

void MainWindow::on_add_word_act_triggered()
{
    /*得到单词*/
    QInputDialog* input = new QInputDialog(this);
    input -> setWindowTitle(tr("添加单词")); input -> setLabelText(tr("请输入要添加的单词："));
    input -> setTextValue(tr("ILoveWords"));
    if (input -> exec() == QDialog::Rejected) return;
    /*得到单词*/

    QString word = input -> textValue();
    string word_ = word.toStdString(); ToStdForm(word_);

    if (database_ -> CheckWord(word_))
    {
        QMessageBox::critical(this, tr("错误"), tr("该单词已存在！"));
        return;
    }

    /*得到音标*/
    input = new QInputDialog(this);
    input -> setWindowTitle(tr("添加单词")); input -> setLabelText(tr("请输入%1的音标：").arg(word_.c_str()));
    input -> setTextValue(tr("[I love words]"));
    if (input -> exec() == QDialog::Rejected) return;
    /*得到音标*/
    QString pronounce = input -> textValue();

    /*得到释义*/
    input = new QInputDialog(this);
    input -> setWindowTitle(tr("添加单词")); input -> setLabelText(tr("请输入%1的释义：").arg(word_.c_str()));
    input -> setTextValue(tr("笑着活下去"));
    if (input -> exec() == QDialog::Rejected) return;
    /*得到释义*/
    QString meaning = input -> textValue();

    database_ -> AddWord(word_, pronounce.toStdString(), meaning.toStdString());
    QMessageBox::information(this, tr("添加单词"), tr("添加单词成功！"));
}
