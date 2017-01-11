#pragma once
#include <string>
#include <sstream>
#include "Commercial.h"
#include "Property.h"

using namespace std;

Commercial::Commercial(bool rental, int value, bool discountStatusInput, double discountRateInput, string address) :Property(rental, value, address)
{
	discountStatus = discountStatusInput;
	discountRate = discountRateInput;
}
//-----------------------------------------------------------------------------------------------------------------------
Commercial::~Commercial() {}
//-----------------------------------------------------------------------------------------------------------------------
bool Commercial::getDiscountStatus()
{
	return discountStatus;
}
//-----------------------------------------------------------------------------------------------------------------------
double Commercial::getDiscountRate()
{
	return discountRate;
}
//-----------------------------------------------------------------------------------------------------------------------
double Commercial::getTax()
{
	double taxRate;

	if (rental)
	{
		taxRate = 0.012;
	}
	else
	{
		taxRate = 0.01;
	}
	if (discountStatus)
	{
		tax = (value * (1.00 - discountRate)) * taxRate;
	}
	else
	{
		tax = value * taxRate;
	}
	return tax;
}
//-----------------------------------------------------------------------------------------------------------------------
string Commercial::toString()
{
	string RENTAL;
	if (rental == 1)
	{
		RENTAL = "Rental";
	}
	else
	{
		RENTAL = "NOT Rental";
	}

	string DISCOUNT_STATUS;
	if (discountStatus == 1)
	{
		DISCOUNT_STATUS = "Discounted";
	}
	else
	{
		DISCOUNT_STATUS = "NOT Discounted";
	}

	if (DISCOUNT_STATUS == "Discounted")
	{
		stringstream ss;
		ss << "Property ID: " << ID << " " << "Address:" << address << " " << RENTAL << " " << "Estimated Value: " << value << " " << DISCOUNT_STATUS << " " << "Discount: " << discountRate << endl;
		return ss.str();
	}
	else
	{
		stringstream ss;
		ss << "Property ID: " << ID << " " << "Address:" << address << " " << RENTAL << " " << "Estimated Value: " << value << " " << DISCOUNT_STATUS << endl;
		return ss.str();
	}
}
