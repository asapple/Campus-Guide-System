#include "form.h"

int Form::pos2int(QString position)
//转换函数
{
    ifstream infile;
    infile.open("./res/position.txt",ios::in);
    string pos;
    int num;
    while( infile>>num>>pos )
    {
        if(position.toStdString() == pos)
            return num;

    }
    QString crossroad = "";
    for(int i=0; i<position.length();i++){
        if(position[i]>='0' && position[i]<='9')
            crossroad.append(position[i]);
    }

    infile.close();
    if(crossroad != "")
        return crossroad.toInt();
    else
        return -1;
}
QString Form::int2pos(int positionNumber)
{
    ifstream infile;
    infile.open("./res/position.txt",ios::in);
    string pos;
    int num;
    while( infile>>num>>pos )
    {
        if(num == positionNumber)
            return QString::fromStdString(pos);

    }
    QString crossroad = "第";
    crossroad.append(QString::number(positionNumber));
    crossroad.append("号路口");
    return crossroad;
}

