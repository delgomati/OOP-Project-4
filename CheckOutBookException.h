//
// Created by Owner on 12/10/2022.
//

#ifndef HWK7_CHECKOUTBOOKEXCEPTION_H
#define HWK7_CHECKOUTBOOKEXCEPTION_H
#include <exception>
using namespace std;

class CheckOutBookException: public exception {
public:
    virtual const char* what() const throw(){
        return "EXCEPTION: that book has already been checked out";
    }

};

#endif //HWK7_CHECKOUTBOOKEXCEPTION_H
