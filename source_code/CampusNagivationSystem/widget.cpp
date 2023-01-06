#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPixmap pixmap("./res/logo.png");//窗口左上角的小图标设置
    this->setWindowIcon(pixmap);
    this->setFixedSize(900,800);

    this->setWindowTitle("CampusNagivationSystem");//窗口名称设置


    QPushButton *pushButtonExit =new QPushButton();//退出按键设置
    pushButtonExit->move( this->width() * 0.7,this->height() * 0.87);
    pushButtonExit->setMinimumSize(100,100*0.618);
    pushButtonExit->setStyleSheet("QPushButton { background-color: rgb(128,138,135); } QPushButton:pressed { background-color: rgb(245,245,245); }");
    pushButtonExit->setParent(this);
    pushButtonExit->setText("退出");
    pushButtonExit->setFont(QFont("宋体",28));

    QPushButton *pushButtonNagivation =new QPushButton();//进入导航界面按键
    pushButtonNagivation->move( this->width() * 0.3,this->height() * 0.87);
    pushButtonNagivation->setMinimumSize(100,100*0.618);
    pushButtonNagivation->setStyleSheet("QPushButton { background-color: rgb(128,138,135); } QPushButton:pressed { background-color: rgb(245,245,245); }");
    pushButtonNagivation->setParent(this);
    pushButtonNagivation->setText("导航");
    pushButtonNagivation->setFont(QFont("宋体",28));

    connect(pushButtonExit, &QPushButton::clicked, [=](){   //退出提示窗口
        int ret =QMessageBox::question(this,"提示","确定是否关闭？",QMessageBox::Yes,QMessageBox::Cancel);
        switch (ret) {
        case QMessageBox::Yes:
            QTimer::singleShot(50, this, SLOT(close()));//50ms之后关闭窗口
            break;
        default:
            break;
        }
    });
    wNag = new Form;    //创建导航窗口，并且和导航按键点击信号连接
    connect(pushButtonNagivation,&QPushButton::clicked,[=](){
        this->hide();
        wNag->show();
        }
    );

}
void Widget::paintEvent(QPaintEvent *)//背景图设置
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(QString("./res/street.png"));
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}
Widget::~Widget()
{
    delete ui;
}
