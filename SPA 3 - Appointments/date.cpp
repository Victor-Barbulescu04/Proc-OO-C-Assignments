//============================================================================
// Name        : date.cpp
// Author      : Victor Barbulescu
//============================================================================

//
// Make no changes to this file other than the TODOs below
//

#include "date.h"

#include <iostream>
#include <sstream>
using namespace std;

Date::Date(int month, int day, int year) : _month{month}, _day{day}, _year{year} {}

Date::Date() : _month{0}, _day{0}, _year{0} {}

int Date::month() const {
    return _month;
}

int Date::day() const {
    return _day;
}

int Date::year() const {
    return _year;
}

string Date::to_string() const
{
    // ostringstreams provide an cout-like interface but store the results
    //   in a std:string instead of files; this convert data into a string
    ostringstream formatted;
    if ( _month < 10 )
        formatted << "0";
    formatted << _month << "/";
    if ( _day < 10 )
        formatted << "0";
    formatted << _day << "/" << _year;

    return formatted.str();
}

bool Date::earlier(Date d1, Date d2) {
    // If year is less, d1 is earlier. Return true.
    if (d1.year() < d2.year()) {
        return true;
    }
    // If year is greater, d1 is not earlier. Return false.
    if (d1.year() > d2.year()) {
        return false;
    }

    // If years are equal, compare months
    if (d1.month() < d2.month()) {
        return true;
    }
    // If month is greater, d1 is not earlier. Return false.
    if (d1.month() > d2.month()) {
        return false;
    }

    // If months are equal, compare days
    return d1.day() < d2.day();
}

bool Date::check_valid_date(Date d) {
    // Check month
    if (d.month() < 1 || d.month() > 12) {
        cout << "ERROR: invalid month in " << d.to_string() << endl;
        return false;
    }

    // Check day
    switch (d.month()) {
        case 2: // February
            if (d.day() <= 0 || d.day() > 29) {
                cout << "ERROR: invalid day in " << d.to_string() << endl;
                return false;
            }
        break;
        case 1:  // January
        case 3:  // March
        case 5:  // May
        case 7:  // July
        case 8:  // August
        case 10: // October
        case 12: // December
            if (d.day() <= 0 || d.day() > 31) {
                cout << "ERROR: invalid day in " << d.to_string() << endl;
                return false;
            }
        break;
        case 4:  // April
        case 6:  // June
        case 9:  // September
        case 11: // November
            if (d.day() <= 0 || d.day() > 30) {
                cout << "ERROR: invalid day in " << d.to_string() << endl;
                return false;
            }
        break;
        default:
            return false;
    }

    // Check year
    if (d.year() < 2000 || d.year() > 3000) {
        cout << "ERROR: invalid year in " << d.to_string() << endl;
        return false;
    }


    return true;
}