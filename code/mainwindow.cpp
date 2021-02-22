#include "mainWindow.h"
#include "ui_mainwindow.h"
#include "paintWindow.h"

#include <QMovie>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->start->setDisabled(true);
    ui->stop_move->setDisabled(true);
    ui->continue_move->setDisabled(true);

    p_w=new paintWindow;
    ui->horizontalLayout_4->addWidget(p_w);
    p_w->show();

    //左上角小车展示
    QPixmap *pixmap=new QPixmap(":/new/prefix1/3.png");
    QPixmap *now_car=p_w->now_car();
    ui->pic_label->setPixmap(*pixmap);
    ui->pic_label->show();


    //设置部分控件的初始值和变化范围
    ui->spinBox_grain->setMinimum(1);  //最小值
    ui->spinBox_grain->setMaximum(99);  //最大值
    ui->spinBox_grain->setSingleStep(2);  //步长
    ui->spinBox_grain->setValue(25);  //初始值

    ui->Slider->setMinimum(0);  // 最小值
    ui->Slider->setMaximum(99);  // 最大值
    ui->Slider->setSingleStep(1);  // 步长
    ui->Slider->setTickInterval(10);  // 设置刻度间隔
    ui->Slider->setTickPosition(QSlider::TicksAbove);  //刻度在上方

    ui->spinBox_grain->setValue(55);  //初始值
    ui->spinBox_speed->setValue(5);  //初始值

    // 连接信号槽（相互改变）
    connect(ui->spinBox_tension, SIGNAL(valueChanged(int)), ui->Slider, SLOT(setValue(int)));
    connect(ui->Slider, SIGNAL(valueChanged(int)), ui->spinBox_tension, SLOT(setValue(int)));
    //connect(p_w,SIGNAL(mousePressEvent()),ui->number2,SLOT(update_numbers()));  //实现实时更新关键点的数目（未实现）

    ui->Slider->setValue(50);

    //如果用规范的槽函数再加上connect，函数会被调用两次
    //connect(ui->generate,SIGNAL(clicked()),this,SLOT(on_generate_clicked()),Qt::uniqueconnection);
    //connect(ui->clear,SIGNAL(clicked()),this,SLOT(on_clear_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//生成并绘制曲线
void MainWindow::on_create_clicked()
{
    int num=p_w->numbers();
    if(num==0)return;  //没有指定关键点

    QString temp="  "+QString::number(num);
    ui->number2->setText(temp);
    ui->start->setDisabled(false);

    //读取曲线参数
    double _tension=ui->Slider->value();
    _tension=(_tension+1)/100.0;
    int _grain=ui->spinBox_grain->value();

    //画出曲线
    p_w->create_Spline(_grain,_tension);

    //计算曲线总长度并显示
    double total_len=p_w->total_length();
    temp=QString::number(total_len);
    ui->length->setText(temp);

    //刷新
    update();
}

//修改参数，决定是否展示插值点
void MainWindow::on_show_clicked()
{
    p_w->change_DrawInPoint();
}

//小车开始运动
void MainWindow::on_start_clicked()
{
    double _speed=ui->spinBox_speed->value();
    double _accelarate=ui->spinBox_acce->value();
    p_w->start_Move(_speed,_accelarate);

    //设置按钮是否可用
    ui->continue_move->setDisabled(true);
    ui->stop_move->setDisabled(false);
}


//清屏槽函数
void MainWindow::on_clear_clicked()
{
    //paintWindow清屏
    p_w->clear();

    //清除关键点个数和曲线总长度
    int _temp=0;
    QString temp=QString::number(_temp);
    ui->number2->setText(temp);
    ui->length->setText(temp);

    //开始运动按钮不可用
    ui->start->setDisabled(true);
    ui->stop_move->setDisabled(true);
    ui->continue_move->setDisabled(true);
}


//小车暂停运动
void MainWindow::on_stop_move_clicked()
{
    p_w->stop_Move();
    ui->continue_move->setDisabled(false);
    ui->stop_move->setDisabled(true);
}

//小车继续运动
void MainWindow::on_continue_move_clicked()
{
    p_w->continue_Move();
    ui->continue_move->setDisabled(true);
    ui->stop_move->setDisabled(false);
}

//实现实时更新关键点的数目（未实现）
void MainWindow::update_numbers()
{
    int num=p_w->numbers();
    QString temp=QString::number(num);
    //ui->number->setText(temp);
    temp="   "+temp;
    ui->number2->setText(temp);
}

void MainWindow::on_change_clicked()
{
    p_w->change_car();
}
