#ifndef LOGSHELL_H
#define LOGSHELL_H

#include <QWidget>

namespace Ui {
class LogShell;
}

class LogShell : public QWidget
{
    Q_OBJECT

public:
    explicit LogShell(QWidget *parent = 0);
    ~LogShell();

private:
    Ui::LogShell *ui;
};

#endif // LOGSHELL_H
