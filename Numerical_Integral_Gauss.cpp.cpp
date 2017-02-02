//
//  Numerical_Integral_Gauss.cpp
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
 
#define num 13 
double f(double x); 
double l(double xl,double xu,double *tmp); 
int _tmain(int argc, _TCHAR* argv[]) 
{ 
 
FILE *fp; 
char *fn="output.txt"; 
fp=fopen(fn,"w"); 
int n=num; 
int i,j,k; 
double legendre[num+1][num+1]; 
for(i=0;i<=num;i++){  
  for(j=0;j<=num;j++){legendre[i][j]=0.0; 
  }} 
for(i=1;i<=num;i++){legendre[0][i]=0;} 
legendre[0][0]=1.; 
for(i=2;i<=num;i++){legendre[1][i]=0;} 
legendre[1][0]=0;legendre[1][1]=1.; 
for(i=2;i<=num;i++){ 
legendre[i][i]=(2.*i-1)/i*legendre[i-1][i-1]; 
legendre[i][i-1]=(2*i-1)/i*legendre[i-1][i-2]; 
legendre[i][i-2]= ( (2*i-1)*legendre[i-1][i-3]-(i-1)*legendre[i-2][i-2] )/i ; 
 
for(j=1;j<=i-2;j++){ 
legendre[i][j]=( (2*i-1)*legendre[i-1][j-1]-(i-1)*legendre[i-2][j] )/i ; 
} 
legendre[i][0]= -(i-1)*legendre[i-2][0]/i; 
} 
 
//show the legendre matrix 
/* 
for(i=0;i<=num;i++){ 
  for(j=0;j<=num;j++){ 
    printf("%g  ," ,legendre[i][j]);} printf("\n");} 
*/ 
//get the roots of legendre polynomial 
double tmp[num+1]; 
for(i=0;i<=num;i++){tmp[i]=legendre[num][i];} 
double eps_x=1.0E-12; 
double root[num]; 
for(k=0;k<num;k++){ 
 
double x0=0.,x1=1.,examine; 
int flag=0; 
for(i=1;i<=999;i++){ 
          if(flag){break;} 
double fn=0.,fn_1=0.   ;              
for(j=0;j<=num;j++){fn=fn+tmp[j]*pow(x1,j) ;}     
for(j=0;j<=num;j++){fn_1=fn_1+tmp[j]*pow(x0,j)  ;} 
examine=x1-fn*(x1-x0)/(fn-fn_1); 
 
                 
               if(fabs(x1-x0)>eps_x){ 
                   
                        x0=x1; 
                        x1=examine; 
                 
        } 
                  if(fabs(x1-x0)<=eps_x){flag=3;} 
                  if(fabs(examine)<=eps_x){flag=3;} 
         
                 
                 
}       
if(flag==3){printf("the root is %.5f\n",x1);} 
root[k]=x1; 
double tmp2[num]; 
for(i=0;i<=num;i++){tmp2[i]=tmp[i];} 
tmp[num-k]=0.0; 
tmp[num-1-k]=tmp2[num-k]; 
for(i=num-2-k;i>=0;i--){tmp[i]=tmp2[i+1]+tmp[i+1]*x1;} 
} 
//calculate the integration 
double c[num]; 
double dlegen[num-1]; 
double intelegen[num]; 
intelegen[0]=0.0; 
for(i=0;i<=num-1;i++){dlegen[i]=legendre[num][i+1]*(i+1);} 
double tmp2[num]; 
for(j=0;j<num;j++){ 
for(i=0;i<=num;i++){tmp2[i]=legendre[num][i];} 
tmp[num]=0.0; tmp[num-1]=tmp2[num]; 
for(i=num-2;i>=0;i--){tmp[i]=tmp2[i+1]+tmp[i+1]*root[j];} 
for(i=0;i<num;i++){intelegen[i+1]=tmp[i]/(i+1);} 
double intelegen1=0.,intelegen_1=0.,ddi=0.; 
for(i=0;i<=num;i++){intelegen1=intelegen1+intelegen[i]; 
intelegen_1=intelegen_1+intelegen[i]*pow(-1.,i); 
} 
for(i=0;i<num;i++){ddi=ddi+dlegen[i]*pow(root[j],i);} 
c[j]=(intelegen1-intelegen_1)/ddi;} 
double ans=0.; 
for(i=0;i<=num;i++){ 
  ans=ans+c[i]*f(root[i]);} 
 
ans=ans*2.47*exp(2.13/2)/2.; 
 
printf("%15.13lf",ans); 
//for(i=0;i<num;i++){printf(" %g %g %g %g %g\n",c[i],intelegen[i],dlegen[i],tmp[i],tmp2[i]);} 
fclose(fp); 
        getche(); 
    return 0; 
} 
 
double f(double x){return exp(x*(2.47)/2);} 