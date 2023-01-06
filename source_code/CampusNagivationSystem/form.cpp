#include "form.h"
#include <QDebug>
#include <vector>
#include "aboutTime.cpp"
#include "setPaint.cpp"

Form::Form(QWidget *parent) : QWidget(parent), ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setWindowTitle("NagivationPage");
    ui->lcdNumber->display(int(1));
    mytime = new QTimer;
    query = new QueryWidget;//详情页面
    mytime->setInterval(10);

    QPixmap pixmap("./res/bupt.jpg");//窗口左上角的小图标设置
    this->setWindowIcon(pixmap);

    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->lcdNumber,SLOT(display(int)));//模拟倍数滑条和数字同步显示设置
    connect(this, &Form::put_arounds, query, &QueryWidget::show_arounds);
    connect(this, &Form::flash_around, this, &Form::deal_flash);

    ui->lcdNumber->setDigitCount(1);
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);

    connect(ui->pushButtonRecord,&QPushButton::clicked,[=](){
        recWid.show();//日志页面
        }
    );
    connect(mytime,&QTimer::timeout,[=](){
        this->changeStation();
    });
    ui->lineEditTransfer->setEnabled(false);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButtonQuery_clicked()
{
    emit(flash_around());
    query->show();
}

void Form::deal_flash()
{
    std::vector<int> around;
    std::vector<int> distance;
    for (int i = 0; i < Number_Total; i++)
    {
        if (MAP::distanceBetweenPoint[position][i] >= 0 && MAP::distanceBetweenPoint[position][i] < 150)
        {
            around.push_back(i);
            distance.push_back(MAP::distanceBetweenPoint[position][i]);
        }

    }

    QString show_around;
    for (int i = 0; i < around.size(); i++)
    {
        QString building = int2pos(around[i]);
        if (!building.endsWith("路口"))
            show_around += int2pos(around[i]) + " 距离：" + QString::number(distance[i]) + "\n";
    }

    emit(put_arounds(show_around));
}

void Form::on_pushButton_clicked()
{
    this->mapPai.show();
}
