//
//  Rounding_Error.cpp
//  
//
//  Created by Y.Huang on 12/3/18.
//  Copyright (c) 2012 All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
float root(float,float,float);
float parabola(float,float,float,float);

int main ()
{
    float a,b,c,d,e,f,g,h,i,j;
    a=pow(10,-5);
    b=-2;
    c=0.2; 
    d=(1/(sqrt(2)));
    e=-sqrt(31398);
    f=0.2;
    g=root(a,b,c);
    h=root(d,e,f);
    i=parabola(a,b,c,g);
    j=parabola(d,e,f,h);
    
    cout.precision(10);
    
    cout<<"-Root of (a) "<<g<<endl<<"Value of (a) "<<i<<endl<<"-Root of (b) "<<h<<endl<<"Value of (b) "<<j<<endl;
    
    return 0;
}//end main

float root(float number1,float number2,float number3)
{
    float number;
    return number=((-number2)-sqrt(pow(number2,2)-(4*number1*number3)))/(2*number1);    
}//end root


float parabola(float number4,float number5,float number6,float number7)
{
    float answer;
    return answer=(number4*(pow(number7,2)))+(number5*number7)+number6;
}//end parabola




