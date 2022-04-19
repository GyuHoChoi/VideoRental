
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "Rental.h"

class Rental;

enum class OUTPUT_TYPE
{
	E_OUT_DISPLAY,
	E_OUT_XML,
	E_OUT_JSON,
};

using namespace std;

class Customer 
{

public:
	Customer(const int& newID, const string& newCustomer);				//	constructor
	~Customer();														//	destructor

	int getID() const;													//	get Customer ID
	string getName() const;												//	get Customer name
	vector<Rental*> getCustomerRentals() const;							//	get Customer rental history

	void setID(const int& newID);										//	set customer ID
	void setName(const string& newName);								//	set customer name
	void addRental(Rental* newRental);									//	add transaction to customer transaction history

	void display();														//	display customer information
	string statement(OUTPUT_TYPE type);									//	generate a statement for the customer

	bool operator==(const Customer& other) const;						//	== operator
	bool operator!=(const Customer& other) const;						//	!= operator

private:
	vector<Rental*> customerRentals;									// customer rental history
	int id;
	string name;
};
#endif
