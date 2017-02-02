//
//  Rounding_Error_recursive.cpp
//  
//
//  Created by Y.Huang on 12/3/18.
//  Copyright (c) 2012 All rights reserved.
//

#include <iostream>
using namespace std;
float recursive1(float);
float recursive2(float);

int main()
{
    cout<< "recursive2"<<endl;
    for (int counter = 0;counter <= 50; counter++)
    {
        cout.precision(10);
        cout <<recursive2(counter)<<endl;
        //cout <<recursive1(counter)<<endl;
    }
    return 0;
}

float recursive1(float number)
{
    if((number == 0)||(number == 1))
        return (1.0-(number*0.4));
    else 
        return (-1.4*recursive1(number-1))+(1.2*recursive1(number-2)); 
}

float recursive2(float number2)
{
    if(number2 == 0)
        return 1.0;
    else 
        return (0.6*recursive2(number2-1)); 
}

