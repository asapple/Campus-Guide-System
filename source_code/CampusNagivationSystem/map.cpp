#include "map.h"
using namespace std;

#include <fstream>
#include <sstream>

Node MAP::map[Number_Total];
int MAP::distanceBetweenPoint[Number_Total][Number_Total];
Axis MAP::point_axis[Number_Total];
/*
    初始化函数，用于载入地图，载入成功则返回 1
*/
int InitMap(){
    QString selected_map_name;  //记录数据文件名
    QString open_map_name;
    QString tips;
    int file_unsorted=0;  //记录地图数据是否已经有序

    { //检查是否存在已排序文件
    selected_map_name = "./res/map_data";
    QFile map_data(selected_map_name+"_sorted.txt");

    if(map_data.open(QIODevice::ReadOnly | QIODevice::Text)==false){
        file_unsorted = 1;
        open_map_name = selected_map_name+".txt";
        tips="----------检测到文件数据未排序，正在记录数据并排序----------";
        qDebug()<<tips.toUtf8().data();
        //打开失败则说明没有已排好序的地图数据存在，则打开源文件
    }else open_map_name = selected_map_name+"_sorted.txt";

    map_data.close();
    }


    QFile map_data(open_map_name);
    if(map_data.open(QIODevice::ReadOnly | QIODevice::Text)==false){
        tips="----------地图数据加载失败，请检查文件是否存在或出错----------";
        qDebug()<<tips.toUtf8().data();
        return 0;
    }

    int i=0,j=0,k=0;
    QString this_line;
    while(!map_data.atEnd()){
        this_line = map_data.readLine();
        if(this_line=="\n" || this_line[0]=='#') continue; //跳过注释行以及空行

        QTextStream the_line(&this_line); //将字符串转为输入流，方便往数组输入

        if(6==i){
            if(this_line.length()>33){
                tips="----------第"+QString::number(k)+"号节点名字过长，请修改后重试----------";
                qDebug()<<tips.toUtf8().data();
            }
            else the_line>>MAP::map[k].node_name;
            k++; i=0; j=0;
            continue;
        }

        the_line>>MAP::map[k].next_node_number[j]
                >>MAP::map[k].next_node_distance[j];

        i++;j++;
    }
    //录入地图数据

    if(file_unsorted){
        sort_map(k);
        save_sorted_map(selected_map_name,k);
    }
    //给地图数据排序，并记录在文件中，方便下次使用

    //warshall算法算出每两点间的距离，用于周边查询
    warshall();
    init_axis();

    tips="----------地图载入完成,共载入"+QString::number(k)+"个数据点----------";
    qDebug()<<tips.toUtf8().data();
    map_data.close();
    return 1;
}

/*
    采用冒泡排序，因为每个节点的邻接节点个数有限，均为6个以下
    故对单个节点进行冒泡排序的时间复杂度为 O（1）
    对整个地图数据进行冒泡排序的时间复杂度为 O（n）

    若采用快速排序，时间复杂度上没有明显优势
    但递归的写法却可能拖慢效率
*/
void sort_map(int map_len){
    int node_len;
    int i,j,k;

    for(i=0;i<map_len;i++){
        node_len = 0;
        for(j=0;MAP::map[i].next_node_distance[j]!=-1 && j < 6;j++) node_len++;
        for(j=0;j<node_len;j++){
            for(k=1;k<node_len;k++){
                int front_node = MAP::map[i].next_node_distance[k-1];
                int behind_node = MAP::map[i].next_node_distance[k];
                if(behind_node>=front_node) continue;

                int temp;

                temp = MAP::map[i].next_node_distance[k-1];
                MAP::map[i].next_node_distance[k-1] = MAP::map[i].next_node_distance[k];
                MAP::map[i].next_node_distance[k] = temp;

                temp = MAP::map[i].next_node_number[k-1];
                MAP::map[i].next_node_number[k-1] = MAP::map[i].next_node_number[k];
                MAP::map[i].next_node_number[k] = temp;

                temp = MAP::map[i].next_node_crowd[k-1];
                MAP::map[i].next_node_crowd[k-1] = MAP::map[i].next_node_crowd[k];
                MAP::map[i].next_node_crowd[k] = temp;

                temp = MAP::map[i].next_node_bicycle[k-1];
                MAP::map[i].next_node_bicycle[k-1] = MAP::map[i].next_node_bicycle[k];
                MAP::map[i].next_node_bicycle[k] = temp;
            }
        }
    }

    QString tips="----------文件数据排序完成----------";
    qDebug()<<tips.toUtf8().data();
    return;
}

/*
    将排序好的地图数据写成新文件记录下来，方便下次使用
*/
void save_sorted_map(QString selected_map_name, int map_len){
    selected_map_name += "_sorted.txt";

    QFile map_data_sorted(selected_map_name);
    map_data_sorted.open(QIODevice::WriteOnly);
    QTextStream out(&map_data_sorted);

    for(int i=0;i<map_len;i++){
        out<<"#"<<"Node number: "<<i<<endl;

        for(int j=0;j<6;j++){
            out<<MAP::map[i].next_node_number[j]<<" ";
            out<<MAP::map[i].next_node_distance[j]<<endl;
        }

        out<<MAP::map[i].node_name<<endl;
        out<<endl;
    }

    map_data_sorted.close();
    QString tips="----------已生成新的数据记录文件----------";
    return;
}

void warshall(){
    /*************************************/
    for (int memset_i = 0; memset_i < Number_Total; ++memset_i) {
        memset(MAP::distanceBetweenPoint[memset_i], 0x1fffffff, sizeof(MAP::distanceBetweenPoint[memset_i]));
        MAP::distanceBetweenPoint[memset_i][memset_i] = 0;

        for (int memset_j = 0; memset_j < 6; ++memset_j) {
            //2号节点的相邻节点为5、12号节点，距离都为2
            //那么next_node_number = {5, 12, -1, ...};  next_node_distance = {2, 2, -1, ...}
            if (MAP::map[memset_i].next_node_number[memset_j] > -1) {
                int memset_target = MAP::map[memset_i].next_node_number[memset_j];
                MAP::distanceBetweenPoint[memset_i][memset_target] = MAP::distanceBetweenPoint[memset_target][memset_i] = MAP::map[memset_i].next_node_distance[memset_j];
            }
        }
    }

    //Warshell
    for (int warshall_k = 0; warshall_k < Number_Total; warshall_k++){
        for (int warshall_i = 0; warshall_i < Number_Total; warshall_i++){
            for (int warshall_j = 0; warshall_j < Number_Total; warshall_j++){
                if (MAP::distanceBetweenPoint[warshall_i][warshall_k] > 0 && MAP::distanceBetweenPoint[warshall_k][warshall_j] > 0){
                    if (MAP::distanceBetweenPoint[warshall_i][warshall_j] < 0 || MAP::distanceBetweenPoint[warshall_i][warshall_j] > MAP::distanceBetweenPoint[warshall_i][warshall_k] + MAP::distanceBetweenPoint[warshall_k][warshall_j])
                        MAP::distanceBetweenPoint[warshall_i][warshall_j] = MAP::distanceBetweenPoint[warshall_i][warshall_k] + MAP::distanceBetweenPoint[warshall_k][warshall_j];
                }
            }
        }
    }
/*************************************/
}

void init_axis()
{
    std::ifstream filename("./res/axis.txt");
    std::string cache;
    int index = 0;
    double x = 0,y = 0;
    for (int i = 0; i < Number_Total; i++)
    {
        getline(filename, cache);
        std::istringstream cache_stream(cache);
        cache_stream >> index >> x >> y;

        MAP::point_axis[index].x = x;
        MAP::point_axis[index].y = y;
    }
}
