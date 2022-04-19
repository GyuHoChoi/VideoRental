#include "Store.h"

//*	Constructs a new Store
Store::Store()
{
}

//*	Deallocate store
Store::~Store()
{
}

//*	Initialize object
void Store::initialize()
{
	//	Retrieves information stored in a data file.
	//	load movie information
	ifstream movieType("dataTypes.txt");
	buildMovieTypeList(movieType);

	ifstream movies("dataMovies.txt");
	buildMovieList(movies);
	
	//	load customer information
	ifstream customer("dataCustomers.txt");
	buildCustomerList(customer);
}

//*	 build movie type list
void Store::buildMovieTypeList(ifstream& infile)
{
	//	load movie type information
	movieManager.processMovieType(infile);
	//movieManager.display(); 

	movieManager.displayErrors();
}

//*	 build movie list
void Store::buildMovieList(ifstream &infile)
{
	//	load movie type information
	movieManager.processMovies(infile);
	//movieManager.display(); 

	movieManager.displayErrors();
}

//*	build customer list
void Store::buildCustomerList(ifstream &infile)
{
	customerManager.processCustomers(infile);
	//customerManager.display();
}

//*	rental 
void Store::rental(string customer, string title, int days)
{
	Movie* movie = movieManager.getMovie(title);
	Rental* rent = new Rental(movie, days);

	customerManager.getCustomer(customer)->addRental(rent);
}

//*	add new customer
void Store::addCustomer(int id, string customer)
{
	customerManager.createCustomer(id, customer);
	//customerManager.display();
}

//*	add new type
void Store::addType(string type, int code)
{
	movieManager.createMovieType(type, code);
	//movieManager.display(); 
}


//*	add new movie
void Store::addMovie(string movie, string type)
{
	movieManager.createMovie(movie, type);
	//movieManager.display(); 
}

//*	display history
void Store::statement(string customer, OUTPUT_TYPE type)
{
	string state = customerManager.getCustomer(customer)->statement(type);

	if (type == OUTPUT_TYPE::E_OUT_DISPLAY)
	{
		cout << state << endl;
	}
	else
	{
		string filePath, ext;
		switch (type)
		{
		case OUTPUT_TYPE::E_OUT_JSON: ext = ".json";	break;
		case OUTPUT_TYPE::E_OUT_XML : ext = ".xml";		break;
		}

		filePath = "./" + customer + ext;

		// write File
		ofstream writeFile(filePath.data());
		if (writeFile.is_open())
		{
			writeFile << state;
			writeFile.close();
		}
	}
}


//#include <fstream>
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	string filePath = "test.txt";
//
//	// write File
//	ofstream writeFile(filePath.data());
//	if (writeFile.is_open()) {
//		writeFile << "Hello World!\n";
//		writeFile << "This is C++ File Contents.\n";
//		writeFile.close();
//	}
//
//	// read File
//	ifstream openFile(filePath.data());
//	if (openFile.is_open()) {
//		string line;
//		while (getline(openFile, line)) {
//			cout << line << endl;
//		}
//		openFile.close();
//	}
//
//	return 0;
//}