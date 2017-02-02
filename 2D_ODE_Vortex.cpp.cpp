//
//  2D_ODE_Vortex.cpp
//  
//
//  Created by Y.Huang on 12/4/1.
//  Copyright (c) 2012 All rights reserved.
// 
#include "stdafx.h" 
#include <iostream>  
#include <fstream> 
#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <cmath> 
#include <math.h>  
#include <cstdlib> 
#include <fstream> 
 
using namespace std; 
 
double u(double,double,double,double,double); 
double v(double,double,double,double,double); 
 
 
int main() 
{ 
   
  ofstream outf("out.txt"); 
 
  double a=10.0; 
  double g1=-10.0; 
  double g2=20.0; 
  double x1=-a; 
  double x2=a; 
  double y1=0.0; 
  double y2=0.0; 
  double dt=1.0; 
  double u1,u2,v1,v2; 
  double pi=3.141592653589793238462643383279502884197169399; 
   
  for (double t=0.0;t<2000.0;t+=dt) 
  { 
     
    u1=u(x1,y1,x2,y2,g2); 
    v1=v(x1,y1,x2,y2,g2); 
    u2=u(x2,y2,x1,y1,g1); 
    v2=v(x2,y2,x1,y1,g1); 
 
  //  cout<<x1-x2<<endl; 
      
 
    x1+=u1*dt; 
    x2+=u2*dt; 
    y1+=v1*dt; 
    y2+=v2*dt; 
 
     // outf << x1 << "\n" ; 
       
  //  outf << y1 << "\n" ; 
     //  outf << x2 << "\n" ; 
 
    outf << y2 << "\n" ; 
 
 
 
  } 
   
  outf.close(); 
   
} 
 
 
 
double u(double xi,double yi,double xj,double yj,double k) 
{ 
   double pi=3.141592653589793238462643383279502884197169399; 
     double u; 
   u=(-1.0/(2.0*pi))*(k*(yi-yj))/(pow((xi-xj),2.0)+pow((yi-yj),2.0)); 
 
   return u; 
 
} 
 
 
double v(double xi,double yi,double xj,double yj,double k) { 
   double pi=3.141592653589793238462643383279502884197169399; 
     double v; 
   v=(1.0/(2.0*pi))*(k*(xi-xj))/(pow((xi-xj),2.0)+pow((yi-yj),2.0)); 
     
   return v; 
 
} 