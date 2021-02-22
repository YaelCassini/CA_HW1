#include "spline.h"

//构造函数
spline::spline(){
    for(int i=0;i<4;i++)
    {
        matrix[i]=new double[4];
    }
}


//构造CubicSpline曲线
void spline::set_Spline(vector<QPoint>& vec,int _grain,double _tension)
{
    //设置参数
    int _num=vec.size();
    this->grain=_grain;
    this->tension=_tension;
    this->num=vec.size();

    //为每段曲线的中间计算值分配空间
    ax=new double[_num];
    bx=new double[_num];
    cx=new double[_num];
    dx=new double[_num];

    ay=new double[_num];
    by=new double[_num];
    cy=new double[_num];
    dy=new double[_num];

    create_flag=true;

    //根据参数τ初始化计算矩阵
    init_Matrix();
    //计算曲线参数
    init_spline_Coefficient(vec);
}

//初始化计算矩阵
void spline::init_Matrix()
{
    matrix[0][0]=-tension;
    matrix[0][1]=2-tension;
    matrix[0][2]=-2+tension;
    matrix[0][3]=tension;
    matrix[1][0]=2*tension;
    matrix[1][1]=-3+tension;
    matrix[1][2]=3-2*tension;
    matrix[1][3]=-tension;
    matrix[2][0]=-tension;
    matrix[2][1]=0;
    matrix[2][2]=tension;
    matrix[2][3]=0;
    matrix[3][0]=0;
    matrix[3][1]=1;
    matrix[3][2]=0;
    matrix[3][3]=0;
}

//根据每段的关键点坐标以及计算矩阵计算参数方程的参数ax等
void spline::init_spline_Coefficient(vector<QPoint>& vec)
{
    vector<QPoint> points=vec;
    QPoint p1,p2,p3,p4;

    for(int i=0;i<points.size()-1;i++)
    {
        if(i==0)//第一段（虚拟点）
        {
            p1=points[0];
            p2=points[0];
            p3=points[1];
            p4=points[2];
        }
        else if(i==points.size()-2)
        {
            p1=points[points.size()-3];
            p2=points[points.size()-2];
            p3=points[points.size()-1];
            p4=points[points.size()-1];
        }
        else//最后一段（虚拟点）
        {
            p1=points[i-1];
            p2=points[i];
            p3=points[i+1];
            p4=points[i+2];
        }

        ax[i]=matrix[0][0]*p1.x()+matrix[0][1]*p2.x()+matrix[0][2]*p3.x()+matrix[0][3]*p4.x();
        bx[i]=matrix[1][0]*p1.x()+matrix[1][1]*p2.x()+matrix[1][2]*p3.x()+matrix[1][3]*p4.x();
        cx[i]=matrix[2][0]*p1.x()+matrix[2][1]*p2.x()+matrix[2][2]*p3.x()+matrix[2][3]*p4.x();
        dx[i]=matrix[3][0]*p1.x()+matrix[3][1]*p2.x()+matrix[3][2]*p3.x()+matrix[3][3]*p4.x();
        ay[i]=matrix[0][0]*p1.y()+matrix[0][1]*p2.y()+matrix[0][2]*p3.y()+matrix[0][3]*p4.y();
        by[i]=matrix[1][0]*p1.y()+matrix[1][1]*p2.y()+matrix[1][2]*p3.y()+matrix[1][3]*p4.y();
        cy[i]=matrix[2][0]*p1.y()+matrix[2][1]*p2.y()+matrix[2][2]*p3.y()+matrix[2][3]*p4.y();
        dy[i]=matrix[3][0]*p1.y()+matrix[3][1]*p2.y()+matrix[3][2]*p3.y()+matrix[3][3]*p4.y();
    }
}

//计算曲线上所有插值点
void spline::CubicSpline(vector<QPoint>& vec)
{
    //当没清除就再次点击生成曲线时，不清除之前的插值点，插入间隔点
    QPoint temp(0,0);
    all_points.push_back(temp);

    //根据设置的插值点个数参数，计算对应的u值
    int num=vec.size();
    double* u = new double[grain];
    for (int i = 0; i<grain; i++) {
        u[i] = ((double)i) / grain;  //u [0,1]
    }

    //根据u值和曲线参数计算插值点坐标
    for (int i = 0; i<num-1; i++) {
        QPoint p1=vec[i];
        //加入关键点
        all_points.push_back(p1);
        for (int j = 1; j<grain; j++) {
            QPoint temp=calc_Interpolation(i,u[j]);
            all_points.push_back(temp);
        }
    }
    //加入关键点
    QPoint p1=vec[num-1];
    all_points.push_back(p1);

    delete []u;
}


//根据曲线段序号i和参数u计算插值点坐标
QPoint spline::calc_Interpolation(int i,double u)   //计算插值点的xy值
{
    QPoint p;

    double x=(dx[i] + u*(cx[i] + u*(bx[i] + u*ax[i])));
    double y=(dy[i] + u*(cy[i] + u*(by[i] + u*ay[i])));

    p.setX(x);
    p.setY(y);

    return p;
}

//计算曲线总长度
double spline::calc_Total_length()
{
    double sum=0;
    init_length_Coefficient(num);
    for(int i=0;i<num-1;i++)
    {
        //每两个关键点之间的曲线长度
        sum+=simpson(i,0,1);
    }
    return sum;
}

//初始化曲线计算参数
void spline::init_length_Coefficient(int _num)
{
    int num=_num;
    A = new double[num-1];
    B = new double[num-1];
    C = new double[num-1];
    D = new double[num-1];
    E = new double[num-1];
    for(int i=0;i<num-1;i++){
        A[i] = 9*(ax[i]*ax[i]+ay[i]*ay[i]);
        B[i] = 12*(ax[i]*bx[i]+ay[i]*by[i]);
        C[i] = 6*(ax[i]*cx[i]+ay[i]*cy[i]) + 4*(bx[i]*bx[i]+by[i]*by[i]);
        D[i] = 4*(bx[i]*cx[i]+by[i]*cy[i]);
        E[i] = cx[i]*cx[i]+cy[i]*cy[i];
    }
}


//使用simpson方法计算指定的曲线长度
double spline::simpson(int i,double a,double b)
{
    int n=20;//区间个数
    double h=(b-a)/n;
    double sum=0;

    for(int j=1;j<=n-1;j++)
    {
        double ui=a+1.0*(b-a)/n*j;
        if(j%2!=0)
        {
            sum+=2*f(i,ui);

        }else sum+=4*f(i,ui);
    }
    sum+=f(i,a)+f(i,b);
    sum*=h/3;

    return sum;
}

//f函数
double spline::f(int i,double u)
{

    return sqrt(A[i]*u*u*u*u+B[i]*u*u*u+C[i]*u*u+D[i]*u+E[i]);
}


//使用二分法，根据路程长度计算u的值
double spline::calc_U(double s,int i,double u1,double u2)
{
    if(s<=0)return 0;
    double mid=(u1+u2)/2;
    double Mid_s=simpson(i,0,mid);
    double differ=abs(Mid_s-s);
    if(differ<0.1f)  //精度0.1f
    {
        return mid;
    }

    else if(Mid_s<s) return calc_U(s,i,mid,u2);
    else return calc_U(s,i,u1,mid);
}

//根据曲线段序号i和参数u计算插值带你坐标
point spline::calc_double_Interpolation(int i,double u)   //计算插值点的xy值
{
    point p;

    double x=(dx[i] + u*(cx[i] + u*(bx[i] + u*ax[i])));
    double y=(dy[i] + u*(cy[i] + u*(by[i] + u*ay[i])));

    p.setXY(x,y);
    return p;
}


//清除spline类中的数据
void spline::clear()
{
    if(create_flag)//已经为ax等指针分配了空间
    {
        delete []ax;
        delete []bx;
        delete []cx;
        delete []dx;
        delete []ay;
        delete []by;
        delete []cy;
        delete []dy;
    }
    all_points.clear();
}

//返回储存所有插值点的vector
vector<QPoint>& spline::get_all_points()
{
    return all_points;
}




