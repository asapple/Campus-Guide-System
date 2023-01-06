#include "form.h"
#include "IOfunction.cpp"
#include "findTheWay.cpp"
#include <iostream>

#define SCHOOL_DISTANCE 5000

bool is_over_school(int one, int two);

void Form::on_comboBoxStrategy_currentIndexChanged(int index)
//当且仅当策略选择途径地最短距离时，途径地一栏可编辑
{
    if(index == 2)
    {
        ui->lineEditTransfer->setEnabled(true);
    }
    else
    {
        ui->lineEditTransfer->setEnabled(false);
    }
}

void Form::on_pushBUttonStart_clicked()
{
    if(ui->pushBUttonStart->text() == "开始")
    //点击开始导航
    {   this->origin = pos2int(ui->lineEditOrigin->text());//获取出发地，转成int类型，以便被算法模块接受
        this->terminal = pos2int(ui->lineEditTerminal->text());//获取目的地，转成int类型，以便被算法模块接受
        this->strategy = ui->comboBoxStrategy->currentIndex();//获取策略

        qDebug()<<"origin = "<<origin;
        qDebug()<<"terminal = "<<terminal;
        qDebug()<<"strategy = "<<strategy;

        /**************************/
        if(strategy != 1) this->speed = 2;
        else this->speed = 5;
        /**************************/

        if(strategy == 2)
            this->transfer = getTransfer(ui->lineEditTransfer->text());
        if(origin == -1)
        {
            QMessageBox::warning(this,"error","没有找到您输入的起点");
            return;
        }
        if(terminal == -1)
        {
            QMessageBox::warning(this,"error","没有找到您输入的终点");
            return;
        }
        if(strategy == 2 && transfer[0] == -1 )
        {
            QMessageBox::warning(this,"error","途径地输入错误");
            return;
        }

        /*************************************************/

        if(this->terminal == 138 ||this->terminal == 144 ||this->terminal == 163 )
        {
            selectCanteen();
        }

        /*************************************************/

        //connect2MySQL();                    //日志
        insertRecord();

        /*************************************************/
        std::vector<int> pathDebug(findTheWay(this));
        qDebug()<<"The passing points are:";
        for(int i=0;i<pathDebug.size();i++){
            qDebug()<<pathDebug[i]<<" ";
        }
        std::cout<<"\n";
        this->leftTime = this->formalDistance / this->speed;
        /*************************************************/
        pass_position.clear();
        distance_of_change.clear();
        distance_of_change.push_back(actualDistance);
        local_speed.clear();
        local_speed.push_back(speed);

        int next_distance = actualDistance;
        for(std::vector<int>::iterator iter = pathDebug.begin(); (iter+1) != pathDebug.end(); iter++){
            int temp_distance = 0;
            double temp_speed = 0;

            for(int i = 0; i < 6; i++){
                if(MAP::map[*iter].next_node_number[i] == *(iter+1)){
                    if (is_over_school(*iter, *(iter+1)))
                    {
                        local_speed.push_back(0);
                        distance_of_change.push_back(next_distance);
                        pass_position.push_back(*iter);

                        temp_distance = MAP::map[*iter].next_node_distance[i];
                        this->leftTime -= SCHOOL_DISTANCE / speed - SCHOOL_DISTANCE*1.0 / BUS_SPEED;
                        this->wait_time = (temp_distance - SCHOOL_DISTANCE) / speed;
                        qDebug() << "this->wait_time is : "<<this->wait_time;

                        temp_speed = BUS_SPEED;
                        temp_distance = SCHOOL_DISTANCE;

                        actualDistance -= wait_time * speed;
                        for (int i = 0; i < distance_of_change.size(); i++)
                        {
                            distance_of_change[i] -= wait_time * speed;
                        }
                        next_distance -= wait_time * speed;

                    }
                    else
                    {
                        temp_distance = MAP::map[*iter].next_node_distance[i];
                        if(strategy == 3)
                            temp_speed = speed / (1 + MAP::map[*iter].next_node_crowd[i]/100.0);
                        else
                            temp_speed = speed;
                        break;
                    }
                }
            }

            next_distance -= temp_distance;
            pass_position.push_back(*iter);
            distance_of_change.push_back(next_distance);
            local_speed.push_back(temp_speed);
        }
        pass_position.push_back(terminal);
        qDebug()<<"actualDistance = "<<this->actualDistance;
        qDebug()<<"formalDistance = "<<this->formalDistance;
        qDebug()<<"total time = "<<leftTime;
        qDebug()<<"pass_positon = " << pass_position.size();
        qDebug()<<"distannce_of_change = " << distance_of_change.size();
        qDebug()<<"local_speed = " << local_speed.size();
        /*for(int i=0;i<distance_of_change.size();i++){
            qDebug()<<distance_of_change[i];
        }*/
        /************************************************/

        mytime->start(10/ui->horizontalSlider->value());//启动计时器
        displayStation();
        query->luxian_show(pathDebug);
        //qDebug()<<origin<<terminal<<strategy;
        ui->pushBUttonStart->setText("暂停");
        ui->lineEditOrigin->setEnabled(false);
        ui->lineEditTerminal->setEnabled(false);
        ui->lineEditTransfer->setEnabled(false);
        ui->comboBoxStrategy->setEnabled(false);

        position = origin;//把起点传给当前位置
        this->mapPai.x = MAP::point_axis[origin].x * 0.8;
        this->mapPai.y = MAP::point_axis[origin].y * 0.8;

        this->mapPai.show();

    }
    else
    //点击暂停导航
    {
            mytime->stop();
            int ret =QMessageBox::question(this,"提示","是否暂停导航？",QMessageBox::Yes,QMessageBox::Cancel);
            switch (ret) {
            case QMessageBox::Yes:
                ui->pushBUttonStart->setText("开始");
                ui->lineEditOrigin->setEnabled(true);
                ui->lineEditTerminal->setEnabled(true);
                if(ui->comboBoxStrategy->currentIndex() == 2)
                    ui->lineEditTransfer->setEnabled(true);
                else
                    ui->lineEditTransfer->setEnabled(false);
                ui->comboBoxStrategy->setEnabled(true);
                ui->lineEditOrigin->setText(int2pos(position));//在ui上把起点设为当前位置
                //mytime->stop();
                break;
            default:
                mytime->start();
                break;
            }
    }
}

bool is_over_school(int one, int two)
{
    int stations[] = {193,194,195,19,196,197};
    int is_one = 0, is_two = 0;
    for (int i = 0; i < 6; i++)
    {
        if (one == stations[i])
            is_one = 1;
        if (two == stations[i])
            is_two = 1;
    }
    return is_one * is_two;
}
