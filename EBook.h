//
// Created by Owner on 12/10/2022.
//

#ifndef HWK7_EBOOK_H
#define HWK7_EBOOK_H

#include "Book.h"
#include <cmath>

class EBook : public Book{
public:
    EBook(string aTitle, int sizeCharacters, int charsPerPage);
    ~EBook();
    string getBookSizeRepresentation();

private:
    int sizeCharacters;
    int charsPerPage;
};


#endif //HWK7_EBOOK_H
