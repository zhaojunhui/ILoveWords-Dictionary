#ifndef Test3_H
#define Test3_H

#include <QWidget>
#include <QList>
#include <QLabel>
#include <QRadioButton>
#include <QString>
#include <string>
#include "Test.h"

namespace Ui {
class Test3;
}

class Test3 : public Test
{
    Q_OBJECT

public:
    explicit Test3(Quiz* quiz, SingleWord& word, QWidget *parent = 0);
    ~Test3();

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

    Ui::Test3 *ui;
};

#endif // Test3_H
