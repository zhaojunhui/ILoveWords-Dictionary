#ifndef RECITE_H
#define RECITE_H

#include <QWidget>
#include <string>
#include "Word.h"
#include "database.h"

namespace Ui {
class Recite;
}

class MainWindow; class WordBook;
class Recite : public QWidget
{
    Q_OBJECT

public:
    explicit Recite(MainWindow* wnd, QWidget *parent = 0);
    ~Recite();

public slots:
    void Step0();
    void StepYes();
    void StepNo();
    void Next();
    void Undo();
    void StartRecite();
    void AddToWordBook();

private:
    bool Init();
    void initConnect();

private:
    static const int threshold1 = 2;
    static const int threshold2 = 5;

    SingleWord cur_word_;
    struct tm *cur_time_;
    int period_;
    int word_period_;

    int pre_feature_;
    int cur_feature_;

    bool legal_next_;
    bool legal_undo_;
    bool legal_YN_;

    MainWindow* processor_;
    WordBook*   wordbook_;

    Ui::Recite *ui;
};

#endif // RECITE_H
