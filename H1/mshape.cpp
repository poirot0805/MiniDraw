#include "mshape.h"

mShape::mShape()
{
    mColor=Qt::black;
    pen_width=1;
}

mShape::~mShape(){

}

void mShape::SetStart(QPoint s){
    startP=s;
}
void mShape::SetEnd(QPoint e){
    endP=e;
}
void mShape::SetColor(QColor c){
    mColor=c;
}
void mShape::SetWidth(int pw){
    pen_width=pw;
}
void mShape::AddNode(QPoint p){

}
