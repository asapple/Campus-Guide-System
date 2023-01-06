#ifndef RECORDWIDGET_H
#define RECORDWIDGET_H

#include <QWidget>
#include<QSqlTableModel>
namespace Ui {
class RecordWidget;
}

class RecordWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RecordWidget(QWidget *parent = 0);
    ~RecordWidget();
    QSqlTableModel *model;
private slots:

    void on_pushButtonClean_clicked();

    void on_pushButton_clicked();

private:
    Ui::RecordWidget *ui;
};

#endif // RECORDWIDGET_H
