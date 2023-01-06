#ifndef QUERYWIDGET_H
#define QUERYWIDGET_H

#include <QWidget>
#include<QPainter>
#include<cstdio>
#include<string.h>
namespace Ui {
class QueryWidget;
}

class QueryWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QueryWidget(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    ~QueryWidget();
    void luxian_show(std::vector<int> t);

public slots:
    void show_arounds(QString arounds);

private:
    Ui::QueryWidget *ui;
};

#endif // QUERYWIDGET_H
