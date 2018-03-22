#include <QString>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include "ui_query.h"
#include "func.h"
#include "Query.h"
#include "Log.h"
#include "Word.h"
#include "DataBase.h"
#include "mainwindow.h"

using namespace std;

Query::Query (const QString &user, const QString &dict, MainWindow* wnd, QWidget *parent) :
    QWidget(parent),  ui(new Ui::Query), processor_ (wnd), log_ (new Log ("record/querylog/" + user.toStdString() + "_log", NULL))
{
    ui->setupUi(this);
    log_ -> hide();
    initConnects();
}

Query::~Query()
{
    delete ui;
}

void Query::closeEvent(QCloseEvent *)
{
    log_ -> Save();
}

void Query::hideEvent(QHideEvent*)
{
    log_ -> Save();
}

void Query::initConnects()
{
    connect (ui -> word_btn, SIGNAL(clicked()), this, SLOT(RunWordQuery()));
    connect (ui -> file_btn, SIGNAL(clicked()), this, SLOT(RunFileQuery()));
    connect (ui -> log_btn,  SIGNAL(clicked()), this, SLOT(ShowHistory()));
}

DataBase* Query::GetDataBase() const
{
    return processor_ -> GetDataBase();
}


int Query::CalcAndNote (const string& path, bool all, vector<SingleWord>& vec)
{
    ifstream fin (path);
    if (!fin)
    {
        QMessageBox::critical(this, tr("错误"), tr("路径不合法或文件不存在"));
        fin.close();
        return -1;
    }

    //统计并查询，返回成功查询的单词数目
    int cnt = 0;
    string wrd;
    while (fin >> wrd)
    {
        /*前后去空格，不区分大小写*/
        ToStdForm(wrd);
        if (processor_ -> GetDataBase() -> CheckWord (wrd))
        {
            SingleWord word = processor_ -> GetDataBase() -> GetWord (wrd);
            if (all || word.GetFeature() == 0)
                 log_ -> AddRecord (wrd), vec.push_back (word), cnt++;
        }
    }
    fin.close();
    return cnt;
}




void Query::RunWordQuery()
{
    if (ui -> query_word -> text() == "") return;
    string cmd = ui -> query_word -> text().toStdString();

    /*前后去空格，不区分大小写*/
    ToStdForm(cmd);

    SingleWord word = processor_ -> GetDataBase() -> GetWord (cmd);

    log_ -> AddRecord (cmd);

    QString ans;
    //如果没有匹配的结果，输出相似结果
    if (!(processor_ -> GetDataBase() -> CheckWord (cmd)))
    {
        ans = tr("没有匹配的查找结果。您找的是不是：\n");
        vector<SingleWord> vec;
        processor_ -> GetDataBase() -> Similar (cmd, vec);
        for (int i = 0; i < vec.size(); i++)
            ans += (QString(vec[i].GetInfo().c_str()) + '\n');
    } else ans = word.GetInfo().c_str();

    //显示查询结果
    ui -> query_ans -> setText(ans);
    return;
}


void Query::RunFileQuery()
{
    QString path;
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog -> setWindowTitle(tr("文件位置"));
    fileDialog -> setDirectory(".");
    if(fileDialog -> exec() == QDialog::Accepted)
    {
        path = fileDialog -> selectedFiles()[0];
        ui -> query_word -> setText(path);
    } else
    {
        QMessageBox::information(NULL, tr("Path"), tr("你没有选择任何文件"));
        return;
    }

    bool all = false;
    QMessageBox::StandardButton reply = QMessageBox::question(this, tr("文件查询选项"),
                                        tr("是否对文件中所有单词进行查询？（或仅查询当前词典中的生词）"),
                                        QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) all = true;

    vector<SingleWord> vec;
    int sum = CalcAndNote (path.toStdString(), all, vec);
    if (sum != -1)
    {
        QString ans = tr("查询结果：\n文件中共有");
        QString num; num.setNum(sum);
        if (!all) ans += num + tr("个生词.\n");
        else ans += num + tr("个单词.\n");

        for (int i = 0; i < vec.size(); i++)
            ans += (QString(vec[i].GetInfo().c_str()) + '\n');

        //显示查询结果
        ui -> query_word -> setText(path);
        ui -> query_ans -> setText(ans);
     }
}

void Query::ShowHistory()
{
    log_ -> show();
}
