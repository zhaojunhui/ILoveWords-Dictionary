#ifndef QUERY_H
#define QUERY_H

#include <QWidget>
#include <QString>
#include <vector>
#include "Word.h"

class Log;
class MainWindow;
class DataBase;

namespace Ui {
class Query;
}

class Query : public QWidget
{
    Q_OBJECT

public:
    explicit Query (const QString &user, const QString &dict, MainWindow* wnd, QWidget *parent = 0);
    ~Query();

    virtual void closeEvent(QCloseEvent*);
    virtual void hideEvent(QHideEvent*);


    DataBase* GetDataBase() const;

private slots:
    void RunFileQuery();
    void RunWordQuery();
    void ShowHistory();

private:
    void initConnects();
    int CalcAndNote (const std::string& path, bool all, std::vector<SingleWord>& vec);

private:
    Ui::Query *ui;

    MainWindow* processor_;
    Log* log_;
};

#endif // QUERY_H
