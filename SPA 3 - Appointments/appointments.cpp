//============================================================================
// Name        : appointments.cpp
// Author      : Victor Barbulescu
//============================================================================

#include "appointments.h"
#include <string>
#include <iostream>
using namespace std;
// add other includes as needed here, but appointments.h must be the FIRST include

Appointment::Appointment(Date date, std::string description) {
    _date = date;

    // Clean description parameter
    // Remove leading spaces
    while (!description.empty() && description[0] == ' ') {
        description.erase(0, 1);
    }
    // Remove trailing spaces
    while (!description.empty() && description.back() == ' ') {
        description.pop_back();
    }

    _description = description;
}

Appointment::Appointment(){
    _date = Date(0,0,0);
    _description = "";
}

bool before(Appointment a, Appointment b) {
    return Date::earlier(a.date(), b.date());
}


void Schedule::add(Appointment new_appointment) {
    if (Date::check_valid_date(new_appointment.date())) {
        int pos = 0;

        // Find the correct position for the new appointment
        while (pos < num_appointments && before(appointments[pos], new_appointment)) {
            ++pos;
        }

        // Shifting logic
        for (int i = num_appointments; i > pos; --i) {
            appointments[i] = appointments[i - 1];
        }

        // Insertion logic
        if (pos < num_appointments) {
            appointments[pos] = new_appointment;
        } else {
            appointments[num_appointments] = new_appointment;
        }
        ++num_appointments;
    }
}

void Schedule::write_to_cout() const {
    for (int i = 0; i < num_appointments; ++i) {
        cout << appointments[i].date().to_string() << ": " << appointments[i].description() << endl;
    }
}

