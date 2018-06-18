// FixedIncomeProject.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "RootFinder.h"
#include "Bond.h"

int main()
{
    /*
    // Demo python script call NOTE for WINDOWS \\ or for LINUX /
    // WINDOWS
    std::string filename = "C:\\Users\\con-4\\Documents\\Uni\\CMF\\Thesis\\DeltaHedgingCall.py";
    std::string command = "python ";
    // LINUX
    // std::string filename = "/mnt/c/Users/con-4/Documents/Uni/CMF/Thesis/DeltaHedgingCall.py";
    // std::string command = "python3 ";
    command += filename;
    system(command.c_str());
    */

	double yield = 0.01;
	double coupon_rate = 0.05;
	double face_value = 100;
	double tenor = 10;

	Bond b(yield, coupon_rate, face_value, tenor);

	std::cout << "Bond NPV: " << b.NetPresentValue() << " DV01: " << b.DV01() << std::endl;	

	auto nBNPV = [&b](double y) {return b.PriceFromYield(y) ; };
	RootFinder finder(1e-6,1e4);
	try
	{
		double root = finder.SecantMethod(nBNPV, 1E-5, 0.2);
		std::cout << "Yeild from price " << root << std::endl << "Number of iterations " << finder.GetNumberOfIterations() << std::endl;
	}
	catch (std::exception e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}


	
	
	int a;
	std::cin >> a;
    return 0;
}


