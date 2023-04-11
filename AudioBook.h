//
// Created by Owner on 12/10/2022.
//

#ifndef HWK7_AUDIOBOOK_H
#define HWK7_AUDIOBOOK_H
#include "Book.h"
#include <cmath>

class AudioBook : public Book{
public:
    AudioBook(string aTitle, int durationSeconds);
    ~AudioBook();
    string getBookSizeRepresentation();
private:
    int durationSeconds;
};

#endif //HWK7_AUDIOBOOK_H
