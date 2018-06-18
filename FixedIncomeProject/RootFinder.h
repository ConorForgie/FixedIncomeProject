#pragma once
#include <functional>

class RootFinder
{
public:
	RootFinder(double tolerance_ = 1e-6, double max_iterations_ = 1e4);
	double SecantMethod(std::function<double(double)> Func, double lower_bound, double upper_bound);
	int GetNumberOfIterations() { return num_iters; };

	/*template<typename Func,typename T>
	double SecantMethod(Func F, T lower_bound, T upper_bound)
	{
		T x_im1 = lower_bound;
		T x_im2 = upper_bound;
		T x_i;
		for (int i = 0; i<max_iterations; i++)
		{
			x_i = (x_im2*F(x_im1) - x_im1 * F(x_im2)) / (F(x_im1) - F(x_im2));
			T relative_error = abs(x_i - x_im1);
			if (relative_error < tolerance) { std::cout << "Converged in " << i << " iterations" << std::endl; break; }
			if (i == max_iterations - 1) { std::cout << "Max Iterations reached. Relative error level = " << relative_error << std::endl; }
			x_im2 = x_im1; x_im1 = x_i;
		}
		return x_i;
	};*/


private:
	double tolerance;
	int max_iterations;
	int num_iters;
};


