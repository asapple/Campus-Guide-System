#ifndef MAP_H
#define MAP_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#define Number_Total 256
#define Number_Xi 196

/*
    使用时将本文件及地图数据一同置于开发文件的文件夹下
    并在开发文件中添加如下语句

    #include "map.h"

    即可直接调用本文件中定义的结构体以及函数方法
    同时，本文件中include的头文件也无需在开发文件重复导入
*/

typedef struct{
    char node_name[33]; // 节点名称,不超过31个字符
    int next_node_number[6]; // 邻接节点的编号列表
    int next_node_distance[6]; // 到邻接节点的距离
    int next_node_crowd[6]; // 两节点间道路的拥挤程度
    int next_node_bicycle[6]; //是否可以通行自行车，1为能，0为不能

    // 以上四个数组的数据按顺序一一对应

    // 例如：
    // 本节点的第一个邻接节点是5号节点，
    // 其与本节点的距离为 3，
    // 两节点间的道路拥挤度为 4，
    // 两节点间不能通行自行车。

    // 则有
    // next_node_number[0] = 5
    // next_node_distance[0] = 3
    // next_node_crowd[0] = 4
    // next_node_bicycle[0] = 0

} Node;

typedef struct{
    double x;
    double y;
} Axis;

//申明全局变量
class MAP
{
public:
    static Node map[Number_Total];
    static int distanceBetweenPoint[Number_Total][Number_Total];
    static Axis point_axis[Number_Total];
};

/*
    函数申明
*/
int InitMap();
void init_axis();
void warshall();
void sort_map(int map_len);
void save_sorted_map(QString selected_map_name, int map_len);

#endif // MAP_H
