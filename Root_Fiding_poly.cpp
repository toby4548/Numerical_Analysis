//
//  Root_Fiding_poly.cpp
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
double newton(double[],double,double[],double[]);
void diff(double[],int);
int rcount=0;
double ox[8]={0.0,1.0,-2.6,2.57,-1.248,0.316,-0.04,0.002};


int main ()
{
    double a[8]={0.0,1.0,-2.6,2.57,-1.248,0.316,-0.04,0.002};
    double tr[6]={1.0,0.5,0.5,0.2,0.2,0.2};
    double c[8],dox[8],ddox[8];
    
    for (int i=0; i<8; i++) {
        c[i]=ox[i];
    }
    
    diff(ox, 8);
    
    for (int i=0; i<8; i++) {
        dox[i]=ox[i];
    }
    
    diff(ox, 8);
    
    for (int i=0; i<8; i++) {
        ddox[i]=ox[i];
    }
    
    for (int i=0; i<8; i++) {
        ox[i]=c[i];
    }
    
    cout<<"Answer of Parameters(for test):"<<endl;
    
    for (int i=0; i<8; i++) {
        cout<<"  X^("<<(8-i-1)<<")";
    }
    
    cout<<endl;
    
    cout<<setw(7);
    
    for (int i=0; i<8; i++) {
        cout<<a[i]<<setw(7);
    }
    
    cout<<endl<<setw(7);
    
    
    for (int  dr=0; dr<6; dr++) 
    {
        
    divi(a, 8, tr[dr]);
    
    for (int i=0; i<8; i++) {
        cout<<a[i]<<setw(7);
    }
    
    cout<<" divi by:"<<tr[dr]<<endl<<setw(7);

    }
    
    double f[8]={0.0,1.0,-2.6,2.57,-1.248,0.316,-0.04,0.002};
    
    
    cout<<"Find roots of f(x):"<<endl;
    
    cout<<setw(7);
    
    for (int i=0; i<8; i++) {
        if (i==7) {
            cout<<f[i];
        }
        else {
        cout<<f[i]<<setw(7);
        }
    }
    
    cout<<endl;
    
 
    while (rcount<6) 
    {
        /*
        r[0]=bisec(ddox, 0.0, 2.5, 0.5);
        rcount+=2;
        divi(ox, 8, r[0]);
        divi(ox, 8, r[0]);
        divi(ox, 8, r[0]);
        r[1]=bisec(dox, 0.4, 0.6, 0.5);
        rcount+=1;
        divi(ox, 8, r[1]);
        divi(ox, 8, r[1]);
        r[3]=bisec(ox, 0.0, 2.5, 0.5);
        */
        
        newton(ox, 0.3, dox, ddox);
        
    }
    
    
       
    for (int i=0; i<8; i++) {
        cout<<ox[i]<<setw(5);
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

    double tv=a;
    
    while (tv<b) {
        cout<<tv<<endl;
        tv+=0.01;
        if (f(array3,8,tv)*f(array3,8,tv+0.01)<0) {
            a=tv-0.01;
            b=tv+0.02;
            break;
            
        }
    }
    
   
    
    cout<<"a="<<a<<"b="<<b<<endl;
    
    
    
    
    
    double fa=f(array3,8,a),fb=f(array3,8,b),c,fc,zero=pow(10.0,-15.0);
    while (fabs(b - a) > zero)  // 足夠精確就好了
 
    {
        c = (a + b)/2.0; fc = f(array3,8,c);
        if (fc * fb > 0.0) 
        {b = c; fb = fc;}
        else 
        {a = c; fa = fc;}
     printf("%1.8e\n",c);
        
    }
    
    cout<<"Root is:";
    printf("%14.8e\n",c);
    cout<<endl;
    
    rcount+=1;

    return c;
     
}

    
void diff(double array4[],int size4)//微分
{
    array4[0]*=7.0;
    array4[1]*=6.0;
    array4[2]*=5.0;
    array4[3]*=4.0;
    array4[4]*=3.0;
    array4[5]*=2.0;
    array4[6]*=1.0;
    array4[7]*=0.0;
    

    
    for (int o=0; o<size4-1; o++) 
    {

        array4[size4-o-1]=array4[size4-o-2];

    }

}

double newton(double array5[],double x0,double dox[],double ddox[])//Newton-Raphson
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
        x0=x;
        x=x0-((f(array5,8,x0)*f(darray5,8,x0))/((pow(f(darray5,8,x0),2.0))-(f(array5,8,x0)*f(ddarray5,8,x0))));
        fx=f(ox,8,x);
        printf("%15.8e\n" , x);
    }
    
    cout<<"Root is:"<<x<<endl;
    
    cout<<setw(5);
    
   

    
    divi(array5, 8, x);
    rcount++;
    
           
     
       
    return x;
}


