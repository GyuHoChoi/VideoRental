#ifndef STORE_H
#define STORE_H

#include "CustomerManager.h"
#include "MovieManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


class Store
{
public:
	Store();												//	constructor
	~Store();												//	destructor

	void initialize();										//	initialize
	void buildMovieTypeList(ifstream& infile);				//	build new movie type list
	void buildMovieList(ifstream& infile);					//	build new movie list
	void buildCustomerList(ifstream& infile);				//	build new customer list

	void rental(string customer, string title, int days);	//	rental
	void addCustomer(int id, string cusotmer);				//	add new customer 
	void addType(string type, int code);					//	add new type
	void addMovie(string movie, string type);				//	add new movie

	void statement(string customer, OUTPUT_TYPE type);		//	print recorded user information 

private:
	CustomerManager customerManager;						//	manage customers
	MovieManager movieManager;								//	manage inventory
};
#endif