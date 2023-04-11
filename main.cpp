#include <iostream>
#include "Library.h"
#include "Book.h"
#include "Patron.h"
using namespace std;

int main() {
    Library library;

    int option;
    string name, address, phoneNumber;
    string bookTitle;
    int numPages, sizeCharacters, charsPerPage, durationSeconds;
    int dueMonth, dueDay, dueYear;
    Book *aBook;
    Patron *aPatron = new Patron();

    bool exit = false;
    do{
        cout << "---------------------------------\n"
                " Main Menu\n"
                "------------------------------\n"
                "1) Add Patron\n"
                "2) Add Book\n"
                "3) Search for Patron\n"
                "4) Search for Book\n"
                "5) Check Out Book\n"
                "6) Return Book\n"
                " 99) EXIT\n"
                "------------------------------" << endl;

        cin >> option;

        switch (option) {
            case 1:
                // Add Patron
                cin.ignore();
                cout << "Enter the patron's name: ";
                getline(cin, name);

                cout << "Enter the patron's address: ";
                getline(cin, address);

                cout << "Enter the patron's phone number: ";
                getline(cin, phoneNumber);

                // Catch exception if patron was already added
                try{
                    library.addPatron(name, address, phoneNumber);
                }
                catch(DuplicatePatronException& e){
                    cout << e.what() << endl;
                }
                break;
            case 2:
                // Add Book
                int subOption;
                bool invalid;
                do {
                    invalid = false;
                    cout << "---------------------------------\n"
                            " Sub Menu\n"
                            "------------------------------\n"
                            "1) Add Printed Book\n"
                            "2) Add EBook\n"
                            "3) Add Audio Book\n"
                            "------------------------------" << endl;
                    cin >> subOption;

                    cin.ignore();
                    switch(subOption){
                        case 1:
                            // Printed Book
                            cout << "Enter the book's title: ";
                            getline(cin, bookTitle);

                            cout << "Enter the number of pages in the book: ";
                            cin >> numPages;

                            // Catch exception if book was already added
                            try{
                                library.addPrintedBook(bookTitle, numPages);
                            }
                            catch(DuplicateBookException& e){
                                cout << e.what() << endl;
                            }
                            break;
                        case 2:
                            // EBook
                            cout << "Enter the book's title: ";
                            getline(cin, bookTitle);

                            cout << "Enter the character size: ";
                            cin >> sizeCharacters;

                            cout << "Enter the number of characters per page: ";
                            cin >> charsPerPage;

                            // Catch exception if book was already added
                            try{
                                library.addEBook(bookTitle, sizeCharacters, charsPerPage);
                            }
                            catch(DuplicateBookException& e){
                                cout << e.what() << endl;
                            }

                            break;
                        case 3:
                            // Audio Book
                            cout << "Enter the book's title: ";
                            getline(cin, bookTitle);

                            cout << "Enter the duration in seconds: ";
                            cin >> durationSeconds;

                            // Catch exception if book was already added
                            try{
                                library.addAudioBook(bookTitle, durationSeconds);
                            }
                            catch(DuplicateBookException& e){
                                cout << e.what() << endl;
                            }

                            break;
                        default:
                            cout << "Invalid option, please chose one of the options listed" << endl;
                            invalid = true;
                            break;
                    }

                } while (invalid == true);

                break;

            case 3:
                // Search for Patron
                cin.ignore();
                cout << "Enter the patron's name: ";
                getline(cin, name);

                aPatron = library.searchPatron(name);
                if (aPatron != nullptr){
                    cout << "Name: " << aPatron->getName() << endl;
                    cout << "Address: " << aPatron->getAddress() << endl;
                    cout << "Phone number: " << aPatron->getPhoneNumber() << endl;
                }
                else{
                    cout << "That patron is not in the system" << endl;
                }
                break;

            case 4:
                // Search for Book
                cin.ignore();
                cout << "Enter the book's title: ";
                getline(cin, bookTitle);

                aBook = library.searchBook(bookTitle);
                if (aBook != nullptr){
                    cout << aBook->toString() << endl;
                }
                else{
                    cout << "That book is not in the system" << endl;
                }
                break;

            case 5:
                // Check Out Book
                cin.ignore();
                cout << "Enter the book's title: ";
                getline(cin, bookTitle);
                aBook = library.searchBook(bookTitle);
                if (aBook == nullptr){
                    cout << "That book is not in the system" << endl;
                    break;
                }

                cout << "Enter the patron's name: ";
                getline(cin, name);
                aPatron = library.searchPatron(name);
                if (aPatron == nullptr){
                    cout << "That patron is not in the system" << endl;
                    break;
                }

                cout << "Enter the year the book is due: ";
                cin >> dueYear;
                cout << "Enter the month the book is due: ";
                cin >> dueMonth;
                cout << "Enter the day the book is due: ";
                cin >> dueDay;

                // Catch exception if book was already checked out
                try{
                    library.checkOutBook(aBook, aPatron, dueYear, dueMonth, dueDay);
                }
                catch(CheckOutBookException& e){
                    cout << e.what() << endl;
                }

                break;

            case 6:
                // Return Book
                cin.ignore();
                cout << "Enter the book's title: ";
                getline(cin, bookTitle);
                aBook = library.searchBook(bookTitle);
                if (aBook == nullptr){
                    cout << "That book is not in the system" << endl;
                    break;
                }

                cout << "Enter the patron's name: ";
                getline(cin, name);
                aPatron = library.searchPatron(name);
                if (aPatron == nullptr){
                    cout << "That patron is not in the system" << endl;
                    break;
                }


                // Catch exception if book wasn't checked out or the book and patron don't match the loan
                try{
                    library.returnBook(aBook, aPatron);
                }
                catch(ReturnLoanException& e){
                    cout << e.what() << endl;
                }
                catch(ReturnMismatchException& e){
                    cout << e.what() << endl;
                }

                break;

            case 99:
                // EXIT
                cout << "Are you sure you want to exit? (y/n): ";
                char answer;
                cin >> answer;
                answer = toupper(answer);
                if (answer == 'Y'){
                    exit = true;
                }
                break;

            default:
                cout << "Invalid option, please chose one of the numbers listed" << endl;
                break;

        }

    } while(!exit);



    return 0;
}