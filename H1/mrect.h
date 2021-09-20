#ifndef MRECT_H
#define MRECT_H

#include "mshape.h"
class mRect:public mShape
{
public:
    mRect();
    ~mRect();
    void Draw(QPainter &painter) ;
private:
    int width;
    int height;
};

#endif // MRECT_H
