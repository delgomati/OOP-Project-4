//
// Created by Owner on 12/10/2022.
//

#ifndef HWK7_DUPLICATEPATRONEXCEPTION_H
#define HWK7_DUPLICATEPATRONEXCEPTION_H
#include <exception>
using namespace std;

class DuplicatePatronException: public exception {
public:
    virtual const char* what() const throw(){
        return "EXCEPTION: that patron has already been added";
    }

};
#endif //HWK7_DUPLICATEPATRONEXCEPTION_H
