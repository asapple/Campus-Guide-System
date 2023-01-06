#ifndef FORM_H
#define FORM_H

#include"querywidget.h"
#include "ui_form.h"
#include"recordwidget.h"
#include "map.h"
#include <QWidget>
#include<QPainter>
#include<QCompleter>
#include<QStringList>
#include<QMessageBox>
#include<QDebug>
#include<QTimer>
#include<QThread>
#include<iostream>
#include<fstream>
#include<string>
#include"mappainter.h"

#define BUS_SPEED 20

using namespace std;
namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    QueryWidget *query = NULL;
    ~Form();

    int origin;//出发地
    int terminal;//目的地
    int strategy;//策略
    double actualDistance;//实际距离
    double formalDistance;//形式距离
    double leftTime;//还需时间
    double wait_time;
    double speed;
    std::vector<int> transfer;//途径地
    int pos2int(QString position);//将地点从qstring类型转成int类型
    QString int2pos(int positionNumber);//将地点从int类型转成qstring类型
    void connect2MySQL();
    void insertRecord();
    void buildRecord();
    void selectCanteen();
    RecordWidget recWid;
    MapPainter mapPai;
signals:
    void put_arounds(QString arounds);
    void flash_around();

private slots:
    void on_comboBoxStrategy_currentIndexChanged(int index);

    void on_pushBUttonStart_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_pushButtonQuery_clicked();

    void on_pushButton_clicked();

    void deal_flash();

private:
    Ui::Form *ui;

    int position;//当前位置

    std::vector<int> pass_position;
    std::vector<int> distance_of_change;//剩余距离为何值时速度应该改变
    std::vector<double> local_speed;//在当前位置的前进速度
    std::vector<int> getTransfer(QString transfer);//获取UI界面中的的途径地

    QTimer *mytime;
    void changeStation();
    void displayStation();
    void setSP(std::vector<int> path);
    //void findTheWay();//寻路函数

};

#endif // FORM_H
