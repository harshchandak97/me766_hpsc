#include <stdio.h>
#include <omp.h>
#include <math.h>

int main()
{
int n =100;
float pi = 3.14159, area = 0, x = 0, x1 = 0;
for (int i = 0; i < n+1; ++i)
{
	x1 = i*pi/n ;
	area = area + (sin(x) + sin(x1))/2*(x1 - x);
	x = x1;
}
printf("Area under a sine curve between 0 to pi using Trapezoidal method = %f \n", area);
	
}
