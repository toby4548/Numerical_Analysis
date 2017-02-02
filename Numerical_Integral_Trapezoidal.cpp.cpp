//
//  Numerical_Integral_Trapezoidal.cpp
//  
//
//  Created by Y.Huang on 12/4/1.
//  Copyright (c) 2012 All rights reserved.
// 

#include "stdafx.h" 
#include "stdio.h" 
#include "conio.h" 
#include "math.h" 
#include "stdlib.h" 
#include <cmath> 
#define num 160 
double f(double x); 
int _tmain(int argc, _TCHAR* argv[]) 
{  
 
 
 
 
  FILE *fp; 
  char *fn="output.txt"; 
    fp=fopen(fn,"w"); 
int i,n=num; //n points 
double x[num]; 
double y[num]; 
//uniformly spaced grid 
double a=-0.17; 
double b=2.3; 
double h=(b-a)/(n-1); 
for(i=0;i<n;i++){ 
x[i]=a+h*i;//printf("%g\n",x[i]); 
} 
for(i=0;i<n;i++){  
y[i]=f(x[i]);//printf("%g\n",y[i]); 
 
} 
double sum=0.; 
for(i=0;i<n-1;i++){  
sum=sum+h*0.5*(y[i+1]+y[i]); 
} 
printf("approx= %g\n",sum);printf("abs = 9.130517638"); 
    fclose(fp); 
        getche(); 
return 0; 
} 
double f(double x){return exp(x);} 
 
