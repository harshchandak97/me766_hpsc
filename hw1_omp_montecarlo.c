#include <stdio.h>
#include <omp.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main() 
{
int n, threads, inside_curve = 0;
long double random_x, random_y, area, pi = 3.14159 ;
float start_time, end_time, duration;

printf("Enter the number of sampling points: ");
scanf("%d",&n);
printf("Enter the number of threads: ");
scanf("%d",&threads);

omp_set_num_threads(threads);
start_time = omp_get_wtime();
srand(time(NULL));

#pragma omp parallel for private(random_x,random_y) reduction(+:inside_curve)
for (int i = 0; i < n; ++i)	
{
	random_x = (double)rand()/(double)RAND_MAX*pi ; //Generating a random number in the range 0 to pi
	random_y = (double)rand()/(double)RAND_MAX ; // Generating a random number in the range 0 to 1
	if (random_y <= sin(random_x)) //Checking whether the point lies inside the curve (here sin(x))
		{
			inside_curve++ ; //If the point lies inside increment the number of points by 1		
		}	
}

area = (float)inside_curve/(float)n*pi ; //Area under the curve = (points inside)/(Total points)*Area of the rectangle
printf("Area under a sine curve between 0 to pi using Monte Carlo method = %Lf \n",area);
end_time = omp_get_wtime();
duration = end_time - start_time;
printf("Time taken to run (in seconds) %f\n",duration);
return 0;
}