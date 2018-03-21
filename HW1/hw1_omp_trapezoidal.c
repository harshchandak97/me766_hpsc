#include <stdio.h>
#include <omp.h>
#include <math.h>

int main()
{
int n, threads;
float pi = 3.14159, area = 0, x = 0, x1 = 0;
float start_time, end_time, duration;
printf("Enter the number of divisions: ");
scanf("%d",&n);
printf("Enter the number of threads: ");
scanf("%d",&threads);

omp_set_num_threads(threads);
start_time = omp_get_wtime();
#pragma omp parallel for default(none) firstprivate(x,x1) shared(pi,n) reduction(+:area)
for (int i = 0; i < n+1; ++i)
{
	x = i*pi/n ; //Breaking the range 0 to pi into n intervals
	x1 = (i+1)*pi/n;
	area = area + (sin(x) + sin(x1))*(x1 - x)/2; //Adding area of each small trapezoid interatively 
	//area of the trapezoid with vertices (x,0) (x,sin(x)) (x1,0) (x1,sin(x1))

}
printf("Area under a sine curve between 0 to pi using Trapezoidal method = %f \n", area);
end_time = omp_get_wtime();
duration = end_time - start_time;
printf("Time taken to run (in seconds) %f\n",duration);
return 0;	
}
