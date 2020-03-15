//
// Created by Benjamin on 3/7/2020.
//

#include "Store.h"

Store::Store()
{
    for (int i = 0; i < hashSize; i++)
    {
        customers[i] = NULL;
    }
    movies = new BSTree;
    genreTypes.push_back('F');
    genreTypes.push_back('D');
    genreTypes.push_back('C');
}

/*
 * precondition: have a correctly formatted text file
 * containing a list of movies of varying genres.
 * postcondition: adds all movies from a given text file
 * to the binary search tree, and sorts them based on the
 * given sorting criteria.
 */
void Store::buildMovie(ifstream &movieFile) {
    string line;
    while(!movieFile.eof()) {
        char genre;
        char comma;
        int stock;
        movieFile >> genre;
        if(!isValidGenre(genre)) { // in case of invalid genre
            getline(movieFile, line); // skip to next line
            continue;
        }
        movieFile >> comma;
        movieFile >> stock;
        movieFile >> comma;
        getline(movieFile, line);
        int commaIndex = line.find(',');
        string director = line.substr(1, commaIndex-1);
        line = line.erase(0, commaIndex + 1);
        commaIndex = line.find(',');
        string title = line.substr(1, commaIndex-1);
        line = line.erase(0, commaIndex + 2);
        int releaseYear;
        if(genre == 'F' || genre == 'D') {
            releaseYear = stoi(line);
            if(genre == 'F') { // movie is of Comedy genre
                Movie* film = new Comedy(genre, stock, director, title, releaseYear);
                movies->insert(film);
            }
            else { // movie is of Drama genre
                Movie* film = new Drama(genre, stock, director, title, releaseYear);
                movies->insert(film);
            }
        }
        else { // movie is of Classic genre
            int spaceIndex = line.find(' ');
            string firstName = line.substr(0, spaceIndex);
            line = line.erase(0, spaceIndex + 1);
            spaceIndex = line.find(' ');
            string lastName = line.substr(0, spaceIndex);
            line = line.erase(0, spaceIndex + 1);
            int month = stoi(line);
            spaceIndex = line.find(' ');
            line = line.erase(0, spaceIndex + 1);
            releaseYear = stoi(line);
            Movie* film = new Classic(genre, stock, director, title, releaseYear, firstName, lastName, month);
            movies->insert(film);
        }
    }
}

/*
 * precondtion: have read a char from a correctly formatted
 * text file.
 * returns true if the char passed in is a valid genre type
 * by checking if it's in the genreTypes vector.
 */
bool Store::isValidGenre(char genre) const
{
    for (int i = 0; i < genreTypes.size(); i++)
    {
        if (genre == genreTypes[i])
        {
            return true; // genre is valid
        }
    }
    return false;
}

/*
 * this method adds a char to the genreTypes vector,
 * to indicate that this is a valid genre to read from
 * a text file.
 */
void Store::addGenre(char genre)
{
    genreTypes.push_back(genre);
}

void Store::displayInventory() const
{
    movies->display();
}

//Attempts to add a customer to the hash table, returns true if successful.
bool Store::addCustomer(Customer *patron)
{
    int key = patron->getID() % hashSize;
    while (true)
    {
        if (customers[key] == NULL)
        {
            customers[key] = patron; //inserts the customer
            return true;
        }
        else if (customers[key]->getID() == patron->getID())
        {
            cout << "Error: customer with " << patron->getID() << " already exists." << endl;
            return false; //if there is already a customer with that given ID
        }
        else
        {
            key++; //increments the key to check the next spot for insertion, linear probing.
        }
    }
}

//"returns" a customer via the pointer passed into it. Uses linear probing.
bool Store::getCustomer(int customerID, Customer *&patron) const
{
    int key = customerID % hashSize;
    while (true)
    {
        if (customers[key] == NULL)
        {
            cout << "Customer with ID: " << customerID << " not found." << endl;
            return false;
        }
        if (customers[key]->getID() == customerID)
        {
            patron = customers[key];
            return true;
        }
        key++; //if not found, iterate up. linear probing.
    }
}

// Preconditions: The customer file is formatted properly, each line containing a four digit integer, followed by two
// strings, each separated by a space.
// Postconditions: The customer hash table has been properly constructed.
void Store::buildCustomer(istream &customerFile)
{
    while (!customerFile.eof())
    {
        int id;
        customerFile >> id;
        string lname;
        customerFile >> lname;
        string fname;
        customerFile >> fname;
        if (!(fname.empty() || lname.empty()))
        {
            addCustomer(new Customer(id, lname, fname));
        }
    }
}

// Preconditions: the transaction file contains properly formatted data, though potentially incorrect data, such as a
// command character that does not exist, an invalid customer ID, etc.
// Postconditions: all transactions have been properly handled, either executed if valid, or error output provided.
void Store::processTrans(istream &transFile)
{
    string transactionLine;
    while (!transFile.eof())
    {
        getline(transFile, transactionLine);
        if (transactionLine.empty())
        {
            return;
        }
        char transChar = transactionLine.at(0);
        cout << "--" << transactionLine << endl; //todo remove
        if (transChar == 'I')
        {
            Inventory inv = Inventory('I');
            inv.doTrans(*this);
        }
        else if (transChar == 'H')
        {
            int customerID;
            customerID = atoi(transactionLine.substr(2, 5).c_str());
            History hist = History('H', customerID);
            Customer *customer = NULL;
            if (getCustomer(customerID, customer))
            {
                hist.doTrans(customer);
            }
        }
        else if (transChar == 'B' || transChar == 'R')
        {

            int customerID = atoi(transactionLine.substr(2, 5).c_str());
            char genre = transactionLine.at(9);
            char mediaType = transactionLine.at(7);
            string movieData = transactionLine.substr(11); //will be in varying forms dependent on genre.
            if(mediaType != 'D')
            {
                cout << mediaType << " is an invalid media type, only DVDs, denoted as D." << endl;
                continue;
            }
            if(!isValidGenre(genre))
            {
                cout << genre << " is not a valid genre" << endl;
                continue; //invalid genre, move onto the next line
            }

            Movie *m = makeMovie(genre, movieData);

            if (!movies->search(m))
            {
                cout << "Unable to find movie: " << transactionLine.substr(7) << endl;
                continue; //if not found, skip this line after outputing error
            }

            Customer *c = NULL;
            if (getCustomer(customerID, c)) //make sure the customer is valid, getCustomer outputs error if not found.
            {

                if (transChar == 'B')
                {
                    if(m->getStock() <= 0)
                    {
                        if(m->getGenre() == 'C')
                        {
                            const Classic* classic = static_cast<const Classic* >(m);
                            movies->checkAlternative(classic);
                            continue;
                        }
                        cout << m->getTitle() << " is out of stock, sorry!" << endl;
                        continue;
                    }
                    c->addTrans(transactionLine);
                    Borrow borrow = Borrow(transChar, customerID, m);
                    borrow.doTrans(m);
                }
                else
                {
                    if(!c->hasBorrowedMovie(transactionLine))
                    {
                        cout << "The customer with the ID: " << c->getID() << " has not borrowed that movie!" << endl;
                    }
                    c->addTrans(transactionLine);
                    Return ret = Return(transChar, customerID, m);
                    ret.doTrans(m);
                }

            }
        }
        else
        {
            cout << "Invalid command character: " << transChar << endl;
        }
    }
}

//Creates temporary movies for the purpose of retrieving real movies from the movies BST.
//Takes an input of a genre, movie data (a cluster of information to be processed differently depending on movie type
//and a movie ptr, which will be used to find a movie in the movie BST. It assumes a four digit year.
Movie *Store::makeMovie(char genre, string movieData)
{
    if(genre == 'F') //comedy (F for funny)
    {
        //F uses title, year : "National Lampoon's Animal House, 1978"
        int commaIndex = movieData.find_first_of(',');
        string title = movieData.substr(0, commaIndex);
        string year = movieData.substr(commaIndex + 2);
        Movie *movie = new Comedy(genre, 0,"defaultDirector",title,atoi(year.c_str()));
        return movie;
    }
    else if(genre == 'D') //drama
    {
        //D uses director, title : "Steven Spielberg, Schindler's List,"
        int commaIndex = movieData.find_first_of(',');
        int lastComma = movieData.find_last_of(',');
        string director = movieData.substr(0, commaIndex);
        string title = movieData.substr(commaIndex+2, movieData.length()- (director.length() + 3));
        Movie *movie = new Drama(genre, 0, director, title, 0000);
        return movie;
    }
    else if(genre == 'C') //classic
    {
        //C uses release date, major actor : "3 1971 Ruth Gordon"
        int firstSpace = movieData.find_first_of(' ');
        int centerSpaceIndex = firstSpace + 5; //format: month (1-2 chars), space, year (4 digits)
        int lastSpaceIndex = movieData.find_last_of(' ');
        string releaseMonth = movieData.substr(0, firstSpace);
        string releaseYear = movieData.substr(firstSpace+1, centerSpaceIndex-firstSpace-1);
        string actorFname = movieData.substr(centerSpaceIndex+1, lastSpaceIndex-centerSpaceIndex-1);
        string actorLname = movieData.substr(lastSpaceIndex+1, movieData.length()-lastSpaceIndex-1);
        Movie *movie = new Classic(genre,0,"default director","defaultTitle",atoi(releaseYear.c_str()),
                actorFname,actorLname,atoi(releaseMonth.c_str()));
        return movie;
    }
    else
    {
        cout << "Internal error: genre passed initial check in transaction processing when it shouldn't have" << endl;
        return NULL;
    }
}