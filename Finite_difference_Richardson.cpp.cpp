//
//  Finite_difference_Richardson.cpp
//  
//
//  Created by Y.Huang on 12/4/1.
//  Copyright (c) 2012 All rights reserved.
// 
 

#include "stdafx.h" 
#include "stdio.h" 
#include "conio.h" 
#include "math.h" 
#include <iostream> 
using namespace std; 
 
 
int _tmain(int argc, _TCHAR* argv[]) 
{ 
  int i=0; 
  int k; 
  double p; 
  double j=0.0; 
  double x[5000],f[5000],f3[5000],nf3[5000],e[5000],y[5000]; 
  double xx[10000],ff[10000],nff3[10000]; 
  double pi=3.141592653589793238462643383279502884197169399; 
  double h; 
  double n; 
  double err=0.0; 
      
    FILE *fout; 
  fout=fopen("out.txt","w+t"); 
 
    cout<<"Enter N:"; 
  cin>>n; 
    h=2.0/n; 
 
     
 
 
  for (i=0;i<=n;i++) 
    { 
      x[i]=-1.0+h*i; 
      f[i]=exp(-(x[i])); 
      f3[i]=-exp(-(x[i])); 
         //   fprintf(fout,"%g  \n",x[i]); 
      printf("%g \n",x[i]); 
    } 
 
  for (i=0;i<=2*n;i++) 
    { 
      xx[i]=-1.0+((h/2.0)*i); 
      ff[i]=exp(-(xx[i])); 
      printf("%g \n",xx[i]); 
    } 
 
  for (i=0;i<=(2*n-12);i++) 
    { 
       
            
nff3[i]=(-17.0*ff[i]+71.0*ff[i+1]-118.0*ff[i+2]+98.0*ff[i+3]-41.0*ff[i+4]+7.0*ff[i+5])/(4.0*
pow(h,3.0));   
    } 
 
  for (i=(2*n-11);i<=2*n;i++)  
    { 
       
            
nff3[i]=(17.0*ff[i]-71.0*ff[i-1]+118.0*ff[i-2]-98.0*ff[i-3]+41.0*ff[i-4]-7.0*ff[i-5])/(4.0*p
ow(h,3.0)); 
    } 
   
  for (i=0;i<=n-6;i++) 
    { 
       
            
nf3[i]=(-17.0*f[i]+71.0*f[i+1]-118.0*f[i+2]+98.0*f[i+3]-41.0*f[i+4]+7.0*f[i+5])/(4.0*pow(h,3
.0)); 
    } 
 
  for (i=n-5;i<=n;i++) 
    { 
       
            
nf3[i]=(17.0*f[i]-71.0*f[i-1]+118.0*f[i-2]-98.0*f[i-3]+41.0*f[i-4]-7.0*f[i-5])/(4.0*pow(h,3.
0)); 
    }   
 
  for (i=0;i<=n;i++) 
    { 
       
      y[i]=nf3[i]-f3[i]; 
      if (y[i]<0) 
      { 
      y[i]=-y[i]; 
      } 
      p=pow(y[i],2.0); 
      j=j+p; 
      } 
     err=sqrt(j/(n+1)); 
    printf("e=%g \n",log(err)); 
 
  _getche(); 
  return 0; 
} 