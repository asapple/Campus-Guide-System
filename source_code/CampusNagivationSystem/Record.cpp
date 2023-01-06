//用MySQL数据库实现日志
#include"form.h"
#include<QSqlDatabase>
#include<QDebug>
#include<QMessageBox>
#include<QSqlError>
#include<QSqlQuery>
#include<QDateTime>
void Form::connect2MySQL() //弃用
{
    //打印Qt支持的数据库驱动
    qDebug()<<QSqlDatabase::drivers();
    //添加MySQL数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");//数据库服务器IP
    db.setUserName("root"); // 数据库用户名
    db.setPassword("123456");//密码
    db.setDatabaseName("campusnagivation");//使用哪个数据库
    if(!db.open())
    {
        QMessageBox::warning(this,"数据库打开失败"
                             ,db.lastError().text());
        return ;
    }
}
void Form::insertRecord()
{
        QDateTime current_date_time =QDateTime::currentDateTime();
        QString current_date =current_date_time.toString("yyyy/MM/dd hh:mm:ss ddd");

        QString ori = ui->lineEditOrigin->text();
        QString ter=ui->lineEditTerminal->text();
        QString tra=ui->lineEditTransfer->text();
        int str = ui->comboBoxStrategy->currentText().toInt();

        ofstream recordfile;
        recordfile.open("./res/record.txt",ios::app);
        QString tmp = current_date;
        tmp.append(" ").append(ori).append(" ").append(ter).append(" ").append(QString::number(str)).append(" ").append(tra).append("\n");
        recordfile << tmp.toStdString();
        recordfile.close();
}
void Form::buildRecord() //弃用
{
    QSqlQuery query;
    query.exec("create table record(time varchar(255) primary key ,origin varchar(255),terminal varchar(255),transfer varchar(255),strategy int)");
}
