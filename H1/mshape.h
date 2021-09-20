#ifndef MSHAPE_H
#define MSHAPE_H

#include <QtGui>
class mShape
{
public:
    mShape();
    virtual ~mShape();
    virtual void Draw(QPainter &painter)=0;

    void SetStart(QPoint s);
    void SetEnd(QPoint e);
    void SetColor(QColor c);
    void SetWidth(int pw);
    virtual void AddNode(QPoint p);

public:
    enum mType{
        cDefault=0,
        cLine=1,
        cRect=2,
        cEclip=3,
        cPoly=4,
        cFree=5
    };
protected:
    QPoint startP;
    QPoint endP;
    QColor mColor;
    int pen_width;
};

#endif // MSHAPE_H
