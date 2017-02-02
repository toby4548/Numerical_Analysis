//
//  Root_Fiding_complex.cpp
//  
//
//  Created by Y.Huang on 12/3/18.
//  Copyright (c) 2012 All rights reserved.
//


#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
double f(double [],int,double);
void divi(double [],int,double);
double bisec(double[],double,double,double);
void newton(double[],double);
void diff(double[],int);
double root=0.0;
int bcount=0;

int main ()
{
    double x;
    
    for (x=-2.49; x<0; x+=0.01) 
    {
        double fxy[8]={0.0,(1.0/36.0),0.0,((5.0/6.0)*pow(x, 2.0)+(1.0/6.0)*x+(5.0/6.0)),0.0,((5.0/6.0)*pow(x, 4.0)+(1.0/3.0)*pow(x, 3.0)+0.5*pow(x, 2.0)),0.0,((1.0/36.0)*pow(x, 6.0)+(1.0/6.0)*pow(x, 5.0)+(7.0/12.0)*pow(x, 4.0)+(4.0/3.0)*pow(x, 3.0)+2.0*pow(x, 2.0)+2.0*x)};
        
        cout<<setw(5);
        
        for (int i=0; i<8; i++) {
            cout<<fxy[i]<<"     ";
        }
        
        double temp;
        
        root=0.0;
        
        cout<<"x="<<x<<endl;
        temp=x;
        
        while (root <= 0.0) 
        {
            double ig=bisec(fxy, 0.0, 100.0, 0.05);            
            newton(fxy, ig);
            if (bcount>10) {
                break;
            }
            x=temp;
            
        } 
        
        if (bcount>10) {
            cout<<"No complex root"<<endl;
            bcount=0;
        
        }
        else { 
        
        cout<<"Complex Root is:"<<x<<"x+"<<root<<"i"<<endl;
        bcount=0;
        
        }
    
    }
    
    
    
    
    
}

double f(double array1[],int size1,double value)//求函數值
{
    double ans;
    ans=array1[0]*pow(value,7.0)+array1[1]*pow(value, 6.0)+array1[2]*pow(value, 5.0)+array1[3]*pow(value, 4.0)+array1[4]*pow(value, 3.0)+array1[5]*pow(value, 2.0)+array1[6]*value+array1[7];
    return ans;
}

void divi(double array2[],int size2,double root)//長除法
{
    double b[size2];
    for (int k =0; k<size2; k++) {
        b[k]=array2[k];
    }
    
    for (int l=0; l<size2; l++) {
        if (l==0) 
            b[l]=0.0;
        else
            b[l]=array2[l]+b[l-1]*root;
    }
    
    for (int m=1; m<=size2; m++) {
        if (m==size2)
            array2[m]=0.0;
        else
            array2[size2-m]=b[size2-m-1];
    }
    
}

double bisec(double array3[],double a,double b,double tol)//二分法
{
    double fa=f(array3,8,a),fb=f(array3,8,b),c,fc,zero=tol;
    while (fabs(b - a) > zero)  // 足夠精確就好了
        
    {
        c = (a + b)/2.0; fc = f(array3,8,c);
        if (fc * fb > 0.0) 
        {b = c; fb = fc;}
        else 
        {a = c; fa = fc;}
        cout<<c<<endl;
    }
    
    return c;
}

void diff(double array4[],int size4)//微分
{
    
    
    for (int n=0; n<size4; n++) 
    {
        double pow;
        int powo=(size4-n-1);
        pow=static_cast<double>(powo);
        array4[n]=pow*array4[n];
    }
    
    
    
    
    for (int o=0; o<size4-1; o++) 
    {
        
        array4[size4-o-1]=array4[size4-o-2];
        
    }
    
}

void newton(double array5[],double x0)//Newton-Raphson
{
    double x,fx,darray5[8],ddarray5[8],b[8],zero=pow(10.0,-15.0);
    
    for (int i=0; i<8; i++) {
        b[i]=array5[i];
    }
    
    diff(array5, 8);
    
    for (int i=0; i<8; i++) {
        darray5[i]=array5[i];
    }
    
    diff(array5, 8);
    
    for (int i=0; i<8; i++) {
        ddarray5[i]=array5[i];
    }
    
    for (int i=0; i<8; i++) {
        array5[i]=b[i];
    }
    
    x=x0-(f(array5,8,x0)*f(darray5,8,x0))/((pow(f(darray5,8,x0),2.0))-(f(array5,8,x0)*f(ddarray5,8,x0)));
    fx=f(array5,8,x);
    
    
    
    while (fabs(fx)>zero) 
    {
      if (bcount>10) {break;}
        
        x0=x;
        x=x0-((f(array5,8,x0)*f(darray5,8,x0))/((pow(f(darray5,8,x0),2.0))-(f(array5,8,x0)*f(ddarray5,8,x0))));
        fx=f(array5,8,x);
        cout<<x<<endl;
        bcount++;
    }
    
    if (bcount>10) {
        cout<<"No root"<<endl;
        
    }
    
    else {
    cout<<"Root is:"<<x<<endl;
    root=x;
    
    divi(array5, 8, x);

    
    if (f(darray5,8,x)<zero) 
    {
        
        divi(array5, 8, x);
   
        
        if (f(ddarray5,8,x)<zero) 
        {
            cout<<"TRIPLE ROOT!"<<endl;
            divi(array5, 8, x);
    
        }
        
        else cout<<"DOUBLE ROOT!"<<endl;
        
    }
    
    }
    
}    


