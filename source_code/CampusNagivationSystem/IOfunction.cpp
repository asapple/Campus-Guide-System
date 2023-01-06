#include "form.h"
#include "QIchange.cpp"

std::vector<int> Form::getTransfer(QString transfer)
{
    std::vector<int> result;
    std::vector<int> errorResult;   errorResult.push_back(-1);

    std::ofstream transferFile_out ;
    transferFile_out.open("./res/transferFile.txt",ios_base::out);//将途径地输入框中的内容复制到文件transferFile.txt中
    transferFile_out << transfer.toStdString();
    transferFile_out.close();

    std::ifstream transferFile ;
    transferFile.open("./res/transferFile.txt",ios_base::in);

    string pos;
    while(transferFile >> pos)
    {
        qDebug() << QString::fromStdString(pos);
        int num = pos2int(QString::fromStdString(pos));
        if(-1 == num)
        {
            return errorResult;
        }
        else
            result.push_back(num);
        qDebug() << num;
    }
    transferFile.close();
    qDebug() << "途径地处理结果:";
    for (int i=0;i<result.size();i++)
    qDebug() << result[i] ;
    return result;
}
void Form::displayStation()
{
    ui->lineEditPosition->setText(Form::int2pos(position));

    int dis;
    int tim;
    QString dis_s;
    QString tim_s;
    if(leftTime>60)
    {
        tim = (int)leftTime/60;
        tim_s = QString::number(tim,10);
        tim_s.append("分钟");
    }
    else
    {
        tim = (int)leftTime;
        tim_s = QString::number(tim,10);
        tim_s.append("秒");
    }

    if(actualDistance>10)
    {
        dis = ((int)actualDistance +5) / 10 * 10;
        dis_s = QString::number(dis,10);
    }
    else
    {
        dis = (int)actualDistance;
        dis_s = QString::number(dis,10);
    }
    dis_s.append("米");

    ui->lineEditDistance->setText(dis_s);
    ui->lineEditLeftTime->setText(tim_s);
}
