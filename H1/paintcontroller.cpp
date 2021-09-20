#include "paintcontroller.h"

PaintController::PaintController(QWidget *parent) : QWidget(parent)
{
    ui->setupUi(this);
    isDrawStart=false;
    pen_width=1;
    startPoint=endPoint=QPoint(0,0);
    shape_type=mShape::cDefault;
    cur_shape=NULL;
    pColor=Qt::black;
    colorDialog=new QColorDialog();

}
PaintController::~PaintController(){
    for (size_t i = 0; i < mShapeList.size(); i++)
        {
            if (mShapeList[i])
            {
                delete mShapeList[i];
                mShapeList[i] = NULL;
            }
        }
    delete colorDialog;
    delete ui;
    if(cur_shape!=NULL){
        delete cur_shape;
        cur_shape=NULL;
    }
}

void PaintController::mousePressEvent(QMouseEvent *event){
    if(Qt::LeftButton==event->button()){
        qDebug() << "Press!" << endl;
        switch(shape_type){
            case mShape::cLine:
                cur_shape=new mLine();
            break;
            case mShape::cRect:
                cur_shape=new mRect();
                break;
            case mShape::cEclip:
                cur_shape=new mEclipse();
                break;
            case mShape::cPoly:{
                isDrawStart=true;
                if(cur_shape==NULL){
                    cur_shape=new mPoly();
                    startPoint=endPoint=event->pos();
                    cur_shape->SetStart(startPoint);
                    cur_shape->SetEnd(endPoint);
                    cur_shape->SetColor(pColor);
                    cur_shape->SetWidth(pen_width);
                }
                break;
            }
            case mShape::cFree:
                cur_shape=new mFreeLine();
                break;
            case mShape::cDefault:
                cur_shape=NULL;
                break;
       }
       //qDebug() << shape_type << endl;
       if(cur_shape!=NULL && shape_type!=mShape::cPoly){
            isDrawStart=true;
            startPoint=endPoint=event->pos();
            cur_shape->SetStart(startPoint);
            cur_shape->SetEnd(endPoint);
            cur_shape->SetColor(pColor);
            cur_shape->SetWidth(pen_width);
        }
    }
    else if(Qt::RightButton==event->button() && isDrawStart && shape_type==mShape::cPoly){
        isDrawStart=false;
        cur_shape->SetEnd(startPoint);
        mShapeList.push_back(cur_shape);
        cur_shape=NULL;
    }
}
void PaintController::mouseMoveEvent(QMouseEvent *event){
    if (isDrawStart && cur_shape != NULL)
    {
        //qDebug() << "Move!" << endl;
        endPoint = event->pos();
        cur_shape->SetEnd(endPoint);
        if(shape_type==mShape::cFree) cur_shape->AddNode(endPoint);
    }
}
void PaintController::mouseReleaseEvent(QMouseEvent *event){
    if (cur_shape != NULL && shape_type!=mShape::cPoly)
    {
        //qDebug() << "Release!" << endl;
        endPoint = event->pos();
        cur_shape->SetEnd(endPoint);
        mShapeList.push_back(cur_shape);
        cur_shape=NULL;
        isDrawStart=false;
    }
    else if(cur_shape!=NULL){
        endPoint = event->pos();
        cur_shape->SetEnd(endPoint);
        cur_shape->AddNode(endPoint);
    }
    // update();
}
void PaintController::paintEvent(QPaintEvent *){
    QPainter painter(this);

    for (int i = 0; i < mShapeList.size(); i++)
    {
        mShapeList[i]->Draw(painter);
    }
    if (cur_shape != NULL) {
        cur_shape->Draw(painter);
    }

    update();
}
void PaintController::OpenColorDialog(){

    pColor=colorDialog->getColor(Qt::red,this,QString("Color Box"),QColorDialog::ShowAlphaChannel);
    qDebug()<<shape_type<<endl;
}
void PaintController::SetLine(){
    qDebug()<<"Set Line"<<endl;
    shape_type=mShape::cLine;
}

void PaintController::SetRect(){
    shape_type=mShape::cRect;
}

void PaintController::SetEclipse(){
    shape_type=mShape::cEclip;
}

void PaintController::SetPoly(){
    shape_type=mShape::cPoly;
}

void PaintController::SetFreeLine(){
    shape_type=mShape::cFree;
}

void PaintController::ClearLastShape(){
    if(cur_shape!=NULL){
        isDrawStart=false;
        delete cur_shape;
        cur_shape=NULL;
    }
    else{
        if(mShapeList.size()){
            vector<mShape*>::iterator it=mShapeList.end();
            it--;
            int i=mShapeList.size()-1;
            delete mShapeList[i];
            mShapeList[i]=NULL;
            it=mShapeList.erase(it);
        }
    }
    update();
}
void PaintController::SetLineWidth(int value){
    pen_width=value;
}
