#include "form.h"
#include "navigation.cpp"
#include <algorithm>
#include <QTime>
#include <QDebug>

int insert_gate(std::vector<int> *points, int strategy, int XS, Form* ui, int point_num); //已实现
std::vector<int> join_path(std::vector<int> points, int strategy, double& actualDistance); //已实现
int shortest_passing(std::vector<int> *points, int strategy, int start_index, int end_index); //已实现函数
bool is_station(int one);

std::vector<int> findTheWay(Form *ui){
    int point_num = ui->transfer.size()+2; //路径点的个数（包括起点和终点）
    int strategy = ui->strategy; //策略
    int different_side = 0; //判断起点和终点是否在同一校区
    int XiTuCheng = 0; //判断是否有路径点在西土城校区
    int ShaHe = 0; //判断是否有路径点在沙河校区

    std::vector<int> points;
    points.push_back(ui->origin); //路径点数组
    points.insert(points.end(),ui->transfer.begin(),ui->transfer.end());
    points.push_back(ui->terminal);
    //上面三行是为了将起点和终点插入路径点数组中去，第一个数是起点，最后一个数是终点

    for(int i=0;i<point_num;i++){ //判断是否有路径点在西土城校区/沙河校区
        if(points[i] < Number_Xi) XiTuCheng = 1;
        else ShaHe = 1;
    }

    //判断起点和终点是否在同一校区
    //if((ui->origin>=Number_Xi && ui->terminal<Number_Xi) || (ui->terminal>=Number_Xi && ui->origin<Number_Xi)) different_side = 1;

    //根据情况增加校门点，并计算途径最佳路径
    //最终总路径长度通过return返回
    //路径则被保存在points数组中
    ui->formalDistance = insert_gate(&points,strategy,XiTuCheng*ShaHe,ui,point_num) / 100.0;

    /*std::vector<int> final_path;
    join_path(&final_path,points,strategy); //将每一段具体路径拼接起来*/
    return join_path(points,strategy,ui->actualDistance);
}

int shortest_passing(std::vector<int> *points, int strategy, int start_index, int end_index){
    int distance = navigation((*points)[start_index], (*points)[end_index], strategy).back();

    /****************************/
    std::vector<int> path = { (*points)[start_index], (*points)[end_index] };

    for (int shortest_i = 0; shortest_i < points->size(); ++shortest_i) {
        std::vector<int> min_data = {0x3fffffff, 0}; //{position, delta}, 其中delta为正数

        for (int shortest_j = 0; shortest_j < path.size() - 1; ++shortest_j) {
            if (std::find(path.begin(), path.end(), (*points)[shortest_i]) != path.end()) break; //若路径点已在path中，则跳过
            
            int distance_a = navigation(path[shortest_j], (*points)[shortest_i], strategy).back(),//distanceBetweenPoint[shortest_j][(*points)[shortest_i]],
                distance_b = navigation((*points)[shortest_i], path[shortest_j + 1], strategy).back();//distanceBetweenPoint[(*points)[shortest_i]][shortest_j];
            
            int increase = distance_a + distance_b - navigation(path[shortest_j], path[shortest_j + 1], strategy).back();
            if (increase < min_data.front())
                min_data = { increase, shortest_j };
        }

        if(std::find(path.begin(), path.end(), (*points)[shortest_i]) != path.end()) continue;
        
        path.insert(path.begin() + min_data.back() + 1, (*points)[shortest_i]);
        distance += min_data.front();
    }
    /****************************/
    
    points->assign(path.begin(), path.end());
    return distance;
}

std::vector<int> join_path(std::vector<int> points, int strategy, double& actualDistance){
    actualDistance = 0;
    std::vector<int> final_path;
    for(int i=points.size()-1;i>0;i--){
        std::vector<int> temp(navigation(points[i-1],points[i],strategy));
        temp.pop_back();
        actualDistance += temp.back(); temp.pop_back();
        temp.pop_back();
        final_path.insert(final_path.end(),temp.begin(),temp.end());
    }
    final_path.push_back(points[0]);
    reverse(final_path.begin(), final_path.end());
    return final_path;
}

int insert_gate(std::vector<int> *points, int strategy, int XS, Form* ui, int point_num){
    int station[] = {193,194,195,19};

    if(XS == 0){ //此时所有路径点都在同一校区中，不必额外添加校门点
        return shortest_passing(points,strategy,0,point_num-1);
    }else if(ui->origin < Number_Xi){ //此时起点和终点分别在两个不同校区中，起点为西土城校区
        double distance[4], now_time, arrive_time, wait_time;
        QTime current_time = QTime::currentTime();
        int school_bus[] = {24600, 30600, 43200, 48600, 51600, 60600};

        now_time = (current_time.hour() * 60 + current_time.minute()) * 60 + current_time.second();
        for (int i = 0; i < 4; i++)
        {
            distance[i] = navigation(ui->origin, station[i], strategy).back() / 100.0;
            if (i != 3)
            {
                arrive_time = now_time + distance[i] / ui->speed;
                if (fmod(arrive_time, 600) != 0)
                    wait_time = 600 - fmod(arrive_time, 600);
                else
                    wait_time = 0;

                qDebug() << station[i] << " wait time is : " << wait_time;
                //更改车站到沙河西门所需的时间（路程时间加等待时间）
                for (int j = 0; j < 6; j++)
                {
                    if (MAP::map[station[i]].next_node_number[j] == 196 || MAP::map[station[i]].next_node_number[j] == 197)
                    {
                        MAP::map[station[i]].next_node_distance[j] += wait_time * ui->speed;
                    }
                }
            }
        }

        arrive_time = now_time + distance[3] / ui->speed;
        int is_late = 1;
        for(int i = 0; i < 6; i++)
        {
            if (arrive_time <= school_bus[i])
            {
                wait_time = school_bus[i] - arrive_time;
                is_late = 0;
                qDebug() << "school bus wait time is : " << wait_time;

                for (int j = 0; j < 6; j++)
                {
                    if (MAP::map[station[3]].next_node_number[j] == 196 || MAP::map[station[3]].next_node_number[j] == 197)
                    {
                        MAP::map[station[3]].next_node_distance[j] += wait_time * ui->speed;
                    }
                }

                break;
            }
        }

        if (is_late)
        {
            for (int i = 0; i < 6; i++)
            {
                int next = MAP::map[station[3]].next_node_number[i];
                if (is_station(next))
                    MAP::map[station[3]].next_node_distance[i] += 10000 * ui->speed;
            }
        }

        return shortest_passing(points, strategy, 0, point_num - 1);

    }else{ //此时起点和终点在不同校区，起点为沙河校区
        double distance[2], now_time, arrive_time, wait_time;
        QTime current_time = QTime::currentTime();
        int school_bus[] = {35400, 42000, 46800, 56700, 61800, 66300,76200};

        now_time = (current_time.hour() * 60 + current_time.minute()) * 60 + current_time.second();

        distance[0] = navigation(ui->origin, 196, strategy).back() / 100.0;
        distance[1] = navigation(ui->origin, 197, strategy).back() / 100.0;

        arrive_time = now_time + distance[0] / ui->speed;
        if (fmod(arrive_time, 600) != 0)
            wait_time = 600 - fmod(arrive_time, 600);
        else
            wait_time = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (MAP::map[196].next_node_number[j] == station[i])
                {
                    MAP::map[196].next_node_distance[j] += wait_time * ui->speed;
                    break;
                }
            }
        }

        arrive_time = now_time + distance[1] / ui->speed;
        for (int i = 0; i < 7; i++)
        {
            if (school_bus[i] >= arrive_time)
            {
                wait_time = school_bus[i] - arrive_time;
                break;
            }
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (MAP::map[197].next_node_number[j] == station[i])
                {
                    MAP::map[197].next_node_distance[j] += wait_time * ui->speed;
                    break;
                }
            }
        }

        return shortest_passing(points, strategy, 0, point_num - 1);
    }
}

bool is_station(int one)
{
    int stations[] = {193,194,195,19,196,197};
    int is_one = 0;
    for (int i = 0; i < 6; i++)
    {
        if (one == stations[i])
            is_one = 1;
    }
    return is_one;
}
