#include "form.h"
#include "map.h"
#include <QDebug>


void Form::changeStation()
{
    static int index = 0;
    static int stop = 0;
    static int flash = 0;
    static double x_change = 0;
    static double y_change = 0;
    static double stop_time = 0;

    if(actualDistance == distance_of_change[0] && speed)
    {
        index = 0;
        flash = 0;
        x_change = 0;
        y_change = 0;
    }

    if(actualDistance <= distance_of_change[index] && !stop)
    {
        speed = local_speed[++index];

        double x_dis = MAP::point_axis[pass_position[index]].x - MAP::point_axis[pass_position[index-1]].x;
        double y_dis = MAP::point_axis[pass_position[index]].y - MAP::point_axis[pass_position[index-1]].y;
        double total_dis = pow(x_dis*x_dis + y_dis*y_dis, 0.5);
        x_change = x_dis / total_dis * 0.008 * speed;
        y_change = y_dis / total_dis * 0.008 * speed;

        this->mapPai.x = MAP::point_axis[pass_position[index - 1]].x * 0.8;
        this->mapPai.y = MAP::point_axis[pass_position[index - 1]].y * 0.8;
    }

    if(actualDistance < (distance_of_change[index] + distance_of_change[index-1])/2)
    {
        position = pass_position[index];
        emit(flash_around());
    }

    if (speed == 0)
    {
        stop = 1;
        leftTime -= 0.01;
        stop_time += 0.01;
        if (stop_time >= wait_time)
        {
            stop = 0;
            stop_time = 0;
            this->mapPai.campus = 2;
        }
    }
    else
    {
        if (pass_position[index - 1] < Number_Xi && speed < BUS_SPEED && speed > 0)
            this->mapPai.campus = 1;
        else if (pass_position[index - 1] >= Number_Xi && speed < BUS_SPEED && speed > 0)
            this->mapPai.campus = 3;

        actualDistance -= speed * 0.01;
        leftTime -= 0.01;
        this->mapPai.x += x_change;
        this->mapPai.y += y_change;
    }


    if(leftTime <= 0.01 || actualDistance <= 0){
        leftTime = 0;
        actualDistance = 0;

        ui->pushBUttonStart->setText("开始");
        ui->lineEditOrigin->setEnabled(true);
        ui->lineEditTerminal->setEnabled(true);
        if(ui->comboBoxStrategy->currentIndex() == 2)
            ui->lineEditTransfer->setEnabled(true);
        else
            ui->lineEditTransfer->setEnabled(false);
        ui->comboBoxStrategy->setEnabled(true);
        ui->lineEditOrigin->setText(int2pos(position));//在ui上把起点设为当前位置
        mytime->stop();
    }

    flash++;
    if (flash == 500)
    {
        qDebug()<<this->mapPai.campus;
        this->mapPai.update();
        flash = 0;
    }

    this->displayStation();
}

void Form::on_horizontalSlider_valueChanged(int value)
{
    this->mytime->setInterval(10/value);
}
