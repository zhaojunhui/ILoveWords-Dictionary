#include <QMessageBox>
#include <QInputDialog>
#include <QDebug>
#include <iostream>
#include <algorithm>
#include <fstream>
#include "Log.h"
#include "Word.h"
#include "DataBase.h"
#include "ui_Log.h"

using namespace std;

ostream& operator<< (ostream& out, const Record& rcd)
{
    out << rcd.word;
    return out;
}



Log::Log(const std::string &filename, QWidget *parent, int num) :
    QWidget(parent), ui(new Ui::Log),
    filename_ (filename), num_ (num)
{
    ui -> setupUi(this);
    Initialize();
    initConnect();
}

Log::~Log()
{
    delete ui;
}

void Log::closeEvent(QCloseEvent*) {
    Save();
}

void Log::hideEvent(QHideEvent *) {
    Save();
}

void Log::showEvent(QShowEvent *) {
    Save();
    Initialize();
    ShowHistory();
}

void Log::initConnect()
{
    connect (ui -> next_btn,    SIGNAL(clicked()), this, SLOT(ShowHistory()));
    connect (ui -> del_btn,     SIGNAL(clicked()), this, SLOT(DelRecord()));
    connect (ui -> del_all_btn, SIGNAL(clicked()), this, SLOT(DelAll()));
    connect (ui -> quit_btn,    SIGNAL(clicked()), this, SLOT(close()));
}

void Log::Initialize()
{
    ifstream fin (filename_);
    data_.clear();

    //当文件存在时导入历史记录
    string record;

    if (fin)
    while (std::getline (fin, record))
    {
        data_.push_back (record);
    }
    fin.close();

    //输出时输出最新的num_条记录
    pos_ = data_.size();

    //如果历史记录为空则标记为无历史记录
    if (pos_ == 0) pos_ = -1;

    ui -> next_btn -> setEnabled(true);
    ui -> del_btn -> setEnabled(true);
    ui -> del_all_btn -> setEnabled(true);
    ui -> quit_btn -> setEnabled(true);
}



void Log::ShowHistory (bool flag)
{
    //如果没有更多的历史记录就退出
    if (pos_ == -1)
    {
        if (flag) QMessageBox::information(this, tr("历史记录"), tr("没有更多的记录了！"), QMessageBox::Ok);
        ui -> textBrowser -> setText("");
        ui -> del_btn -> setEnabled(false);
        return;
    }

    //从标记位置开始输出10条记录
    pos_ = max (0, pos_ - num_);
    QString msg;

    //设置标记位置
    int tail = min (pos_ + num_ - 1, int(data_.size() - 1));
    for (int i = tail, j = 1; i >= pos_; i--, j++)
    {
        QString num; num.setNum(j);
        msg += '[' + num + ']' + ' ';
        msg += QString(data_[i].word.c_str()) + '\n';
    }

    ui -> textBrowser -> setText(msg);
    //如果历史记录已经全部输出则做标记“无更多历史记录”
    if (pos_ == 0) pos_ = -1;
}


void Log::DelRecord()
{
    QString num = QInputDialog::getText(this, tr("删除"), tr("请输入需要删除的历史记录的标号"),
                                        QLineEdit::Normal, tr("0"));
    if (num == "") return;

    QMessageBox::StandardButton reply = QMessageBox::question(this, tr("确认删除"), tr("确定删除历史记录[%1]吗？").arg(num),
                                        QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) return;

    int key = num.toInt(); key--;
    //找到要删除的历史记录在vector中的位置
    int idx = min (pos_ + num_ - 1, int(data_.size() - 1)) - key;
    if (pos_ == -1 && idx == pos_ + num_ - 1 - key) idx++;
    if (idx < data_.size() && idx >= 0 && key < num_)
    {
        QMessageBox::information(this, tr("删除"), tr("历史记录[%1]已删除，下次查看时将不再显示").arg(num),
                                        QMessageBox::Ok);
        data_[idx].isSaved = false;
    }
    else QMessageBox::critical(this, tr("错误"), tr("历史记录%1不存在").arg(num));
}


void Log::DelAll()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, tr("确认删除"), tr("确定清空历史记录吗？"),
                                        QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::No) return;

    data_.clear(); pos_ = -1;
    QMessageBox::information(this, tr("删除"), tr("历史记录已清除"),
                                    QMessageBox::Ok);
    ui -> textBrowser -> setText("");
}


void Log::Save()
{
    ofstream fout (filename_);
    int start = (data_.size() > kSize) ? (data_.size() - kSize) : 0;
    for (int i = start; i < data_.size(); i++) if (data_[i].isSaved)
        fout << data_[i] << endl;
    fout.close();
}

