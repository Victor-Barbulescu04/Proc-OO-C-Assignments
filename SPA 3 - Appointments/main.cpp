//============================================================================
// Name        : main.cpp
// Author      : RWHasker - do not change this file
//============================================================================

// include each .h file twice - ensure headers and be read more than once
#include "date.h"
#include "appointments.h"

#include <iostream>
#include <fstream>
using namespace std;

// read appointments from cin and return a completed schedule object
Schedule read_schedule_from_cin();

int main(int argc, char *argv[]) {
    try {
        Schedule items = read_schedule_from_cin();
        if ( items.appointment_count() == 0 )
            cout << "Empty schedule." << endl;
        else
            items.write_to_cout();
    } catch (string& msg) {
        cout << "Abnormal termination: " << msg << endl;
    } catch (const char* msg) {
        cout << "Abnormal termination: " << msg << endl;
    }
  
    return 0;
}

Schedule read_schedule_from_cin() {
    Schedule result;
    int month;

    cin >> month;
    while ( cin ) {
        int day, year;
        char slash1, slash2, colon;
        string description;

        cin >> slash1 >> day >> slash2 >> year >> colon;
        if ( slash1 != '/' )
            throw "Missing / between month and day.";
        if ( slash2 != '/' )
            throw "Missing / between day and year.";
        if ( colon != ':' )
            throw "Missing colon after date.";
        getline(cin, description);
        result.add(Appointment(Date(month, day, year), description));
      
        cin >> month;
    }
    return result;
}