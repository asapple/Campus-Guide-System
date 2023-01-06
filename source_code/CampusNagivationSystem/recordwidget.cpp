#include "recordwidget.h"
#include "ui_recordwidget.h"

#include<QSqlDatabase>
#include<QDebug>
#include<QMessageBox>
#include<QSqlError>
#include<QSqlQuery>
#include<QDateTime>
#include<iostream>
#include<fstream>
RecordWidget::RecordWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RecordWidget)
{

    ui->setupUi(this);
    this->setWindowTitle("日志");
    QPixmap pixmap("./res/bupt.jpg");//窗口左上角的小图标设置
    this->setWindowIcon(pixmap);

//    //打印Qt支持的数据库驱动
//    qDebug()<<QSqlDatabase::drivers();
//    //添加MySQL数据库
//    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//    db.setHostName("127.0.0.1");//数据库服务器IP
//    db.setUserName("root"); // 数据库用户名
//    db.setPassword("123456");//密码
//    db.setDatabaseName("campusnagivation");//使用哪个数据库
//    if(!db.open())
//    {
//        QMessageBox::warning(this,"数据库打开失败"
//                             ,db.lastError().text());
//        return ;
//    }
//    model = new QSqlTableModel(this);
//    model->setTable("record");
//    ui->tableView->setModel(model);
//    model->select();
//    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

RecordWidget::~RecordWidget()
{
    delete ui;
}

void RecordWidget::on_pushButtonClean_clicked()
{
    int ret =QMessageBox::question(this,"提示","是否删除日志？",QMessageBox::Yes,QMessageBox::Cancel);
    switch (ret) {
    case QMessageBox::Yes:
        std::ofstream recordfile;
        recordfile.open("./res/record.txt",std::ios::out);
        recordfile <<"";
        recordfile.close();
        break;
    }

}

void RecordWidget::on_pushButton_clicked()
{
//    model = new QSqlTableModel(this);
//    model->setTable("record");
//    ui->tableView->setModel(model);
//    model->select();
    std::ifstream recordfile;
    recordfile.open("./res/record.txt",std::ios::in);
    QString tmp;
    std::string s;
    while(std::getline(recordfile,s))
    {
        tmp.append(QString::fromStdString(s)).append("\n");
    }
    ui->textEdit->setText(tmp);
    recordfile.close();
}
