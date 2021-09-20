#ifndef PAINTCONTROLLER_H
#define PAINTCONTROLLER_H
#include "ui_paintcontroller.h"
#include <QWidget>
#include <QColorDialog>
#include "mshape.h"
#include "mline.h"
#include "mrect.h"
#include "meclipse.h"
#include "mpoly.h"
#include "mfreeline.h"

#include <vector>
using namespace  std;

QT_BEGIN_NAMESPACE
namespace Ui { class PaintController; }
QT_END_NAMESPACE

class PaintController : public QWidget
{
    Q_OBJECT
public:
    explicit PaintController(QWidget *parent = nullptr);
    ~PaintController();

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent*);

private:
    Ui::PaintController *ui;

    bool isDrawStart;   // 是否开始绘制当前
    QPoint startPoint;  // 当前形状起点
    QPoint endPoint;
    mShape::mType shape_type;
    mShape* cur_shape;  // 当前正在绘制
    vector<mShape*> mShapeList; // 已经绘制的

    int pen_width;
    QColor pColor;
    QColorDialog *colorDialog;
signals:
public slots:
    void OpenColorDialog();
    void SetLine(); // 设置当前形状为Line
    void SetRect(); // 设置当前形状为Rectangle
    void SetEclipse();  // 设置当前形状为Eclipse
    void SetPoly(); // 设置当前形状为Polygon
    void SetFreeLine(); // 设置当前形状为FreeLine
    void ClearLastShape();  //清除上一个形状
    void SetLineWidth(int value);
};

#endif // PAINTCONTROLLER_H
