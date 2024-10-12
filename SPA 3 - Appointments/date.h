//
// Created by barbulescuv on 10/12/2024.
//

#ifndef DATE_H
#define DATE_H
#include <string>


class Date {
private:
    int _year;
    int _month;
    int _day;
public:
    Date();
    Date(int year, int month, int day);

    int month() const;
    int day() const;
    int year() const;

    std::string to_string() const;

    static bool earlier(Date d1, Date d2);
    static bool check_valid_date(Date d);
};



#endif //DATE_H
