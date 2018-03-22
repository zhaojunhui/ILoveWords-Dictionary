#ifndef Test2_H
#define Test2_H

#include <QWidget>
#include <QList>
#include <QLabel>
#include <QRadioButton>
#include <QString>
#include <string>
#include "Test.h"

namespace Ui {
class Test2;
}

class Test2 : public Test
{
    Q_OBJECT

public:
    explicit Test2(Quiz* quiz, SingleWord& word, QWidget *parent = 0);
    ~Test2();

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

    Ui::Test2 *ui;
};

#endif // Test2_H
