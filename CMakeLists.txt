cmake_minimum_required(VERSION 3.23)
project(HWK7)

set(CMAKE_CXX_STANDARD 14)

add_executable(HWK7 main.cpp AudioBook.cpp AudioBook.h EBook.cpp EBook.h PrintedBook.cpp PrintedBook.h Book.cpp Book.h Date.cpp Date.h Loan.cpp Loan.h Library.cpp Library.h Patron.cpp Patron.h CheckOutBookException.h DuplicateBookException.h DuplicatePatronException.h ReturnLoanException.h ReturnMismatchException.h)
