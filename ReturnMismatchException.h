//
// Created by Owner on 12/10/2022.
//

#ifndef HWK7_RETURNMISMATCHEXCEPTION_H
#define HWK7_RETURNMISMATCHEXCEPTION_H
#include <exception>
using namespace std;

class ReturnMismatchException: public exception {
public:
    virtual const char* what() const throw(){
        return "EXCEPTION: that book was not checked out by that patron";
    }

};
#endif //HWK7_RETURNMISMATCHEXCEPTION_H
