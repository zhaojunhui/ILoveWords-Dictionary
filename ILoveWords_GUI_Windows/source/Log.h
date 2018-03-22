#ifndef LOG_H
#define LOG_H

#include <QWidget>
#include <QDebug>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::ostream;
using std::endl;

struct Record
{
    string word;
    bool isSaved;

    Record (const string& wrd, bool save = true) :
        word (wrd), isSaved (save) {}
};

ostream& operator<< (ostream& out, const Record& rcd);


namespace Ui {
class Log;
}


class Log : public QWidget
{
    Q_OBJECT

public:
    explicit Log(const string& filename, QWidget *parent = 0, int num = 10);
    ~Log();

    virtual void closeEvent(QCloseEvent*);
    virtual void hideEvent(QHideEvent*);
    virtual void showEvent(QShowEvent*);

public:
    //每次显示的历史记录数量的上限
    const static int MAX = 200;

    //设置每次显示的记录数量
    void SetNum (int num) { num_ = num; }

    //当前每次显示的记录数量
    int GetNum() const { return num_; }

    //增加历史记录
    void AddRecord (const string& word)
        { data_.push_back (Record (word)); }

    //初始化
    void Initialize();

    //将历史记录保存
    void Save();

public slots:
    //显示历史记录，flag表示是否输出详细信息
    void ShowHistory (bool flag = true);

    //删除历史记录key
    void DelRecord();

    //删除全部历史记录
    void DelAll();

private:
    //只保存最近1000条历史记录
    const int kSize = 1000;

    //每次显示的数量
    int num_;

    void initConnect();

private:
    string filename_;
    vector<Record> data_;

    //上次查询到的位置，每次退出查询时重新设定为开头
    int pos_;

private:
    Ui::Log *ui;
};

#endif // LOG_H
