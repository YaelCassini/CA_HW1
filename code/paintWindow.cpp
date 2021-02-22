#include "paintWindow.h"
#include <iostream>
#include "math.h"

//构造函数
paintWindow::paintWindow()
{
    sp=new spline;

    //设置画板宽度
    this->setMinimumWidth(750);
    this->setMinimumHeight(800);

    //读取小车图象
    car[0]=new QPixmap;
    car[1]=new QPixmap;
    car[2]=new QPixmap;
    car[3]=new QPixmap;
    car[4]=new QPixmap;

    car[0]->load(":/new/prefix1/001.png");
    car[1]->load(":/new/prefix1/002.png");
    car[2]->load(":/new/prefix1/003.png");
    car[3]->load(":/new/prefix1/004.png");
    car[4]->load(":/new/prefix1/005.png");

    car_index=0;

    timer = new QTimer();
    time=0;
    connect(timer,SIGNAL(timeout()),this,SLOT(changeState()));
}


//鼠标回调函数，鼠标点击，加入关键点
void paintWindow::mousePressEvent(QMouseEvent *e)
{
    points.push_back(e->pos());
    update();
}

//绘制函数
void paintWindow::paintEvent(QPaintEvent *)
{
    if(time==0) pen_index=0;
    QPainter paint(this);
    if(numbers()<=0)return;  //没有关键点

    //有关键点且计时器时钟不为零，则绘制小车
    if(numbers()>=1&&time!=0){
        //平移
        paint.translate(now_point.X(),now_point.Y());
        //获取斜率角度并旋转
        ratio=get_Ratio();
        paint.rotate(ratio);
        paint.drawPixmap(-35,-40,60,40,*car[car_index]);
        //复原平移和旋转
        paint.rotate(-ratio);
        paint.translate(-now_point.X(),-now_point.Y());
    }


    //设置笔刷样式，绘制关键点
    paint.setPen(QPen(Qt::black,5,Qt::DashDotLine,Qt::RoundCap));
    for(int i=0;i<numbers();i++)
    {
        paint.drawEllipse(points[i],1,1);
    }

    //获取储存所有插值点的vector
    vector<QPoint> a_p=sp->get_all_points();
    paint.setPen(QPen(Qt::blue,3,Qt::SolidLine,Qt::RoundCap));
    //如果已经生成了插值点，则在每两个插值点之间绘制线条
    if(a_p.size()>0)
    {
        for(unsigned int i=0;i<a_p.size()-1;i++)
        {
            QPoint p1=a_p[i];
            QPoint p2=a_p[i+1];
            if(((p1.x()==0&&p1.y()==0)||(p2.x()==0&&p2.y()==0)))
            {
                change_pen(paint);
            }
            else
            {
               paint.drawLine(p1,p2);
            }

        }
    }

    //根据控制变量ifDrawInpoint的值，决定是否绘制出中间插值点
    if(ifDrawInpoint)
    {
        if(a_p.size()>0)
        {
            paint.setPen(QPen(Qt::white,2,Qt::SolidLine,Qt::RoundCap));
            for(unsigned int i=0;i<a_p.size()-1;i++)
            {
                paint.drawEllipse(a_p[i],1,1);
            }
        }
    }

}


//计时器关联槽函数，改变小车坐标及角度
void paintWindow::changeState()
{
    //endflag为true，停止计时器，时间恢复为0
    if(endflag)
    {
        time=0;
        timer->stop();
        return;
    }

    //time等于0时，先计算now_point
    if(time==0){
        now_point=sp->calc_double_Interpolation(0,0);
    }

    time++;

    //当前长度超过曲线总长度，保证计时器停止时小车在路线末尾
    if(now_length()>=total_length()-1)
    {
        next_point=sp->calc_double_Interpolation(points.size()-2,1);
        now_point=sp->calc_double_Interpolation(points.size()-2,0.99);
        endflag=true;
        update();
        return;
    }

    //通过路线长度计算小车当前所在曲线段
    double len=now_length();
    int spline_index=get_spline_index(now_length());
    for(int i=0;i<spline_index;i++){
        len -= sp->simpson(i,0,1);
    }

    //通过不同曲线段的参数和小车在当前曲线段走过的路程长度计算小车坐标
    if(spline_index<points.size()-1)
    {
        if(time>1)now_point=next_point;  //将下一个点赋值为当前点
        //计算下一个点的坐标
        double _u=sp->calc_U(len,spline_index,0,1);
        next_point=sp->calc_double_Interpolation(spline_index,_u);
    }

    update();
}


//获取当前斜率（小车旋转角度）
double paintWindow::get_Ratio()
{
    const float pi = 3.14159;

    double _x0=now_point.X();
    double _y0=now_point.Y();
    double _x1=next_point.X();
    double _y1=next_point.Y();

    if(_x1-_x0==0&&_y1-_y0==0)return ratio;  //两条曲线之间的间隔点
    else if(_x1-_x0==0)return 0;  //如果分母为零

    double tan=(_y1-_y0)/(_x1-_x0);
    double theta=atan(tan);
    double ratio=theta/(2*pi)*360;

    return ratio;
}



//计算并绘制曲线
void paintWindow::create_Spline(int _grain, double _tension)
{
    grain=_grain;
    tension=_tension;
    pen_index=0;
    //int _num=numbers();
    //计算CubicSpline曲线参数
    sp->set_Spline(points,_grain,_tension);
    //sp->set_Parameter(_grain,_tension,_num);
    //sp->init_Coefficient(points);
    //计算曲线上所有插值点的值
    sp->CubicSpline(points);
}

//根据小车所走路程计算小车当前所在曲线段
int paintWindow::get_spline_index(double now_len)
{
    double temp=0;
    for(unsigned int i=0;i<points.size()-1;i++)
    {
        if(temp<=now_len&&now_len<=temp+sp->simpson(i,0,1))
        {
           return i;
        }
        temp+=sp->simpson(i,0,1);
    }
    return points.size()-1;
}

//计算曲线总长度
double paintWindow::total_length()
{
    return sp->calc_Total_length();
}

//获取现在的长度
double paintWindow::now_length()
{
    return speed*time + accelerate*time*time/2;
}

//清屏
void paintWindow::clear()
{
    //储存关键点数据的vector清除
    points.clear();
    //spline类数据清除
    sp->clear();
    timer->stop();
    time = 0;
    update();
}

//小车开始运动
void paintWindow::start_Move(double _speed,double _accelarate)
{
    endflag=false;
    speed=_speed;
    accelerate=_accelarate;

    car_index = 0;
    time = 0;
    timer->start(100);//fps
}

//更换小车
void paintWindow::change_car()
{
    car_index=(car_index+1)%5;
    update();
}

//获取当前关键点的个数
int paintWindow::numbers()
{
    return points.size();
}

//改变控制变量，决定是否绘制插值点
void paintWindow::change_DrawInPoint()
{
    if(ifDrawInpoint)ifDrawInpoint=false;
    else ifDrawInpoint=true;
    update();
}

//小车暂停运动，停止计时器
void paintWindow::stop_Move()
{
    timer->stop();
}

//小车继续运动，启动计时器
void paintWindow::continue_Move()
{
    timer->start();
}

//获取当前小车位图指针
QPixmap* paintWindow::now_car()
{
    return car[car_index];
}

//更换不同样式的笔刷
void paintWindow::change_pen(QPainter& paint)
{
    pen_index=(pen_index+1)%10;
    switch(pen_index)
    {
    case 0:paint.setPen(QPen(Qt::gray,3,Qt::SolidLine,Qt::RoundCap));break;
    case 1:paint.setPen(QPen(Qt::gray,3,Qt::SolidLine,Qt::RoundCap));break;
    case 2:paint.setPen(QPen(Qt::red,3,Qt::SolidLine,Qt::RoundCap));break;
    case 3:paint.setPen(QPen(Qt::red,3,Qt::SolidLine,Qt::RoundCap));break;
    case 4:paint.setPen(QPen(Qt::blue,3,Qt::SolidLine,Qt::RoundCap));break;
    case 5:paint.setPen(QPen(Qt::blue,3,Qt::SolidLine,Qt::RoundCap));break;
    case 6:paint.setPen(QPen(Qt::yellow,3,Qt::SolidLine,Qt::RoundCap));break;
    case 7:paint.setPen(QPen(Qt::yellow,3,Qt::SolidLine,Qt::RoundCap));break;
    case 8:paint.setPen(QPen(Qt::green,3,Qt::SolidLine,Qt::RoundCap));break;
    case 9:paint.setPen(QPen(Qt::green,3,Qt::SolidLine,Qt::RoundCap));break;

    }
}
