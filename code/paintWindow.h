#ifndef PAINTWINDOW_H
#define PAINTWINDOW_H
#include <QCoreApplication>
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <QTimer>
#include <QPainter>
#include <QPen>

#include "spline.h"

using namespace std;
class Timer;

class paintWindow : public QWidget
{
    Q_OBJECT
private:
    spline* sp;
    int grain;  //每个曲线区间有多少个插值点（包括两端关键点）
    double tension;  //参数，控制曲线弯曲程度

    bool ifDrawInpoint=false;  //是否显示插值点

    int time;//时间
    QTimer* timer;  //计时器
    QPixmap* car[5];  //储存小车位图信息

    int car_index;//显示第几种小车
    int pen_index=0;//使用第几种笔刷

    double speed;  //小车速度
    double accelerate;  //小车加速度

    point now_point;  //运动当前点
    point next_point;  //运动下一个点
    double ratio;  //旋转角度

    vector<QPoint> points;//储存所有关键点

    bool endflag=false;  //小车是否运动到曲线末端

public:
    paintWindow();

    void paintEvent(QPaintEvent *);  //绘制函数
    void mousePressEvent(QMouseEvent *e);  //鼠标回调函数

    void create_Spline(int _grain, double _tension);  //生成并显示cubicspline曲线
    void start_Move(double _speed,double _accelarate);  //小车开始运动
    void stop_Move();  //小车暂停运动
    void continue_Move();  //小车继续运动

    int numbers();  //关键点个数
    double total_length();  //曲线总长度
    double now_length();  //小车当前走过的路线长度
    int get_spline_index(double now_len);  //获取小车当前在哪一段曲线
    double get_Ratio();  //获取当前曲线斜率

    void change_car();  //改变小车
    void change_pen(QPainter& paint);  //改变笔刷
    void change_DrawInPoint();  //改变是否绘制插值点的控制变量
    QPixmap* now_car();  //当前小车位图指针

    void clear();
private slots:
    void changeState();  //连接计时器，改变小车坐标，旋转角度等信息
};





#endif // PAINTWINDOW_H
