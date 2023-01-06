#include "mappainter.h"
#include "ui_mappainter.h"
#include<QPainter>
#include<QPixmap>
MapPainter::MapPainter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapPainter)
{
    ui->setupUi(this);

    QPixmap pixmap("./res/bupt.jpg");//窗口左上角的小图标设置
    this->setWindowIcon(pixmap);

    this->setFixedSize(771 * 0.8,1080 * 0.8);
    oldcampus = 1;
    campus = 1;
}

MapPainter::~MapPainter()
{
    delete ui;
}
void MapPainter::paintEvent(QPaintEvent *event)
{
    if(campus==1)
    {
        this->setFixedSize(771 * 0.8,1080 * 0.8);
        QPainter painter(this);
        QPixmap pix;
        pix.load("./res/xMap.jpg");
        painter.drawPixmap(0,0,this->width(),this->height(),pix);
        QPixmap stuPix;
        stuPix.load("./res/red.png");
        painter.drawPixmap(this->x,this->y,10,10,stuPix);
    }
    if(campus==2)
    {
        this->setFixedSize(650,487);
        QPainter painter(this);
        QPixmap pix;
        pix.load("./res/bus.jfif");
        painter.drawPixmap(0,0,this->width(),this->height(),pix);
    }
    if(campus==3)
    {
        this->setFixedSize(1228*0.8,877*0.8);
        QPainter painter(this);
        QPixmap pix;
        pix.load("./res/shahe.jpg");
        painter.drawPixmap(0,0,this->width(),this->height(),pix);
        QPixmap stuPix;
        stuPix.load("./res/red.png");
        painter.drawPixmap(this->x,this->y,10,10,stuPix);
    }
}
