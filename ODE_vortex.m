//
//  PDE_vortex.m
//  
//
//  Created by Y.Huang on 12/3/25.
//  Copyright (c) 2012 All rights reserved.
//

pi=3.1415926 
[x,y]=meshgrid(-2:0.22:2); 
r=(x.^2+y.^2); 
z=-log(r.^0.5); 
u1=-y./r; 
v1=x./r; 
quiver(x,y,u1,v1); 
hold on; 
contour(x,y,z,60); 