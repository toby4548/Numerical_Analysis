//
//  Finite_difference.cpp
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
 
  double x[10000],f[10000],f3[10000],nf3[10000],e[10000],hi[10000]; 
  double n; 
  double err=0.0; 
  double h; 
  FILE *fout; 
  fout=fopen("out1.txt","w+t"); 
 
  cout<<"Enter N:"; 
  cin>>n; 
  h=2.0/n; 
 
  int i=0; 
   
  for (i=0;i<=n;i++) 
    { 
      x[i]=-1.0+h*i; 
      f[i]=exp(-(x[i])); 
      f3[i]=-exp(-(x[i])); 
      hi[i]=-1.0+h*i; 
      //fprintf(fout,"hi%d=%g  \n",i,hi[i]); 
        fprintf(fout,"%g  \n",hi[i]); 
    }  
  for (i=0;i<=n-6;i++) 
    { 
  nf3[i]=(-17.0*f[i]+71.0*f[i+1]-118.0*f[i+2]+98.0*f[i+3]-41.0*f[i+4]+7.0*f[i+5])/(4.0*pow(h,3.0)); 
      e[i]=f3[i]-nf3[i]; 
    } 
 
  for (i=n-5;i<=n;i++) 
    { 
  nf3[i]=(17.0*f[i]-71.0*f[i-1]+118.0*f[i-2]-98.0*f[i-3]+41.0*f[i-4]-7.0*f[i-5])/(4.0*pow(h,3.0)); 
      e[i]=f3[i]-nf3[i]; 
    } 
 
  for (i=0;i<=n;i++) 
    { 
      //fprintf(fout,"f3 %d=%g \n",i,f3[i]); 
//        fprintf(fout,"%g \n",f3[i]); 
      } 
      fprintf(fout,"\n"); 
 
  for (i=0;i<=n;i++) 
    { 
      //fprintf(fout,"nf3 %d=%g\n",i,nf3[i]); 
//      fprintf(fout,"%g \n",nf3[i]); 
    } 
      fprintf(fout,"\n"); 
 
  for (i=0;i<=n;i++) 
    { 
      //fprintf(fout,"e%d=%g \n",i,e[i]); 
//      fprintf(fout,"%g \n",e[i]); 
      printf("%g \n",e[i]); 
    } 
      fprintf(fout,"\n");   for (i=0;i<=n;i++) //total abs error 
        { 
      err=err+((e[i])*(e[i])); 
      }  
        err=sqrt(err/n); 
        printf( "n=%g  total error = %g",n,err); 
        fprintf(fout,"%g",err); 
 
  fclose(fout); 
   
  return 0; 
} 