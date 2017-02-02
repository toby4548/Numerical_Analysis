//
//  PDE_Multi_Vortex.m
//  
//
//  Created by Y.Huang on 12/3/25.
//  Copyright (c) 2012 All rights reserved.
//

[x,y]=meshgrid(-3:0.22:3); 
r=((x+1).^2+y.^2); 
u1=+y./r; 
v1=-(x+1)./r; 
s=((x-1).^2+y.^2); 
u2=-y./s; 
v2=(x-1)./s; 
%t=(x.^2+(y-(3^0.5)).^2) 
%u3=-(y-(3^0.5))./t; 
%v3=(x)./t; 
%u=u1+u2+u3; 
%v=v1+v2+v3; 
u=u1+u2; 
v=v1+v2; 
%z=-log(r.^0.5)-log(s.^0.5)-log(t.^0.5); 
z=+log(r.^0.5)-log(s.^0.5) 
quiver(x,y,u,v); 
hold on; 
contour(x,y,z,60); 