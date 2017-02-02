//
//  Lagrange_Interpolation.cpp
//  
//
//  Created by Y.Huang on 12/3/25.
//  Copyright (c) 2012 All rights reserved.
//
 
#include<iostream.h> 
#include<conio.h> 
#include<math.h> 
 
using namespace std; 
 
float fun(float); 
void cheby(int,double[]); 
void us(int,double[]); 
 
int main() 
{ 
         
        FILE *fp; 
  char *fn="C:/numerical outputs/HW2/Q1(b)output6.txt"; 
        fp=fopen(fn,"w"); 
 
         
         
        int n,i,j; 
        double mult,sum=0.0,x[100],f[100],a=-1.0; 
         
        cout<<"Enter no of sample points ? "; 
        cin>>n; 
        //cout<<"Enter all values of x and corresponding funtional value: "<<endl; 
         
        //cheby(n,x); 
        us(n,x); 
         
        for(i=0;i<n;i++) { 
                f[i]=fun(x[i]); 
                }                  
   
                 
        //cout<<"\nEnter your x for calculation : "; 
        //cin>>a; 
 
      for(a=-1.0;a<1.0;a+=0.01) { 
 
        for(i=0;i<=n-1;i++) 
        { 
        mult=1; 
                for(j=0;j<=n-1;j++) 
                { 
                        if(j!=i) 
                        mult*=(a-x[j])/(x[i]-x[j]); 
                } 
                sum+=mult*f[i]; 
        } 
        //cout<<"\nThe estimated value of f(x) = "<<sum; 
        fprintf(fp,"%g    \n",sum); 
   
 
        sum=0.0; 
      } 
          fclose(fp); 
        getch(); 
        return 0; 
} 
 
float fun(float x) 
{ 
            return cos(2*x)*exp(-x); 
} 
 
 
void cheby(int n,double x[100]) 
{ 
          double pi=3.1415926;           for (int i=0;i<n;i++){ 
                  x[i]=cos(((pi/2.0)+static_cast<double>(i)*pi)/static_cast<double>(n)); 
                  } 
 
} 
 
void us(int n,double x[100]) 
{ 
          double s=2.0/static_cast<double>(n); 
          for (int i=0;i<n;i++){ 
                  x[i]=-1+static_cast<double>(i)*s; 
                  } 
} 