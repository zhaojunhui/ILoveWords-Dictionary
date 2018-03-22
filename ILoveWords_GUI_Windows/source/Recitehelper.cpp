#include "Recitehelper.h"
#include "ui_recitehelper.h"

ReciteHelper::ReciteHelper(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReciteHelper)
{
    ui->setupUi(this);
}

ReciteHelper::~ReciteHelper()
{
    delete ui;
}
