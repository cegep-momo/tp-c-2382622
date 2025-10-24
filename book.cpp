#include "book.h"
#include <istream>
#include <iostream>


using namespace std;

// Constructor - livre disonible sans emprunteur

Book::Book()
    : title(""), author(""), isbn(""), isAvailable(true), borrowerName("") {}
Book::Book(const string& title, const string& author, const string& isbn) 
    : title(title), author(author), isbn(isbn), isAvailable(true), borrowerName("") {}



// --- Getters ---

// Retourne le titre du livre
string Book::getTitle() const { return title; }

// Retourne le nom de l’auteur
string Book::getAuthor() const { return author; }

// Retourne SBN du livre
string Book::getISBN() const { return isbn; }

// Indique si le livre est disponible (true = disponible, false = emprunté)
bool Book::getAvailability() const { return isAvailable; }

// Retourne le nom de l’emprunteur actuel (vide si disponible)
string Book::getBorrowerName() const { return borrowerName; }

// --- Setters ---

// Modifie le titre du livre
void Book::setTitle(const string& _title) { title = _title; }

// Modifie l’auteur du livre
void Book::setAuthor(const string& _author) { author = _author; }

// Modifie ISBN
void Book::setISBN(const string& _isbn) { isbn = _isbn; }

// Modifie la disponibilité du livre  - disponible = pas d’emprunteur
void Book::setAvailability(bool _available) { 
    isAvailable = _available; 
    if (_available) borrowerName.clear();
}

// Définit le nom de l’emprunteur - empreunteur =  livre non disponible
void Book::setBorrowerName(const string& name) { 
    borrowerName = name; 
    if (!name.empty()) isAvailable = false;
}

// --- Methods ---


// Emprunter le livre - définit le nom de l’emprunteur, livre non disponible
void Book::checkOut(const string& borrower) {
    if (!borrower.empty()) {
        borrowerName = borrower;
        isAvailable = false;
    }
}
   
// Retourner le livre - emprenteur vide, livre disponible
void Book::returnBook() {
    borrowerName.clear();
    isAvailable = true;
}

// Représentation textuelle du livre
string Book::toString() const {
    string status = isAvailable ? "Disponible" : "Emprunté par " + borrowerName;
    return "Titre: " + title + "\nAuteur: " + author + "\nISBN: " + isbn + "\nStatut: " + status;
}

// Format pour sauvegarde dans fichier
string Book::toFileFormat() const {
    return title + "|" + author + "|" + isbn + "|" + (isAvailable ? "1" : "0") + "|" + borrowerName;
}

// Afficher une ligne 
void Book::fromFileFormat(const string& line) { 
    cout << line << endl;
}


    