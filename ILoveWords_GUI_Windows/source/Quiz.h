#ifndef QUIZ_H
#define QUIZ_H

#include <QWidget>
#include <QSpinBox>
#include <QString>
#include <QList>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace Ui {
class Quiz;
}

class Test;
class DataBase;
class MainWindow;

class Quiz : public QWidget
{
    Q_OBJECT

public:
    explicit Quiz(const QString& user, MainWindow* wnd, QWidget *parent = 0);
    ~Quiz();

    DataBase* GetDataBase() const;

public slots:
    void StartQuiz();
    void StepRight();
    void StepWrong();
    void NextPage();

    //生成题目
    void CreateQuiz(int idx);

    //输出结果
    void Info() const;

private slots:
    void destroyTest();

private:
    void initConnect();

private:
    //3种test的数目
    int num_[3];

    //题目总数
    int sum_;

    //当前测试到的位置
    int pos_;

    //正确、错误题目的数量
    int correct_, wrong_;

    //用户名
    QString username_;

private:
    MainWindow* processor_;
    QList<QSpinBox*> num_list_;
    QList<Test*> prob_list_;

    Ui::Quiz *ui;
};

#endif // QUIZ_H
