#include "map.h"
#include <vector>

#ifndef NAVIGATION
#define NAVIGATION

typedef struct NaviTreeNode{
    int FatherNode;
    int formalDisFromStart;
    int actualDisFromStart;
} NaviTreeNode;

bool NotFound(int num, int index, int HaveFound[]);
void Navi_dfs(NaviTreeNode tree[], int start, int end, QString &path);

std::vector<int> navigation(int start, int end, int strategy){
    int len = Number_Total;
    int HaveFoundNode[len],index=0; //记录已找到的结点
    NaviTreeNode tree[len]; //储存结果的多叉树

    //初始化结果树和已找到的结点表
    for(int i=0;i<len;i++){
        tree[i].formalDisFromStart = -1;
        tree[i].actualDisFromStart = -1;
        HaveFoundNode[i] = -1;
    }

    //录入开始结点
    HaveFoundNode[0] = start;
    tree[start].formalDisFromStart = 0;
    tree[start].actualDisFromStart = 0;
    tree[start].FatherNode = -1;

    //构建结果树
    while(end != HaveFoundNode[index]){
        int MinDistance = 0x7fffffff;
        int MinActualDistance = 0;
        int OriginNode = 0;
        int temp = 0;

        for(int i=0;i<=index;i++){
            temp = HaveFoundNode[i];    
            for(int j=0;j<6;j++){
                int correct_distance = 0;

                //步行，仅考虑距离
                if (0 == strategy) correct_distance = MAP::map[temp].next_node_distance[j] * 100;
                //步行，考虑拥挤度
                else if (3 == strategy) correct_distance = MAP::map[temp].next_node_distance[j] * (100 + MAP::map[temp].next_node_crowd[j]);
                //自行车，仅考虑距离
                else if (1 == strategy) {
                    if (MAP::map[temp].next_node_bicycle[j] == 0) correct_distance = -1;
                    else correct_distance = MAP::map[temp].next_node_distance[j] * 100;
                }//其他，尚未完成
                else correct_distance = MAP::map[temp].next_node_distance[j] * 100;

                if(correct_distance + tree[temp].formalDisFromStart >= MinDistance){
                    break;
                }else if(correct_distance > 0 && NotFound(MAP::map[temp].next_node_number[j],index,HaveFoundNode)){
                    MinDistance = correct_distance + tree[temp].formalDisFromStart;
                    MinActualDistance = MAP::map[temp].next_node_distance[j] + tree[temp].actualDisFromStart;
                    OriginNode = temp;
                    HaveFoundNode[index+1] = MAP::map[temp].next_node_number[j];
                }
            }
        }
        //每找到一个 邻接距离与原有距离之和 小于MinDistance的结点，
        //就更新一次 MinDistance 及 已找到结点表

        //循环完成后，MinDistance中记录了下一个结点到start的最短距离，
        //HaveFoundNode[index+1]中记录了该结点的编号

        tree[HaveFoundNode[index+1]].formalDisFromStart = MinDistance;
        tree[HaveFoundNode[index+1]].actualDisFromStart = MinActualDistance;
        tree[HaveFoundNode[index+1]].FatherNode = OriginNode;
        index++;
    }

    //通过父结点，找到从start到end的路径
    std::vector<int> path;
    int temp = end;
    while(temp!=-1){
        path.push_back(temp);
        temp = tree[temp].FatherNode;
    }
    path.push_back(tree[end].actualDisFromStart); //实际距离
    path.push_back(tree[end].formalDisFromStart); //修正距离
    return path;
}

bool NotFound(int num, int index, int HaveFound[]){
    for(int i=0;i<=index;i++){
        if(HaveFound[i]==num) return false;
    }
    return true;
}

#endif
