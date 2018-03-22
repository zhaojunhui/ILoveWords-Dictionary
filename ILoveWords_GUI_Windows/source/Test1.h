#ifndef TEST1_H
#define TEST1_H

#include <QWidget>
#include <QList>
#include <QLabel>
#include <QRadioButton>
#include <QString>
#include <string>
#include "Test.h"

namespace Ui {
class Test1;
}

class Test1 : public Test
{
    Q_OBJECT

public:
    explicit Test1(Quiz* quiz, SingleWord& word, QWidget *parent = 0);
    ~Test1();

public slots:
    virtual void CheckResponse();

private:
    void initConnect();
    void CreateProb();

private:
    const int sum = 3;
    std::vector<SingleWord> list_;
    QList<QRadioButton*> btn_list_;
    QList<QLabel*> text_list_;

    Ui::Test1 *ui;
};

#endif // TEST1_H
