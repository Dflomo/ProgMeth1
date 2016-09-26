/*************************************
 * Derek Florimonte
 * 909422688
 * dflomo@gmail.com
 * Cygwin g++ (4.8.3)
 *************************************/
#include "residential.h"

//Constructor
Residential:: Residential(){
	capacity = 1;
	taxRevenue = 0;
};

//Destructor
Residential:: ~Residential(){
	
};

//Tick updates the taxRevenue determined by the capacity
void Residential:: tick(){
	taxRevenue = capacity *.1;
};

//CollectTaxes returns the revenue collected, and resets it
double Residential:: collectTaxes(){
	double tempTax = taxRevenue;
	taxRevenue = 0;
	return tempTax;
};

