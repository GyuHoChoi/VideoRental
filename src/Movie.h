#ifndef MOVIE_H
#define MOVIE_H

#include "MovieType.h"
#include <string>
#include <vector>
#include <tuple>

class MovieType;

using namespace std;

class Movie 
{
public:
	Movie();										//	constructor
	Movie(string title, MovieType* type);			//	constructor
	~Movie();										//	destructor

	MovieType* getMovieType() const;				//	get movie type
	void setMovieType(MovieType* type);				//	set movie type
	
	string getTitle() const;						//	get title
	void setTitle(string title);					//	set title

private:
	MovieType* movieType;
	string movieTitle;
};
#endif // MOVIE_H
