
#include "HashTable.h"

//*	Construct a new HashTable and initializes each index to NULL
HashTable::HashTable()
{
	for(int i = 0; i < TABLESIZE; i++)
	{
		customerTable[i] = NULL;
	}
}

//*	Deallocates HashTable, deleting each node and customer data
HashTable::~HashTable()
{
	for(int i = 0; i < TABLESIZE; i++)
	{
		Node* current = customerTable[i];
		while(current != NULL)
		{
			Node* toDelete = current;
			current = current->next;

			delete toDelete->data;
			delete toDelete;
			toDelete = NULL;
		}
	}
}

//*	inserts a customer into the HashTable
void HashTable::put(Customer* newCustomer, const int &id)
{
	// finds index
	int insertionIndex = id % TABLESIZE;

	Node* newNode = new Node;
	newNode->data = newCustomer;
	
	if(customerTable[insertionIndex] == NULL || 
		(customerTable[insertionIndex]->data->getID() > newNode->data->getID()))
	{
		newNode->next = customerTable[insertionIndex];
		customerTable[insertionIndex] = newNode;
	}
	else
	{
		Node* current = customerTable[insertionIndex];
		while(current->next != NULL && (current->next->data->getID() < newNode->data->getID()))
		{
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
}

//*	Returns a pointer to a customer in the HashTable
Customer* HashTable::get(const int &id)
{
	int getIndex = id % TABLESIZE;
	Node* current = customerTable[getIndex];
	while(current != NULL)
	{
		if(current->data->getID() == id)
		{
			return current->data;
		}
		current = current->next;
	}
	return NULL;
}
Customer* HashTable::get(const string& name)
{
	for (int i = 0; i < TABLESIZE; i++)
	{
		Node* current = customerTable[i];
		while (current != NULL)
		{
			if (current->data->getName().compare(name) == 0)
			{
				return current->data;
			}
			current = current->next;
		}
	}
	
	return NULL;
}

//*	displays all customers in the HashTable
void HashTable::display()
{
	for(int i = 0; i < TABLESIZE; i++)
	{
		Node* current = customerTable[i];
		while(current != NULL)
		{
			current->data->display();
			current = current->next;
		}
	}
}