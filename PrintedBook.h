//
// Created by Owner on 12/10/2022.
//

#ifndef HWK7_PRINTEDBOOK_H
#define HWK7_PRINTEDBOOK_H

#include "Book.h"

class PrintedBook: public Book {
public:
    PrintedBook(string aTitle, int numPages);
    ~PrintedBook();
    string getBookSizeRepresentation();
private:
    int numPages;

};


#endif //HWK7_PRINTEDBOOK_H
