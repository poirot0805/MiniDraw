#ifndef MPOLY_H
#define MPOLY_H

#include "mshape.h"
#include<vector>
using namespace std;

class mPoly:public mShape
{
public:
    mPoly();
    ~mPoly();

    void AddNode(QPoint p);
    void Draw(QPainter &painter) ;
private:
    vector<QPoint> node_list;
};

#endif // MPOLY_H
