
#ifndef MOVIEMANAGER_H
#define MOVIEMANAGER_H

#include "Movie.h"
#include "MovieType.h"
#include <fstream>
#include <iostream>
#include <sstream>

class MovieManager
{

public:
	MovieManager();										// constructor
	~MovieManager();									// destructor

	Movie* getMovie(string movieName);					// find a movie
	Movie* getMovie(int id );							// find a movie


	void createMovie(string newMovie);					// create new movie
	void createMovie(string newMovie, int newCode);		// create new movie
	void createMovie(string newMovie, string newCode);	// create new movie
	void processMovies(ifstream& infile);				// process input file

	void createMovieType(string newType, int code);		// create new movie type
	void processMovieType(ifstream& infile);			// process input file

	void display() const;								// display all movies
	void displayErrors() const;							// display errors on input

private:
	void addError(string);								// add a new error
	string errors;										// holds input errors
	int numOfErrors;									// number of errors logged

	vector<Movie*>	arrMovie;							// movies list
	vector<MovieType*> arrType;							// movie type list
	
};
#endif