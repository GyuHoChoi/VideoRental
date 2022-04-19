#include "Customer.h"
#include <iostream>
#include <iomanip>
#include "sstream"

//*	Construct a new Customer with given ID and name info.
Customer::Customer(const int& newID, const string& newCustomer)
{
	id = newID;
	name = newCustomer;
}

//*	Deallocates Customer
Customer::~Customer()
{
	for (auto it : customerRentals)
	{
		delete it;
	}

	customerRentals.clear();
}

//*	Returns this Customer's ID.
int Customer::getID() const
{
	return id;
}

//*	Returns this Customer's name.
string Customer::getName() const
{
	return name;
}

//*	Returns this Customer's transaction history log.
vector<Rental*> Customer::getCustomerRentals() const
{
	return customerRentals;
}

//*	Set this Customer's ID with the input ID.
void Customer::setID(const int& newID)
{
	id = newID;
}

//*	Set this Customer's name with the input name.
void Customer::setName(const string& newName)
{
	name = newName;
}

//*	adds a Transaction to the Customer's transaction history.
void Customer::addRental(Rental* newTransaction)
{
	customerRentals.push_back(newTransaction);
}

//*	Displays the customer's ID and name.
void Customer::display()
{
	cout << "Customer ID: " << id << "\t" << "Customer Name: " << name << endl;
}

//*	operator==  
bool Customer::operator==(const Customer& other) const
{
	return (id == other.id) && (name == other.name);
}

//*	operator!=  
bool Customer::operator!=(const Customer & other) const
{
	return (id != other.id) || (name != other.name);
}

//*	statement  
//std::string Customer::statement()
//{
//  double totalAmount = 0.;
//  int frequentRenterPoints = 0;
//
//  std::vector< Rental >::iterator iter = customerRentals.begin();
//  std::vector< Rental >::iterator iter_end = customerRentals.end();
//
//  // result will be returned by statement()
//  std::ostringstream result;
//  result << "Rental Record for " << getName() << "\n";
//
//  // Loop over customer's rentals
//  for ( ; iter != iter_end; ++iter ) {
//
//    double thisAmount = 0.;
//    Rental each = *iter;
//
//    // Determine amounts for each rental
//    switch ( each.getMovie().getPriceCode() ) {
//
//      case Movie::REGULAR:
//        thisAmount += 2.;
//        if ( each.getDaysRented() > 2 )
//          thisAmount += ( each.getDaysRented() - 2 ) * 1.5 ;
//        break;
//
//      case Movie::NEW_RELEASE:
//        thisAmount += each.getDaysRented() * 3;
//        break;
//
//      case Movie::CHILDRENS:
//        thisAmount += 1.5;
//        if ( each.getDaysRented() > 3 )
//          thisAmount += ( each.getDaysRented() - 3 ) * 1.5;
//        break;
//    }
//
//    // Add frequent renter points
//    frequentRenterPoints++;
//
//    // Add bonus for a two day new release rental
//    if ( ( each.getMovie().getPriceCode() == Movie::NEW_RELEASE )
//         && each.getDaysRented() > 1 ) frequentRenterPoints++;
//
//    // Show figures for this rental
//    result << "\t" << each.getMovie().getTitle() << "\t"
//           << thisAmount << std::endl;
//    totalAmount += thisAmount;
//  }
//
//  // Add footer lines
//  result << "Amount owed is " << totalAmount << "\n";
//  result << "You earned " << frequentRenterPoints
//         << " frequent renter points";
//
//  return result.str();
//}

std::string Customer::statement(OUTPUT_TYPE type)
{
	// result will be returned by statement()
	ostringstream result;

	if (type == OUTPUT_TYPE::E_OUT_DISPLAY)
	{
		result << "*** Rental Record ***\n";
		result << "CUSTOMER : " << name << "\t\t\t" << "ID : " << id << "\n";
		
		int idx = 0;
		for (auto it : customerRentals)
		{
			const Movie* movie = NULL;
			const MovieType* type = NULL;
		
			movie = it->getMovie();
			type  = movie->getMovieType();
			
			result
				<< std::setw( 3) << std::setfill(' ') << ++idx
				<< std::setw(10) << std::setfill(' ') << type->getTypeCode()
				<< std::setw(20) << std::setfill(' ') << type->getTypeName()
				<< std::setw(30) << std::setfill(' ') << movie->getTitle()
				<< std::setw( 5) << std::setfill(' ') << it->getDaysRented()
				<< endl;
		}
	}
	else if (type == OUTPUT_TYPE::E_OUT_JSON)
	{
		result << "{";
		result <<"\"@name\":\"" << name << "\",";
		result << "\"@ID\":\"" << id << "\",";

		result << "\"array\":{";
		result << "\"@name\":\"Rent\",";
		result << "\"item\":[";
		for (auto it : customerRentals)
		{
			result << "{";

			const Movie* movie = NULL;
			const MovieType* type = NULL;

			movie = it->getMovie();
			type = movie->getMovieType();

			result
				<< "\"TypeCode\":\""	<< type->getTypeCode() << "\","
				<< "\"TypeName\":\""	<< type->getTypeName() << "\","
				<< "\"Title\":\""		<< movie->getTitle  () << "\","
				<< "\"DaysRented\":\""	<< it->getDaysRented() << "\"";

			result << "},";
		}
		result << "]";
		result << "}";
	}
	else if (type == OUTPUT_TYPE::E_OUT_XML)
	{
		result << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << endl;
		result << "<Customer name=\""<< name << "\" ID=\"" << id << "\">" << endl;
		result << "<array name=\"Rent\">" << endl;

		for (auto it : customerRentals)
		{
			result << "<item>"<< endl;

			const Movie* movie = NULL;
			const MovieType* type = NULL;

			movie = it->getMovie();
			type  = movie->getMovieType();

			result << "<TypeCode>"   << type->getTypeCode() << "</TypeCode>"   << endl;
			result << "<TypeName>"   << type->getTypeName() << "</TypeName>"   << endl;
			result << "<Title>"		 << movie->getTitle()   << "</Title>"      << endl;
			result << "<DaysRented>" << it->getDaysRented() << "</DaysRented>" << endl;

			result << "</item>" << endl;
		}

		result << "</array>" << endl;
		result << "</Customer>" << endl;
	}

	return result.str();
}
