#include "meclipse.h"

mEclipse::mEclipse()
{

}

mEclipse::~mEclipse(){

}

void mEclipse::Draw(QPainter &painter){
    ecli_b=endP.y()-startP.y();
    ecli_a=endP.x()-startP.x();

    QPen temp=QPen(mColor);
    temp.setWidth(pen_width);
    painter.setPen(temp);
    painter.drawEllipse(startP.x(),startP.y(),ecli_a,ecli_b);
}
