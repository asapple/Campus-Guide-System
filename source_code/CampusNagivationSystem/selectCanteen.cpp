#include"form.h"

#include<QSqlDatabase>
#include<QDebug>
#include<QMessageBox>
#include<QSqlError>
#include<QSqlQuery>

void Form::selectCanteen()
{
    int zh_num;
    int js_num;

    std::ifstream canteenfile;
    canteenfile.open("./res/canteen.txt",std::ios::in);
    canteenfile >> zh_num >>js_num;
    canteenfile.close();
    qDebug()<<"综合食堂人数："<<zh_num;
    qDebug()<<"教师食堂人数："<<js_num;
    if(zh_num<js_num)
    {
        int ret =QMessageBox::question(this,"食堂负载均衡","此时综合食堂就餐人数较少，是否前往综合食堂西门？",QMessageBox::Yes,QMessageBox::Cancel);
        switch (ret) {
        case QMessageBox::Yes:
//            QString tmp =QString("update canteen set number = %1 where name = '综合食堂'").arg(zh_num+100);
//            query.exec(tmp);
            std::ofstream canteenfile;
            canteenfile.open("./res/canteen.txt",std::ios::out);
            canteenfile << zh_num+100 <<"\n"<<js_num;
            canteenfile.close();
            ui->lineEditTerminal->setText("综合食堂西门");
            this->terminal = 144;
            break;
        }
    }
    else
    {
        int ret =QMessageBox::question(this,"食堂负载均衡","此时教师食堂就餐人数较少，是否前往教师食堂南门？",QMessageBox::Yes,QMessageBox::Cancel);
        switch (ret) {
        case QMessageBox::Yes:
//            QString tmp =QString("update canteen set number = %1 where name = '教师食堂'").arg(zh_num+100);
//            query.exec(tmp)std::ofstream canteenfile;
            std::ofstream canteenfile;
            canteenfile.open("./res/canteen.txt",std::ios::out);
            canteenfile << zh_num <<"\n"<<js_num+100;
            canteenfile.close();;
            ui->lineEditTerminal->setText("教师食堂南门");
            this->terminal = 163;
            break;
        }
    }
}
