#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QSlider>
#include <QGridLayout>
#include <paintcontroller.h>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QMenu* menu;
    QToolBar* toolbar;

    QAction* action_color;
    QAction* action_line;
    QAction* action_rectangle;
    QAction* action_eclipse;
    QAction* action_polygon;
    QAction* action_freeline;
    QAction* action_clean_last;

    QSlider* slider_line_width;

    // QGridLayout* rightlayout;

    void Create_Menu();
    void Create_ToolBar();
    void Create_Actions();

private:
    Ui::MainWindow *ui;
    // color
    PaintController* controller;
};
#endif // MAINWINDOW_H
