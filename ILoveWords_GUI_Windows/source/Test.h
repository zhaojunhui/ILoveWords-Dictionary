#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include <QString>
#include "Word.h"

class Quiz;

namespace Ui {
class Test;
}

class Test : public QWidget
{
    Q_OBJECT

signals:
    void AnsRight();
    void AnsWrong();
    void NextPage();
    void ExitQuiz();

public slots:
    virtual void ShowDetail();

public:
    virtual ~Test();
    virtual void CheckResponse() {}
    virtual void ShowAns(bool);
    virtual void closeEvent(QCloseEvent*);

protected:
    Test(Quiz* quiz, SingleWord& word, QWidget *parent = 0);

    Quiz *quiz_;
    QString ans_;
    SingleWord cur_word_;

    Ui::Test *ui;
};

#endif // TEST_H
