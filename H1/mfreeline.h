#ifndef MFREELINE_H
#define MFREELINE_H

#include "mshape.h"
#include<vector>
using namespace std;

class mFreeLine:public mShape
{
public:
    mFreeLine();
    ~mFreeLine();
    void Draw(QPainter &painter) ;
    void AddNode(QPoint p);
private:
    vector<QPoint> node_list;
};

#endif // MFREELINE_H
