#ifndef SPLINE_H
#define SPLINE_H

#include <vector>
#include <QPoint>
#include <math.h>
#include <iostream>

using namespace std;

//point类拥有浮点数精度，传递坐标数据
class point
{
private:
    double x;
    double y;
public:
    point(double _x=0,double _y=0)
    {
        x=_x;y=_y;
    }
    void setXY(double _x,double _y)
    {
        x=_x;y=_y;
    }
    double X(){return x;}
    double Y(){return y;}
};

class spline
{
private:
    double *ax,*bx,*cx,*dx;//P(u)系数
    double *ay,*by,*cy,*dy;//P(u)系数
    double *A,*B,*C,*D,*E;//计算弧长所用系数
    double* matrix[4];//计算矩阵
    double tension;//参数τ
    int num;//关键点个数
    int grain;//每两个关键点之间插值点的个数（含关键点）
    bool create_flag=false;//是否已经为指针分配空间（判断是否需要delete）
    vector<QPoint> all_points;//所有点

public:
    spline();
     //生成CubicSpline曲线
    void set_Spline(vector<QPoint>& vec,int _grain,double _tension);
    //计算生成的三次样条曲线上所有插值点
    void CubicSpline(vector<QPoint>& vec);
    double calc_Total_length();  //计算曲线总长度


    void init_Matrix(); //初始化矩阵
    void init_spline_Coefficient(vector<QPoint>& vec);//计算P(u)系数

    QPoint calc_Interpolation(int i,double u);//计算内部插值点
    point calc_double_Interpolation(int i,double u);//计算内部插值点（坐标为double类型）

    vector<QPoint>& get_all_points();  //返回储存所有插值点的vector

    void init_length_Coefficient(int _num);//初始化长度计算参数
    double f(int i,double u); //f函数
    double simpson(int i,double a,double b);//求样条曲线长度
    double calc_U(double s,int i,double u1,double u2);//根据长度计算参数u的值
    void clear();//清除数据

    ~spline(){}
};



#endif // SPLINE_H
