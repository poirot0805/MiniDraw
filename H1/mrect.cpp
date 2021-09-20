#include "mrect.h"

mRect::mRect()
{

}

mRect::~mRect(){

}

void mRect::Draw(QPainter &painter){
    height=endP.y()-startP.y();
    width=endP.x()-startP.x();

    QPen temp=QPen(mColor);
    temp.setWidth(pen_width);
    painter.setPen(temp);
    painter.drawRect(startP.x(),startP.y(),width,height);
}
