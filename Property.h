#pragma once
#include <string>
#include <sstream>

using namespace std;

class Property
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
	* Parameter: address
	*		The address of the property
	*/
	Property(bool rental, int value, string address);
	~Property();
	//---------------------------------------------------------------------------------------
	/*
	* getAddress
	*
	* Returns address of property.
	*
	* Return:
	*		address
	*/
	string getAddress();
	//---------------------------------------------------------------------------------------
	/*
	* getValue
	*
	* Returns value of property.
	*
	* Return:
	*		value
	*/
	int getValue();
	//---------------------------------------------------------------------------------------
	/*
	* getRental
	*
	* Returns whether or not property is residential.
	*
	* Return:
	*		rental
	*/
	bool getRental();
	//---------------------------------------------------------------------------------------
	/*
	* getTax
	*
	* Returns tax for property.
	*
	* Return:
	*		tax
	*/
	virtual double getTax() = 0; //this is a pure virtual
	//---------------------------------------------------------------------------------------
	/*
	* getID
	*
	* Returns assigned ID for property in list.
	*
	* Return:
	*		ID
	*/
	int getID() const;
	//---------------------------------------------------------------------------------------
	/*
	* toString
	*
	* Returns a single string containing useful information about the property.
	*
	* Return:
	*		A data string about this property
	*/
	virtual string toString() = 0; //this is a pure virtual

protected:
	int ID = 0;
	static int count;
	bool rental;
	int value;
	string address;
	double tax;
};
