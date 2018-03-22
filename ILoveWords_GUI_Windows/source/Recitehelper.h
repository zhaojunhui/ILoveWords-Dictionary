#ifndef RECITEHELPER_H
#define RECITEHELPER_H

#include <QWidget>

namespace Ui {
class ReciteHelper;
}

class Recite;
class ReciteHelper : public QWidget
{
    Q_OBJECT

public:
    explicit ReciteHelper(QWidget *parent = 0);
    ~ReciteHelper();

private:

    Recite* recite;

    Ui::ReciteHelper *ui;
};

#endif // RECITEHELPER_H
