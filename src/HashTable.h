
#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Customer.h"

const int TABLESIZE = 100;

class HashTable
{

public:
	HashTable();														// constructor	
	~HashTable();														// destructor

	void put(Customer* newCustomer, const int &id);						// insert a customer
	Customer* get(const int &id);										// retrieve a customer
	Customer* get(const string& name);

	void display();														// display customer list

private:
	struct Node															// Nodes for linked list
	{
		Node* next;														// pointer to next Node
		Customer* data;													// customer data
	};
	
	Node* customerTable[TABLESIZE];										// HashTable (separate chaining)
};
#endif
