#ifndef MLINE_H
#define MLINE_H

#include "mshape.h"
class mLine:public mShape
{
public:
    mLine();
    ~mLine();

    void Draw(QPainter &painter) ;
};

#endif // MLINE_H
