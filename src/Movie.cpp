#include "Movie.h"

//*	Construct a new Customer with given ID and name info.
Movie::Movie()
{
	movieTitle = "";
	movieType  = NULL;
}
Movie::Movie(string title, MovieType* type) : movieTitle(title), movieType(type)
{
}

//*	Deallocates Customer
Movie::~Movie()
{
}

//*	Returns the movie type
MovieType* Movie::getMovieType() const
{ 
	return movieType;
}

void Movie::setMovieType(MovieType* type)
{ 
	movieType = type;
}

//*	Returns the video title
string Movie::getTitle()  const
{ 
	return movieTitle; 
}

void Movie::setTitle(string title)
{
	movieTitle = title;
}

