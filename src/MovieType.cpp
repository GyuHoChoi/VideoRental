#include "MovieType.h"
#include <iostream>

//*	Construct a new Customer with given ID and name info.
MovieType::MovieType(std::string name, int code)
{
	typeName = name;
	typeCode = code;
}

//*	Deallocates Customer
MovieType::~MovieType()
{
}

//*	Returns type name
std::string MovieType::getTypeName() const
{
	return typeName;
}

//*	Returns price code
int MovieType::getTypeCode() const
{
	return typeCode;
}
