
#ifndef CUSTOMERMANAGER_H
#define CUSTOMERMANAGER_H

#include "HashTable.h"
#include "Customer.h"
#include "Rental.h"
#include <fstream>
#include <sstream>

class CustomerManager
{

public:
	CustomerManager();									// constructor
	~CustomerManager();									// destructor

	void createCustomer(string line);					// create new Customer
	void createCustomer(int id, string name);			// create new Customer

	Customer* getCustomer(const int& id);				// find a Customer
	Customer* getCustomer(const string& name);				// find a Customer

	void processCustomers(ifstream& infile);			// build customer list
	void display();										// display customer list

private:
	HashTable customerList;								// HashTable to store customers
};
#endif