//
//  Interpolation_tension.cpp
//  
//
//  Created by Y.Huang on 12/3/25.
//  Copyright (c) 2012 All rights reserved.
//
#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include<iostream> 
 
using namespace std; 
 
int main(void){ 
        double x_0[9]={-0.96,-0.76,-0.32,-0.14,-0.08,0.12,0.54,0.66,0.90},x,ans; 
        double a[9]={-0.13,-0.092,-0.0051,0.071,0.067,0.044,0.017,-0.013,0.012}; 
  double b[8]={0.0},c[9]={0.0},d[8]={0.0},h[8]={0.0},p[9]={0.0}; 
  double A[9][9]={0.0},L[9][9]={0.0},U[9][9]={0.0},z[9]={0.0}; 
  double tau; 
     cout<<"Please Enter value of tau:"<<endl; 
        cin>>tau; 
       
  FILE *e; 
  e=fopen("c_spline.txt","w"); 
/*****************************計算
h[i]*****************************************/   
  for(int i=0;i<=7;i=i+1) 
        h[i]=x_0[i+1]-x_0[i]; 
/***********************計算矩陣運算中 Ac=p 的
p**********************************/ 
        p[0]=0.0;         
        p[8]=0.0;//Nature 
        //p[0]=-((a[1]-a[0])/h[0]); 
        //p[8]=-((a[8]-a[7])/h[7]);//clamped BC 
        for(int i=1;i<=7;i=i+1) 
              p[i]=(pow(tau,2.0)*(a[i+1]-a[i]))/h[i];         
 
 
/***********************計算矩陣運算中 Ac=p 的
p(orig)*****************************         
  p[0]=0; 
  p[8]=0; 
  for(int i=1;i<=7;i=i+1) 
        p[i]=3*(a[i+1]-a[i])/h[i]-3*(a[i]-a[i-1])/h[i-1]; 
************************計算矩陣運算中 Ac=p 的
p(orig)****************************/         
 
 
/***********************計算矩陣運算中 Ac=p 的
A**********************************/ 
        A[0][0]=1.0; 
        A[8][8]=1.0;//Nature 
        //A[0][0]=-(1.0/tau)*(((tau*cosh(tau*h[0]))/sinh(tau*h[0]))-1.0/h[0]); 
        //A[8][8]=(1.0/tau)*(((tau*cosh(tau*h[7]))/sinh(tau*h[7]))-1.0/h[7]); 
        //A[0][1]=-(1.0/tau)*((1.0/h[0])-(tau/sinh(tau*h[0]))); 
        //A[8][7]=(1.0/tau)*((1.0/h[7])-(tau/sinh(tau*h[7])));//clamped BC 
        for(int i=1;i<=7;i=i+1){                 A[i][i-1]=(1.0/h[i-1])-(tau/sinh(tau*h[i-1])); 
               
A[i][i]=((tau*cosh(tau*h[i-1]))/sinh(tau*h[i-1]))-(1.0/h[i-1])+((tau*cosh(tau*h[i]))/sinh
(tau*h[i]))-(1.0/h[i]); 
                A[i][i+1]=(1.0/h[i])-(tau/sinh(tau*h[i])); 
        } 
 
/***********************計算矩陣運算中 Ac=p 的
A(orig)*****************************         
  A[0][0]=1; 
  A[8][8]=1; 
  for(int i=1;i<=7;i=i+1){ 
                A[i][i-1]=h[i-1]; 
                A[i][i]=2*(h[i-1]+h[i]); 
                A[i][i+1]=h[i]; 
        } 
************************計算矩陣運算中 Ac=p 的
A(orig)****************************/         
         
         
         
/**********對帶狀矩陣 A 進行 LU 分解，由 Ac=LUc=Lz=p 找出 L、U、
z*********************/   
        L[0][0]=A[0][0]; 
        U[0][1]=A[0][1]/L[0][0]; 
        z[0]=p[0]/L[0][0]; 
        for(int i=0;i<=8;i=i+1) 
                U[i][i]=1.0; 
   
  for(int i=1;i<=7;i=i+1){ 
                L[i][i-1]=A[i][i-1]; 
                L[i][i]=A[i][i]-U[i-1][i]*L[i][i-1]; 
                U[i][i+1]=A[i][i+1]/L[i][i]; 
                z[i]=(p[i]-z[i-1]*L[i][i-1])/L[i][i]; 
        } 
         
        L[8][7]=A[8][7]; 
        L[8][8]=A[8][8]-U[7][8]*L[8][7];         z[8]=(p[8]-z[7]*L[8][7])/L[8][8]; 
/**********************由 z=Uc 解出 c，並由 c 推得 b、
d(orig)*************************         
        c[8]=z[8]; 
        for(int i=7;i>=0;i=i-1){ 
                c[i]=z[i]-U[i][i+1]*c[i+1]; 
                b[i]=(a[i+1]-a[i])/h[i]-h[i]*(c[i+1]+2*c[i])/3; 
                d[i]=(c[i+1]-c[i])/(3*h[i]); 
        } 
*****************由 z=Uc 解出 c，並由 c 推得 b、
d(orig)******************************/     
        c[8]=z[8]; 
        for(int i=7;i>=0;i=i-1){ 
                c[i]=z[i]-U[i][i+1]*c[i+1]; 
        } 
     
     
         
/**************所以  Si(x)=a[i] + b[i]*x + c[i]*x^2 + d[i]*x^3 *****************/   
/****************列印出 x=-0.96 to 0.9    步近間隔 0.01 的值
************************/   
        for(int i=0;i<=7;i=i+1){ 
                for(x=x_0[i];x<=x_0[i+1]+0.01;x=x+0.01){ 
                      //ans=a[i]+b[i]*(x-x_0[i])+c[i]*pow((x-x_0[i]),2)+d[i]*pow((x-x_0[i]),3); 
                      // printf("%f          %f\n",x,ans); 
                      // fprintf(e,"%f          %f\n",x,ans); 
                         
ans=(c[i]*sinh(tau*(x_0[i+1]-x))+c[i+1]*sinh(tau*(x-x_0[i])))/(pow(tau,2.0)*sinh(tau*
h[i]))+(a[i]-(c[i]/pow(tau,2.0)))*(x_0[i+1]-x)/h[i]+(a[i+1]-(c[i+1]/pow(tau,2.0)))*(x-x_0[
i])/h[i]; 
                      printf("%f\n",ans); 
                      fprintf(e,"%f\n",ans); 
                } 
        } 
  fclose(e); 
  system("pause"); 
  return 0; 
} 