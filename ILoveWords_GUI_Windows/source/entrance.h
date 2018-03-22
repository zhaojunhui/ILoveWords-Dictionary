#ifndef ENTRANCE_H
#define ENTRANCE_H

#include <QWidget>

namespace Ui {
class Entrance;
}

class Entrance : public QWidget
{
    Q_OBJECT

public:
    explicit Entrance(QWidget *parent = 0);
    ~Entrance();

private slots:
    void slotDict();
    void slotLogin();

private:
    QString user_, dict_;
    Ui::Entrance *ui;
};

#endif // ENTRANCE_H
