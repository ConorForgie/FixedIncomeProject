#pragma once

class Bond
{
public:
	Bond(double yield_, double coupon_, double face_value_, double maturity_);
	double PriceFromYield(double new_yield);
	double NetPresentValue();
	double DV01();
private:
	double yield, coupon, face_value, maturity;

};

