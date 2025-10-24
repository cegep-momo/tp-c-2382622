#include "book.h"

using namespace std;

// Constructor
Book::Book(const string& title, const string& author, const string& isbn) 
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerName("") {}