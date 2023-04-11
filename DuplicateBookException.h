//
// Created by Owner on 12/10/2022.
//

#ifndef HWK7_DUPLICATEBOOKEXCEPTION_H
#define HWK7_DUPLICATEBOOKEXCEPTION_H
#include <exception>
using namespace std;

class DuplicateBookException: public exception {
public:
    virtual const char* what() const throw(){
        return "EXCEPTION: that book has already been added";
    }

};
#endif //HWK7_DUPLICATEBOOKEXCEPTION_H
