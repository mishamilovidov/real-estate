#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Property.h"
#include "Commercial.h"
#include "Residential.h"

using namespace std;

/*
TEST CASE FILE CONTENTS:
testCase1.txt
Commercial 0 1234567 1 0.20 11111 Miami Ave
No Information
Commerical 23343.2 Wrong Way
Residential 0 250000 1 5 Random Road
Commercial 0 1234567 1 0.20 572 Random Road
Residential 1 533000 0 57 Random Road
Residential 23343.2 Wrong Way
Residential 0 250000 1 572 Random Road
I Will Break You
Residential 1 533000 0 123456 Random Road
Commerical 1 132 Way Place

EXPECTED RESULT: 5 invalid lines, 6 valid lines
ACTUAL RESULT: 5 invalid lines, 6 valid lines

testCase2.txt
Residential 0 250000 1 572 Random Road
This shouldn't work
Residential 1 533000 0 123456 Random Road

Commercial 0 1234564 1 0.72 11 BYU Place

EXPECTED RESULT: 2 invalid lines, 3 valid lines
ACTUAL RESULT: 2 invalid lines, 3 valid lines

testCase3.txt
Residential 0 250000 1 572 Random Road
This shouldn't work
Residential 1 533000 0 123456 Random Road

Commercial 0 1234564 1 0.72 11 BYU Place


Residential 0 250000 1 572 Random Road
Why do you do this to me?
Comercial 0 1234564 1 0.72 11 BYU Circle

Commercial 0 1234564 1 0.15 111 BYU Place
HELP ME!!!
Residential 1 1111 0 123456 Random Road

Commercial 0 1234564 1 0.01 11 BYU Avenue

EXPECTED RESULT: 9 invalid lines, 7 valid lines
ACTUAL RESULT: 9 invalid lines, 7 valid lines
*/

//Displays all valid properties from input file
void displayAllProperties(vector<Property*> allProperties)
{
	cout << "\nAll valid properties:" << endl;
	for (int propertyIndex = 0; propertyIndex < allProperties.size(); propertyIndex++)
	{
		cout << allProperties[propertyIndex]->toString();
	}
	cout << endl;
}

//Loads input file and parses data for each valid item; invalid inputs will be displayed at the top of the program
void loadFile(string fileName, vector<Property*> &allProperties)
{
	int ID = 0;

	ifstream inFile;
	inFile.open(fileName.c_str());

	//Check to see if the file opened
	if (!inFile.good()) {
		cout << "File " << fileName << " doesn't exist." << endl << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}

	string line;

	//Read one line, until there are none left.
	while (getline(inFile, line))
	{
		stringstream inLine(line); //Put the line of input that is read into a stringstream.
		string type;
		bool rental;
		int value;
		bool occupied;
		bool discountStatus;
		double discountRate;
		string address;

		//If there is something there, insert the first part into "type" variable
		if (inLine >> type)
		{
			//Do this if the object is Commercial
			if (type == "Residential")
			{
				if (inLine >> rental >> value >> occupied && getline(inLine, address))
				{
					Property* residential = new Residential(rental, value, occupied, address);
					allProperties.push_back(residential);
					//residential->ID = ID;
					//ID++;

				}
				else
				{
					cout << "Ignoring bad RESIDENTIAL in input file: " << inLine.str() << endl;
				}

			}

			//Do this if the object is Commercial
			else if (type == "Commercial")
			{
				if (inLine >> rental >> value >> discountStatus >> discountRate && getline(inLine, address))
				{
					Property* commercial = new Commercial(rental, value, discountStatus, discountRate, address);
					allProperties.push_back(commercial);
					//commercial->ID = ID;
					//ID++;

				}
				else
				{
					cout << "Ignoring bad COMMERCIAL in input file: " << inLine.str() << endl;
				}
			}

			//Do this if the object is not Residential or Commercial
			else
			{
				cout << "Ignoring unknown types of properties appearing in the input file: " << inLine.str() << endl;
			}

		}

		//Do this if there is nothing for "type" variable
		else
		{
			cout << "Ignoring unknown types of properties appearing in the input file: " << inLine.str() << endl;
		}

	}

	inFile.close();
	return;
}

//Prints tax report for each valid property on the input file
void tax_report(vector<Property*> allProperties)
{
	int value;
	double discountRate;
	bool rental;

	cout << "NOW PRINTING TAX REPORT:" << endl;
	for (int i = 0; i < allProperties.size(); i++)
	{
		cout << "** Taxes due for the property at:\t" << allProperties[i]->getAddress() << endl;
		cout << "\tProperty ID: \t\t\t\t\t" << allProperties[i]->getID() << endl;
		cout << "\tThis Property has an estimated value of: \t" << allProperties[i]->getValue() << endl;
		cout << "\tTaxes due on this property are: \t\t" << fixed << setprecision(2) << allProperties[i]->getTax() << endl << endl << endl;
	}
}

int main()
{
	vector<Property*> allProperties;

	string fileName;
	cout << "Enter the file name: ";
	cin >> fileName;

	loadFile(fileName, allProperties);

	displayAllProperties(allProperties);

	tax_report(allProperties);

	system("pause");
	return 0;
}



