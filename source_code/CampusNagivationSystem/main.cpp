#include "widget.h"
#include <QApplication>
#include "map.h"
//#include<QDebug>
//#include<QDir>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    //qDebug()<<QDir::currentPath();
    InitMap();
    for(int i=0; i<Number_Total; i++){
        for(int j=0; j<6;j++){
            MAP::map[i].next_node_crowd[j] = 2;
            MAP::map[i].next_node_bicycle[j] = 1;
        }
    }

    MAP::map[163].next_node_bicycle[0] = 0;
    MAP::map[164].next_node_bicycle[1] = 0;
    w.show();

    return a.exec();
}
