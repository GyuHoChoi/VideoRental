#include "MovieManager.h"


//*	Construct a new MovieManager
MovieManager::MovieManager()
{
	numOfErrors = 0;
}

//*	Deallocate MovieManager
MovieManager::~MovieManager()
{
	for (auto it : arrType)		delete it;
	for (auto it : arrMovie)	delete it;

	arrType.clear();
	arrMovie.clear();
}

//*	Returns a pointer if the movie is found, NULL otherwise
Movie* MovieManager::getMovie(string movieName)
{
	for (auto it : arrMovie)
	{
		string Title = it->getTitle();

		if (Title.compare(movieName) == 0)
		{
			return it;
		}
	}

	return NULL;
}

Movie* MovieManager::getMovie(int id)
{
	int count = arrMovie.size();

	if (id < 0 || id >= count)		return NULL;
	else 							return arrMovie[id];
}

//*	Creates a new movie and stores
void MovieManager::createMovie(string newMovie)
{
	Movie* p = new Movie(newMovie, NULL);
	arrMovie.push_back(p);
}
void MovieManager::createMovie(string newMovie, int newCode)
{
	MovieType* type = NULL;
	for (auto it : arrType)
	{
		if (newCode == it->getTypeCode())
		{
			type = it;
			break;
		}
	}

	Movie* p = new Movie(newMovie, type);
	arrMovie.push_back(p);
}
void MovieManager::createMovie(string newMovie, string newCode)
{
	MovieType* type = NULL;
	for (auto it : arrType)
	{
		if (newCode.compare(it->getTypeName()) == 0)
		{
			type = it;
			break;
		}
	}

	Movie* p = new Movie(newMovie, type);
	arrMovie.push_back(p);
}

//*	Read in file and create new movies
void MovieManager::processMovies(ifstream& infile)
{
	numOfErrors = 0;
	string line;

	for (;;)
	{
		getline(infile, line);

		if (infile.eof())
		{
			break;
		}

		string  movieCode, movieName, movieAuthor;
		stringstream r(line);

		getline(r, movieCode, ',');
		getline(r, movieName, ',');
		getline(r, movieAuthor, ',');
		
		MovieManager::createMovie(movieName, stoi(movieCode));
	}
}

//*	Creates a new movie type
void MovieManager::createMovieType(string newType, int code)
{
	int errCode = 0;
	for (auto it : arrType)
	{
		if (it->getTypeCode() == code)
		{
			errCode |= 0x01;
		}
		if(it->getTypeName().compare(newType) == 0)
		{
			errCode |= 0x02;
		}

		if (errCode)
			break;
	}

	switch (errCode)
	{
	case 0:
	{
		//	idle
		MovieType* mt = new MovieType(newType, code);
		arrType.push_back(mt);
	}
	break;

	case 1:
	{
		//	error.	duplicate code
		addError("Type code already present.");
	}
	break;

	case 2:
	{
		//	error.	duplicate name
		addError("Type name already present.");
	}
	break;

	case 3:
	{
		//	error.	duplicate code & name
		addError("Both type name and code are duplicates");
	}
	break;
	}
}

//*	Read in file and create new type
void MovieManager::processMovieType(ifstream& infile)
{
	numOfErrors = 0;
	string line;

	for (;;)
	{
		getline(infile, line);

		if (infile.eof())
		{
			break;
		}

		string  typeName;
		int		typeCode;
		stringstream r(line);

		r >> typeName;
		r >> typeCode;
		
		MovieManager::createMovieType(typeName, typeCode);
	}
}


//*	Prints movies in correct order
void MovieManager::display() const
{
	//cout << "------------------------------------VIDEOS------------------------------------" << endl;
	//// Print comedies
	//cout << "-----------------------------------Comedies-----------------------------------" << endl;
	//cout << setw(33) << left << "Title" << setw(1) << right << "Year"
	//	<< setw(20) << left << "Director" << setw(20) << left << "Stock" << endl;
	//
	//comedyTree.displayAll();
	//cout << endl;
	//
	//// Print dramas
	//cout << "------------------------------------Dramas------------------------------------" << endl;
	//cout << setw(33) << left << "Title" << setw(1) << right << "Year"
	//	<< setw(20) << left << "Director" << setw(20) << left << "Stock" << endl;
	//
	//dramaTree.displayAll();
	//cout << endl;
	//
	//// Print classics
	//cout << "-----------------------------------Classics-----------------------------------" << endl;
	//cout << setw(7) << left << "Month" << setw(6) << left << "Year" <<
	//	setw(18) << left << "Actor" << setw(23) << left <<
	//	"Title" << setw(17) << left << "Director" << setw(5) << left << "Stock" << endl;
	//
	//classicTree.displayAll();
	//cout << endl;
}

//*	Prints errors on input
void MovieManager::displayErrors() const
{
	if (!numOfErrors)
		return;

	cout << "----------------------------- Build Errors-----------------------------" << endl;
	cout << "Invalid Lines:" << endl;
	cout << errors << endl;
	cout << endl;
}

//*	Adds a new error
void MovieManager::addError(string error)
{
	numOfErrors++;
	ostringstream temp;
	temp << numOfErrors;

	// Format and add error
	errors += temp.str() + ". ";
	errors += error;
	errors += "\n";
}