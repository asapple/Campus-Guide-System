#include "querywidget.h"
#include "ui_querywidget.h"
#include"form.h"
QueryWidget::QueryWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QueryWidget)
{
    ui->setupUi(this);
    QPixmap pixmap("./res/bupt.jpg");//窗口左上角的小图标设置
    this->setWindowIcon(pixmap);

    connect(ui->BtnReturn,&QPushButton::clicked,[=](){//返回按键设置
        this->hide();
        });
}

QueryWidget::~QueryWidget()
{
    delete ui;
}

void QueryWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load("./res/car.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
void QueryWidget::luxian_show(std::vector<int> t)
{
    std::string s = "";
    for(int i=0;i<t.size();i++)
    {
        Form  w;
        s.append((w.int2pos(t[i])).toStdString());
        if(i!=t.size()-1)
            s.append("-->");
    }

    ui->textEditServiceTransfer->setText(QString::fromStdString(s));
}

void QueryWidget::show_arounds(QString arounds)
{
    ui->textEditBuildings->setText(arounds);
}
