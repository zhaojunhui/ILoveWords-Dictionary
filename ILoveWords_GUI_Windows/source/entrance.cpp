#include <QString>
#include <QFileDialog>
#include <QMessageBox>
#include "entrance.h"
#include "ui_entrance.h"
#include "mainwindow.h"


Entrance::Entrance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Entrance)
{
    ui -> setupUi(this);
    connect(ui -> login_btn, SIGNAL(clicked()), this, SLOT(slotLogin()));
    connect(ui -> dict_btn,  SIGNAL(clicked()), this, SLOT(slotDict()));
}

Entrance::~Entrance()
{
    delete ui;
}

void Entrance::slotDict()
{
    QFileDialog *fileDialog = new QFileDialog(this);
    fileDialog -> setWindowTitle(tr("词典位置"));
    fileDialog -> setDirectory(".");
    if(fileDialog -> exec() == QDialog::Accepted)
    {
        dict_ = fileDialog -> selectedFiles()[0];
    }
}

void Entrance::slotLogin()
{
    user_ = ui -> username -> text();
    if (user_ == "")
    {
        QMessageBox::critical(NULL, tr("错误"), tr("用户名不能为空"));
        return;
    } else if (dict_ == "")
    {
        QMessageBox::critical(NULL, tr("错误"), tr("请选择词典！") + dict_);
        return;
    }
    this -> hide();
    MainWindow* wnd = new MainWindow(user_, dict_);
    wnd -> show();
    this -> close();
}
