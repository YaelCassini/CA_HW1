#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "paintWindow.h"
#include <QWidget>
#include <QMainWindow>
#include <QLayout>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    paintWindow* p_w;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_create_clicked();//绘制曲线并显示
    void on_clear_clicked();//清屏
    void on_start_clicked();//开始运动按钮槽函数
    void on_show_clicked();//展示插值点按钮槽函数
    void on_stop_move_clicked();//停止运动按钮槽函数
    void on_continue_move_clicked();//继续运动按钮槽函数


    void update_numbers();//更新关键点数目
    void on_change_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
