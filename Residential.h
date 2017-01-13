#pragma once
#include "Property.h"
#include <string>
#include <sstream>


using namespace std;

class Residential : public Property
{

public:
	//---------------------------------------------------------------------------------------
	/*
	* Constructor/Destructor
	*
	* Handles creation and deletion of Residential Property objects.
	*
	* Parameter: rental
	*		Whether or not it's a rental residential property
	* Parameter: value
	*		The value of the residential property
	* Parameter: occupied
	*		Whether or not the property is occupied
	* Parameter: address
	*		The address of the property
	*/
	Residential(bool rental, int value, bool occupied, string address);
	~Residential();
	//---------------------------------------------------------------------------------------
	/*
	* getOccupied
	*
	* Returns whether or not residential property is occupied.
	*
	* Return:
	*		occupied
	*/
	bool getOccupied();
	//---------------------------------------------------------------------------------------
	/*
	* getTax
	*
	* Returns the amount of taxes to be paid.
	*
	* Return:
	*		The amount of tax
	*/
	virtual double getTax();
	//---------------------------------------------------------------------------------------
	/*
	* toString
	*
	* Returns a single string containing useful information about the residential property.
	*
	* Return:
	*		A data string about this property
	*/
	virtual string toString();

protected:
	bool occupied;

};
