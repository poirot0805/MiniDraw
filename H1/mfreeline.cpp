#include "mfreeline.h"

mFreeLine::mFreeLine()
{

}

mFreeLine::~mFreeLine(){

}

void mFreeLine::Draw(QPainter &painter){
    QPen temp=QPen(mColor);
    temp.setWidth(pen_width);
    painter.setPen(temp);
    QPoint last_p=startP;
    for(int i=1;i<node_list.size();i++){
        painter.drawLine(last_p, node_list[i]);
        last_p=node_list[i];
    }
    painter.drawLine(last_p, endP);
}

void mFreeLine::AddNode(QPoint p){
    node_list.push_back(p);
}
