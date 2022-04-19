#include "CustomerManager.h"

//*	Construct a new CustomerManager
CustomerManager::CustomerManager()
{
}

//*	Deallocates CustomerManager
CustomerManager::~CustomerManager()
{
}

//*	Creates a new Customer and stores it in the HashTable
void CustomerManager::createCustomer(string line)
{
	int id; 
	string newCustomer;

	stringstream customerDetails(line);
	customerDetails >> id >> newCustomer;

	Customer* customer = new Customer(id, newCustomer);
	customerList.put(customer, id);
}
void CustomerManager::createCustomer(int id, string name)
{
	Customer* customer = new Customer(id, name);
	customerList.put(customer, id);
}

//*	Returns a pointer to a customer if found, NULL if not
Customer* CustomerManager::getCustomer(const int &id)
{
	return customerList.get(id);
}
Customer* CustomerManager::getCustomer(const string& name)
{
	return customerList.get(name);
}

//*	Builds the customer list from a file
void CustomerManager::processCustomers(ifstream &infile)
{
	string line;
	while(getline(infile, line))
	{
		createCustomer(line);
	}
}

//*	displays a list of all customers in the customer list
void CustomerManager::display()
{
	customerList.display();
}