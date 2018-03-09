#include <stdio.h>
#include <omp.h>
#include <math.h>

int main()
{
int n;
float pi = 3.14159, area = 0, x = 0, x1 = 0;
printf("Enter the number of divisions: ");
scanf("%d",&n);

for (int i = 0; i < n+1; ++i)
{
	x1 = i*pi/n ; //Breaking the range 0 to pi into n intervals
	area = area + (sin(x) + sin(x1))/2*(x1 - x); //Adding area of each small trapezoid interatively 
	//area of the trapezoid with vertices (x,0) (x,sin(x)) (x1,0) (x1,sin(x1))
	x = x1; //Updating x for the next interval
}
printf("Area under a sine curve between 0 to pi using Trapezoidal method = %f \n", area);
	
}
