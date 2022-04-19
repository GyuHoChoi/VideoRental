#ifndef MOVIETYPE_H
#define MOVIETYPE_H

#include <string>

class MovieType
{
public:
	MovieType(std::string name, int code);			//	constructor
	~MovieType();									//	destructor

	std::string getTypeName() const;				//	get type name
	int getTypeCode() const;						//	get type code

private:
	std::string typeName;
	int typeCode;
};
#endif
