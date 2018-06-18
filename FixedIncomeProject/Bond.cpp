#include "Bond.h"
#include <cmath>



Bond::Bond(double yield_, double coupon_rate, double face_value_, double maturity_)
{
	yield = yield_;
	coupon = coupon_rate*face_value_; 
	face_value = face_value_;
	maturity = maturity_;
}

// Returns the price of a bond from a given yield
double Bond::PriceFromYield(double new_yield)
{
	return ((1 / new_yield)*(1 - (1 / std::pow(1 + new_yield, maturity))) * coupon + std::pow((1 / (1 + new_yield)), maturity) * face_value);
}

// Returns the price of the current bond
double Bond::NetPresentValue()
{
	return PriceFromYield(yield);
}


double Bond::DV01()
{
	return -(1 / yield * yield)*(1 - (1 / std::pow(1 + yield, maturity)))*coupon + (1 / yield)*(maturity / std::pow(1 + yield, maturity + 1))*coupon
		- (maturity*face_value) / std::pow(1 + yield, maturity + 1);
}


