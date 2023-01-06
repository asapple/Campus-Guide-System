#ifndef MAPPAINTER_H
#define MAPPAINTER_H

#include <QWidget>
using namespace std;
namespace Ui {
class MapPainter;
}

class MapPainter : public QWidget
{
    Q_OBJECT

public:
    explicit MapPainter(QWidget *parent = 0);
    void paintEvent(QPaintEvent *event);
    ~MapPainter();
    double x,y;
    int campus;
    int oldcampus;
private:
    Ui::MapPainter *ui;
};

#endif // MAPPAINTER_H
