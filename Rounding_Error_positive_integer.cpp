//
//  Rounding_Error_positive_integer.cpp
//  
//
//  Created by Y.Huang on 12/3/18.
//  Copyright (c) 2012 All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
   
    
    for (int n = 1;n < 100000000;n+=1000)
    {

        float x;
        x = 1.0/n;
        cout<<"X(n="<<n<<")= "<<x<<"   (n+1)*X-1(n="<<n<<")="<<(((n+1.0)*x)-1.0)<<endl;
        
    }

    return 0;
}

