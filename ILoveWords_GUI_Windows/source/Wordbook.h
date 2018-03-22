#ifndef WORDBOOK_H
#define WORDBOOK_H

#include <QWidget>

namespace Ui {
class WordBook;
}

class MainWindow;
class Log;

class WordBook : public QWidget
{
    Q_OBJECT
public:
    explicit WordBook(const QString& user, MainWindow* wnd, QWidget *parent = 0);
    ~WordBook();
    Log *log_1_, *log_2_, *log_3_;

private:
    QString username_;

    MainWindow* processor_;
    Ui::WordBook *ui;
};

#endif // WORDBOOK_H
