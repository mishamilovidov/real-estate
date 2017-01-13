#pragma once
#include "Property.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Commercial : public Property
{

public:
	//---------------------------------------------------------------------------------------
	/*
	* Constructor/Destructor
	*
	* Handles creation and deletion of Residential Property objects.
	*
	* Parameter: rental
	*		Whether or not it's a rental commercial property
	* Parameter: value
	*		The value of the commercial property
	* Parameter: discountStatus
	*		Whether or not the commercial property gets a tax break
	* Parameter: discountRate
	*		The discount rate for the commercial property
	* Parameter: address
	*		The address of the commercial property
	*/
	Commercial(bool rental, int value, bool discountStatus, double discountRate, string address);
	~Commercial();
	//---------------------------------------------------------------------------------------
	/*
	* getDiscountStatus
	*
	* Returns whether or not the commercial property gets a tax break.
	*
	* Return:
	*		discountStatus
	*/
	bool getDiscountStatus();
	//---------------------------------------------------------------------------------------
	/*
	* getDiscountRate
	*
	* Returns the discount rate for the commercial property.
	*
	* Return:
	*		discountRate
	*/
	double getDiscountRate();
	//---------------------------------------------------------------------------------------
	/*
	* getTax
	*
	* Returns the total taxes for the commercial property based on discountStatus and discountRate.
	*
	* Return:
	*		tax
	*/
	virtual double getTax();
	//---------------------------------------------------------------------------------------
	/*
	* toString
	*
	* Returns a single string containing useful information about the commercial property.
	*
	* Return:
	*		A data string about this property
	*/
	virtual string toString();

protected:
	bool discountStatus;
	double discountRate;
};
