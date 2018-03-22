#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

class DataBase;

namespace Ui {
class MainWindow;
}

class WordBook;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow (const QString& user, const QString& dict, QWidget *parent = 0);
    ~MainWindow();
    DataBase* GetDataBase() const { return database_; }
    virtual void closeEvent(QCloseEvent*);
    QString GetUsername() const { return username_; }
    WordBook* GetWordBook() const;

private slots:
    void on_set_act_triggered();

    void on_add_act_triggered();

    void on_add_word_act_triggered();

private:
    Ui::MainWindow *ui;

    QString username_;
    QString dictname_;

    WordBook* wordbook_;
    DataBase* database_;
};

#endif // MAINWINDOW_H
