#include<stdio.h>
int main()
{
 float x1 = 5, y1 = 4, x2 = 3, y2 = 2;
  float slope;
  slope = (y2-y1)/(x2-x1);
  printf("the slope of point (%.3f, %.3f) and (%.3f, %.3f is: %.3f", x1,y1,x2,y2,slope);
}