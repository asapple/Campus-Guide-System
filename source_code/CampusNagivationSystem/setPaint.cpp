#include "form.h"

void Form::paintEvent(QPaintEvent *)
//背景图设置函数
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("./res/house.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
