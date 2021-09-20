#include "mline.h"

mLine::mLine()
{

}

mLine::~mLine(){

}

void mLine::Draw(QPainter &painter){
    QPen temp=QPen(mColor);
    temp.setWidth(pen_width);
    painter.setPen(temp);

    painter.drawLine(startP, endP);
}
