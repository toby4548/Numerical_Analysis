//
//  ODE_RK4_Multi_Vortex.cpp
//  
//
//  Created by Y.Huang on 12/4/15.
//  Copyright (c) 2012 All rights reserved.
// 
 
#include <iostream> 
#include <fstream> 
#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <cmath> 
#include <math.h> 
#include <cstdlib> 
#include <fstream> 
#include <math.h> 
 
using namespace std; 
 
double u(double,double,double,double,double); 
double v(double,double,double,double,double); 
 
 
 
int main() 
{ 
         
  ofstream outf("out.txt"); 
         
         
        double dt=1.0; 
         
        //for (dt=0.1; dt<10.0; dt+=0.1) { 
                 
         
         
  double a=100.0;   double g1=1000.0; 
  double g2=-1000.0; 
  double g3=-10.0; 
  double g4=10.0; 
         
  double x1=-a; 
  double x2=-a; 
  double y1=10.0; 
  double y2=-10.0; 
  double x3=a; 
  double x4=a; 
  double y3=10.0; 
  double y4=-10.0; 
   
  double u1,u2,u3,u4,v1,v2,v3,v4; 
  double pi=3.141592653589793238462643383279502884197169399; 
  double 
c11,c12,c13,c14,d11,d12,d13,d14,c21,c22,c23,c24,d21,d22,d23,d24,c31,c32,c33,
c34,d31,d32,d33,d34,c41,c42,c43,c44,d41,d42,d43,d44; 
         
         
  double Ei=0.0; 
  double Ee=0.0; 
  double Eerr=0.0; 
         
  double Mi=0.0; 
  double Me=0.0; 
  double Merr=0.0; 
         
         
        double xi[4],yi[4],xe[4],ye[4],gi[4],ge[4]; 
         
  xi[0]=x1; 
  yi[0]=y1; 
  xi[1]=x2;   yi[1]=y2; 
  xi[2]=x3; 
  yi[2]=y3; 
  xi[3]=x4; 
  yi[3]=y4; 
  gi[0]=g1; 
        gi[1]=g2; 
  gi[2]=g3; 
        gi[3]=g4; 
         
  for (int i=0;i<4;i++) { 
    for (int j=0;j<4;j++) { 
      if (i==j) 
                                Ei=Ei+0.0; 
      else 
                               
Ei=Ei+(-1.0/(8.0*pi))*gi[i]*gi[j]*log(pow((xi[i]-xi[j]),2.0)+pow((yi[i]-yi[j]),2.0)); 
                         
    } 
  } 
         
         
  for (int i=0;i<4;i++) { 
    Mi=Mi-(gi[i]*(pow(xi[i],2.0)+pow(yi[i],2.0))); 
  } 
           
         
  cout<<"Ei="<<Ei<<endl; 
        cout<<"Mi="<<Mi<<endl; 
         
         
  for (double t=0.0;t<4000.0;t+=dt) 
  { 
                 
                u1=u(x1,y1,x2,y2,g2)+u(x1,y1,x3,y3,g3)+u(x1,y1,x4,y4,g4);     v1=v(x1,y1,x2,y2,g2)+v(x1,y1,x3,y3,g3)+v(x1,y1,x4,y4,g4); 
    u2=u(x2,y2,x1,y1,g1)+u(x2,y2,x3,y3,g3)+u(x2,y2,x4,y4,g4); 
    v2=v(x2,y2,x1,y1,g1)+v(x2,y2,x3,y3,g3)+v(x2,y2,x4,y4,g4); 
    u3=u(x3,y3,x1,y1,g1)+u(x3,y3,x2,y2,g2)+u(x3,y3,x4,y4,g4); 
    v3=v(x3,y3,x1,y1,g1)+v(x3,y3,x2,y2,g2)+v(x3,y3,x4,y4,g4); 
    u4=u(x4,y4,x1,y1,g1)+u(x4,y4,x2,y2,g2)+u(x4,y4,x3,y3,g3); 
                v4=v(x4,y4,x1,y1,g1)+v(x4,y4,x2,y2,g2)+v(x4,y4,x3,y3,g3); 
                 
                 
                 
                c11=dt*u1; 
    d11=dt*v1; 
    c21=dt*u2; 
    d21=dt*v2; 
    c31=dt*u3; 
    d31=dt*v3; 
    c41=dt*u4; 
    d41=dt*v4; 
                 
 
  c12=dt*(u(x1+0.5*c11,y1+0.5*d11,x2+0.5*c21,y2+0.5*d21,g2)+u(x1+0.5*c
11,y1+0.5*d11,x3+0.5*c31,y3+0.5*d31,g3)+u(x1+0.5*c11,y1+0.5*d11,x4+0.5*c4
1,y4+0.5*d41,g4)); 
 
  d12=dt*(v(x1+0.5*c11,y1+0.5*d11,x2+0.5*c21,y2+0.5*d21,g2)+v(x1+0.5*c
11,y1+0.5*d11,x3+0.5*c31,y3+0.5*d31,g3)+v(x1+0.5*c11,y1+0.5*d11,x4+0.5*c4
1,y4+0.5*d41,g4)); 
               
c22=dt*(u(x2+0.5*c21,y2+0.5*d21,x1+0.5*c11,y1+0.5*d11,g1)+u(x2+0.5*c21,y2
+0.5*d21,x3+0.5*c31,y3+0.5*d31,g3)+u(x2+0.5*c21,y2+0.5*d21,x4+0.5*c41,y4+
0.5*d41,g4)); 
 
  d22=dt*(v(x2+0.5*c21,y2+0.5*d21,x1+0.5*c11,y1+0.5*d11,g1)+v(x2+0.5*c
21,y2+0.5*d21,x3+0.5*c31,y3+0.5*d31,g3)+v(x2+0.5*c21,y2+0.5*d21,x4+0.5*c4
1,y4+0.5*d41,g4));  
  c32=dt*(u(x3+0.5*c31,y3+0.5*d31,x1+0.5*c11,y1+0.5*d11,g1)+u(x3+0.5*c
31,y3+0.5*d31,x2+0.5*c21,y2+0.5*d21,g2)+u(x3+0.5*c31,y3+0.5*d31,x4+0.5*c4
1,y4+0.5*d41,g4)); 
 
  d32=dt*(v(x3+0.5*c31,y3+0.5*d31,x1+0.5*c11,y1+0.5*d11,g1)+v(x3+0.5*c
31,y3+0.5*d31,x2+0.5*c21,y2+0.5*d21,g2)+v(x3+0.5*c31,y3+0.5*d31,x4+0.5*c4
1,y4+0.5*d41,g4)); 
 
  c42=dt*(u(x4+0.5*c41,y4+0.5*d41,x1+0.5*c11,y1+0.5*d11,g1)+u(x4+0.5*c
41,y4+0.5*d41,x2+0.5*c21,y2+0.5*d21,g2)+u(x4+0.5*c41,y4+0.5*d41,x3+0.5*c3
1,y3+0.5*d31,g3)); 
 
  d42=dt*(v(x4+0.5*c41,y4+0.5*d41,x1+0.5*c11,y1+0.5*d11,g1)+v(x4+0.5*c
41,y4+0.5*d41,x2+0.5*c21,y2+0.5*d21,g2)+v(x4+0.5*c41,y4+0.5*d41,x3+0.5*c3
1,y3+0.5*d31,g3)); 
                 
 
  c13=dt*(u(x1+0.5*c12,y1+0.5*d12,x2+0.5*c22,y2+0.5*d22,g2)+u(x1+0.5*c
12,y1+0.5*d12,x3+0.5*c32,y3+0.5*d32,g3)+u(x1+0.5*c12,y1+0.5*d12,x4+0.5*c4
2,y4+0.5*d42,g4)); 
 
  d13=dt*(v(x1+0.5*c12,y1+0.5*d12,x2+0.5*c22,y2+0.5*d22,g2)+v(x1+0.5*c
12,y1+0.5*d12,x3+0.5*c32,y3+0.5*d32,g3)+v(x1+0.5*c12,y1+0.5*d12,x4+0.5*c4
2,y4+0.5*d42,g4)); 
               
c23=dt*(u(x2+0.5*c22,y2+0.5*d22,x1+0.5*c12,y1+0.5*d12,g1)+u(x2+0.5*c22,y2
+0.5*d22,x3+0.5*c32,y3+0.5*d32,g3)+u(x2+0.5*c22,y2+0.5*d22,x4+0.5*c42,y4+
0.5*d42,g4)); 
 
  d23=dt*(v(x2+0.5*c22,y2+0.5*d22,x1+0.5*c12,y1+0.5*d12,g1)+v(x2+0.5*c
22,y2+0.5*d22,x3+0.5*c32,y3+0.5*d32,g3)+v(x2+0.5*c22,y2+0.5*d22,x4+0.5*c4
2,y4+0.5*d42,g4)); 
 
  c33=dt*(u(x3+0.5*c32,y3+0.5*d32,x1+0.5*c12,y1+0.5*d12,g1)+u(x3+0.5*c32,y3+0.5*d32,x2+0.5*c22,y2+0.5*d22,g2)+u(x3+0.5*c32,y3+0.5*d32,x4+0.5*c4
2,y4+0.5*d42,g4)); 
 
  d33=dt*(v(x3+0.5*c32,y3+0.5*d32,x1+0.5*c12,y1+0.5*d12,g1)+v(x3+0.5*c
32,y3+0.5*d32,x2+0.5*c22,y2+0.5*d22,g2)+v(x3+0.5*c32,y3+0.5*d32,x4+0.5*c4
2,y4+0.5*d42,g4)); 
 
  c43=dt*(u(x4+0.5*c42,y4+0.5*d42,x1+0.5*c12,y1+0.5*d12,g1)+u(x4+0.5*c
42,y4+0.5*d42,x2+0.5*c22,y2+0.5*d22,g2)+u(x4+0.5*c42,y4+0.5*d42,x3+0.5*c3
2,y3+0.5*d32,g3)); 
 
  d43=dt*(v(x4+0.5*c42,y4+0.5*d42,x1+0.5*c12,y1+0.5*d12,g1)+v(x4+0.5*c
42,y4+0.5*d42,x2+0.5*c22,y2+0.5*d22,g2)+v(x4+0.5*c42,y4+0.5*d42,x3+0.5*c3
2,y3+0.5*d32,g3)); 
                 
 
  c14=dt*(u(x1+c13,y1+d13,x2+c23,y2+d23,g2)+u(x1+c13,y1+d13,x3+c33,y3
+d33,g3)+u(x1+c13,y1+d13,x4+c43,y4+d43,g4)); 
 
  d14=dt*(v(x1+c13,y1+d13,x2+c23,y2+d23,g2)+v(x1+c13,y1+d13,x3+c33,y3
+d33,g3)+v(x1+c13,y1+d13,x4+c43,y4+d43,g4)); 
               
c24=dt*(u(x2+c23,y2+d23,x1+c13,y1+d13,g1)+u(x2+c23,y2+d23,x3+c33,y3+d3
3,g3)+u(x2+c23,y2+d23,x4+c43,y4+d43,g4)); 
 
  d24=dt*(v(x2+c23,y2+d23,x1+c13,y1+d13,g1)+v(x2+c23,y2+d23,x3+c33,y3
+d33,g3)+v(x2+c23,y2+d23,x4+c43,y4+d43,g4)); 
 
  c34=dt*(u(x3+c33,y3+d33,x1+c13,y1+d13,g1)+u(x3+c33,y3+d33,x2+c23,y2
+d23,g2)+u(x3+c33,y3+d33,x4+c43,y4+d43,g4)); 
 
  d34=dt*(v(x3+c33,y3+d33,x1+c13,y1+d13,g1)+v(x3+c33,y3+d33,x2+c23,y2
+d23,g2)+v(x3+c33,y3+d33,x4+c43,y4+d43,g4)); 
 
  c44=dt*(u(x4+c43,y4+d43,x1+c13,y1+d13,g1)+u(x4+c43,y4+d43,x2+c23,y2+d23,g2)+u(x4+c43,y4+d43,x3+c33,y3+d33,g3)); 
 
  d44=dt*(v(x4+c43,y4+d43,x1+c13,y1+d13,g1)+v(x4+c43,y4+d43,x2+c23,y2
+d23,g2)+v(x4+c43,y4+d43,x3+c33,y3+d33,g3)); 
                 
                x1=x1+(1.0/6.0)*(c11+2.0*c12+2.0*c13+c14); 
                y1=y1+(1.0/6.0)*(d11+2.0*d12+2.0*d13+d14); 
                x2=x2+(1.0/6.0)*(c21+2.0*c22+2.0*c23+c24); 
                y2=y2+(1.0/6.0)*(d21+2.0*d22+2.0*d23+d24); 
    x3=x3+(1.0/6.0)*(c31+2.0*c32+2.0*c33+c34); 
    y3=y3+(1.0/6.0)*(d31+2.0*d32+2.0*d33+d34); 
    x4=x4+(1.0/6.0)*(c41+2.0*c42+2.0*c43+c44); 
    y4=y4+(1.0/6.0)*(d41+2.0*d42+2.0*d43+d44); 
                 
                 
                 
                 
                 
                 
                 
                 
                outf<<x2<<endl; 
                //cout<<y4<<endl; 
                 
  } 
         
  outf.close(); 
         
  xe[0]=x1; 
  ye[0]=y1; 
  xe[1]=x2; 
  ye[1]=y2; 
  xe[2]=x3; 
  ye[2]=y3; 
  xe[3]=x4;   ye[3]=y4; 
         
         
         
  for (int i=0;i<4;i++) { 
    for (int j=0;j<4;j++) { 
      if (i==j) 
                                Ee=Ee+0.0; 
      else 
                               
Ee=Ee+(-1.0/(8.0*pi))*gi[i]*gi[j]*log(pow((xe[i]-xe[j]),2.0)+pow((ye[i]-ye[j]),2.0
)); 
                         
    } 
  } 
         
         
  for (int i=0;i<4;i++) { 
    Me=Me-(gi[i]*(pow(xe[i],2.0)+pow(ye[i],2.0))); 
  } 
         
         
         
  cout<<"Ee="<<Ee<<endl; 
        cout<<"Me="<<Me<<endl; 
         
        Eerr=Ee-Ei; 
        Merr=Me-Mi; 
         
        cout<<"Eerr="<<Eerr<<endl; 
        cout<<dt<<endl; 
        cout<<"Merr="<<Merr<<endl; 
         
        system("pause"); 
                                  
//        } 
         
} 
 
 
 
double u(double xi,double yi,double xj,double yj,double k) 
{ 
        double pi=3.141592653589793238462643383279502884197169399; 
        double u; 
        u=(-1.0/(2.0*pi))*(k*(yi-yj))/(pow((xi-xj),2.0)+pow((yi-yj),2.0)); 
         
        return u; 
         
} 
 
 
double v(double xi,double yi,double xj,double yj,double k) 
{ 
        double pi=3.141592653589793238462643383279502884197169399; 
        double v; 
        v=(1.0/(2.0*pi))*(k*(xi-xj))/(pow((xi-xj),2.0)+pow((yi-yj),2.0)); 
         
        return v; 
         
} 