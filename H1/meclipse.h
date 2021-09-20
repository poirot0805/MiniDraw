#ifndef MECLIPSE_H
#define MECLIPSE_H

#include "mshape.h"
class mEclipse:public mShape
{
public:
    mEclipse();
    ~mEclipse();

    void Draw(QPainter &painter) ;

private:
    QPoint center;
    int ecli_a;
    int ecli_b;
};

#endif // MECLIPSE_H
