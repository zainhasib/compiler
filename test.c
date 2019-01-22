#include<graphics.h> 
#include<stdlib.h>
#include<string.h>
  
int main() 
{ 
    int gd = DETECT, gm; 
    initgraph(&gd, &gm, ""); 
    circle(250, 200, 50); 
  
    getch();  
    closegraph(); 
  
    return 0; 
} 