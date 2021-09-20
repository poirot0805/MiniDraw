#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QToolBar>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    controller=ui->paintcon;
    Create_Actions();
    Create_ToolBar();
    Create_Menu();

    // setCentralWidget(controller);
}

MainWindow::~MainWindow()
{
    delete controller;
    delete ui;
}

void MainWindow::Create_Actions(){

    action_line = new QAction(tr("&Line"), this);
    action_line->setIcon(QIcon(":/images/直线.png"));
    connect(action_line, &QAction::triggered, controller, &PaintController::SetLine);

    action_rectangle = new QAction(tr("&Rect"), this);
    action_rectangle->setIcon(QIcon(":/images/矩形.png"));
    connect(action_rectangle, &QAction::triggered, controller, &PaintController::SetRect);

    action_eclipse = new QAction(tr("&Eclipse"), this);
    action_eclipse->setIcon(QIcon(":/images/圆形.png"));
    connect(action_eclipse, &QAction::triggered, controller, &PaintController::SetEclipse);

    action_polygon = new QAction(tr("&Polygon"), this);
    action_polygon->setIcon(QIcon(":/images/多边.png"));
    connect(action_polygon, &QAction::triggered, controller, &PaintController::SetPoly);

    action_freeline = new QAction(tr("&FreeLine"), this);
    action_freeline->setIcon(QIcon(":/images/画笔.png"));
    connect(action_freeline, &QAction::triggered, controller, &PaintController::SetFreeLine);

    action_clean_last=new QAction(tr("&Revoke"),this);
    action_clean_last->setIcon(QIcon(":/images/撤销.png"));
    connect(action_clean_last,&QAction::triggered,controller,&PaintController::ClearLastShape);

    action_color = new QAction(tr("&Color-Box"), this);
    action_color->setIcon(QIcon(":/images/颜色.png"));
    connect(action_color, &QAction::triggered, controller, &PaintController::OpenColorDialog);

    slider_line_width=ui->slider_line_width;
    slider_line_width->setOrientation(Qt::Horizontal);
    slider_line_width->setMinimum(1);
    slider_line_width->setMaximum(10);
    slider_line_width->setSingleStep(1);
    connect(slider_line_width,&QSlider::valueChanged,controller,&PaintController::SetLineWidth);
}

void MainWindow::Create_ToolBar(){
    toolbar = addToolBar(tr("&Main"));

    toolbar->addAction(action_line);
    toolbar->addAction(action_rectangle);
    toolbar->addAction(action_eclipse);
    toolbar->addAction(action_polygon);
    toolbar->addAction(action_freeline);
    toolbar->addAction(action_clean_last);
    toolbar->addAction(action_color);
}

void MainWindow::Create_Menu(){
    menu=menuBar()->addMenu(tr("&Choose Tool"));
    menu->addAction(action_color);
    menu->addAction(action_line);
    menu->addAction(action_rectangle);
    menu->addAction(action_eclipse);
    menu->addAction(action_polygon);
    menu->addAction(action_freeline);
    menu->addAction(action_clean_last);
}
