#include "RootFinder.h"
#include <stdlib.h>
#include <iostream>

RootFinder::RootFinder(double tolerance_, double max_iterations_)
{
	num_iters = 0;
	tolerance = tolerance_;
	max_iterations = max_iterations_;
}

// Implemetaion of the Secant Method - a finite differences version of Newtons Method
double RootFinder::SecantMethod(std::function<double(double)> Func, double lower_bound, double upper_bound)
{
	if (num_iters != 0) { num_iters = 0; }
	double x_im1 = lower_bound;
	double x_im2 = upper_bound;
	double x_i;

	// num_iters is the private member function that keeps track of how many iterations the current method has taken
	// It can be accessed by the GetNumberOfIterations() method
	for (num_iters; num_iters<max_iterations; num_iters++)
	{
		x_i = (x_im2*Func(x_im1) - x_im1 * Func(x_im2)) / (Func(x_im1) - Func(x_im2));
		double relative_error = abs(x_i - x_im1);
		if (relative_error < tolerance) { std::cout << "Converged in " << num_iters << " iterations" << std::endl; break; }
		if (num_iters == max_iterations - 1) {std::cout << "Max Iterations reached. Relative error level = " << relative_error << std::endl;}
		x_im2 = x_im1; x_im1 = x_i;
	}
	return x_i;
}

//template<typename Func, typename T>
//double RootFinder::SecantMethod(Func F, T lower_bound, T upper_bound)
//{
//	T x_im1 = lower_bound;
//	T x_im2 = upper_bound;
//	T x_i;
//	for(int i =0; i<max_iterations;i++)
//	{
//		x_i = (x_im2*F(x_im1) - x_im1 * F(x_im2)) / (F(x_im1) - F(x_im2));
//		T relative_error = abs(x_i - x_im1);
//		if ( relative_error < tolerance) { break; }
//		if (i == max_iterations - 1) { std::cout << "Max Iterations reached. Relative error level = " << relative_error << std::endl; }
//	}
//}