#ifndef WIDGET_H
#define WIDGET_H

#include "form.h"
#include <QWidget>
#include<QDebug>
#include<QIcon>
#include<QPainter>
#include<QDialog>
#include<QPushButton>
#include<QImageReader>
#include<QTimer>
#include<QMessageBox>
//#include<cstdlib>
//#include<ctime>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);//背景图设置函数
    Form * wNag = NULL;//导航窗口
    ~Widget();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
