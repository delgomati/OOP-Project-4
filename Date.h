//
// Created by Owner on 12/10/2022.
//

#ifndef HWK7_DATE_H
#define HWK7_DATE_H

#include <ctime>


class Date {
public:
    Date();
    Date(int year, int month, int day);

    bool isAfter(Date anotherDate) const;
    bool isAfter(int aYear, int aMonth, int aDay) const;

    static int currentYear();
    static int currentMonth();
    static int currentDay();

private:
    int day;
    int month;
    int year;
};



#endif //HWK7_DATE_H
