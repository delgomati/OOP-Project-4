//
// Created by Owner on 12/10/2022.
//

#ifndef HWK7_RETURNLOANEXCEPTION_H
#define HWK7_RETURNLOANEXCEPTION_H
#include <exception>
using namespace std;

class ReturnLoanException: public exception {
public:
    virtual const char* what() const throw(){
        return "EXCEPTION: that book is not loaned";
    }

};

#endif //HWK7_RETURNLOANEXCEPTION_H
