//
//  main.cpp
//  10.13.3
//
//  Created by Pradnya Kadam on 7/11/25.
//

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

//BASE CLASS:
class Appointment
{
public:
    Appointment(string apptDes, int apptDay, int apptMonth, int apptYear, int apptTime);
    virtual bool occurs_on(int year, int month, int day);
protected:
    string description;
    int day;
    int month;
    int year;
    int time;
};

//Constructor
Appointment::Appointment(string apptDes, int apptDay, int apptMonth, int apptYear, int apptTime)
{
    description = apptDes;
    day = apptDay;
    month = apptMonth;
    year = apptYear;
    time = apptTime;
}


bool Appointment::occurs_on(int year, int month, int day)
{
    return (this->year == year && this->month == month && this->day == day);
}


// ============================
// DERIVED CLASS: OneTime
// ============================
class OneTime : public Appointment
{
public:
    using Appointment::Appointment;
    //no changes to occurs_on function
};


// ============================
// DERIVED CLASS: Daily
// ============================
class Daily : public Appointment
{
public:
    using Appointment::Appointment;
    bool occurs_on(int year, int month, int day) override;
};

//Overriden occurs_on function
bool Daily::occurs_on(int year, int month, int day)
{
    //happens everyday
    return true;
}


// ============================
// DERIVED CLASS: Weekly
// ============================
class Weekly : public Appointment
{
public:
    using Appointment::Appointment;
    bool occurs_on(int year, int month, int day) override;
};

//Overriden occurs_on function
bool Weekly::occurs_on(int year, int month, int day)
{
    //even if a different day is given, will check to make sure that
    //appt. is on the same day of the week each week
    
    int num_days_in_month = 30;
    
    if(month % 2 == 1 || month == 8)
    {
        num_days_in_month = 31;
    }
    else if (month == 2)
    {
        if(year % 4 == 0)
        {
            num_days_in_month = 29;
        }
        else{
            num_days_in_month = 28;
        }
    }
    
    //calculating the number of days since the date given in the constructor
    int day_calc = (year - this->year) * 365 + (month - this->month)* num_days_in_month + (day - this->day);
    return (day_calc % 7 == 0);
}


// ============================
// DERIVED CLASS: Monthly
// ============================
class Monthly : public Appointment
{
public:
    using Appointment::Appointment;
    bool occurs_on(int year, int month, int day) override;
};

//Overriden occurs_on function
bool Monthly::occurs_on(int year, int month, int day)
{
    //ensures that the day of the month is the same
    return (this->day == day);
}




int main(int argc, const char * argv[]) {
    
    // ============================
    //TEST CASES: Pradnya Kadam
    // ============================
    
    vector<Appointment*> Planner;
    
    //Appointment::Appointment(string apptDes, int apptDay, string apptMonth, int apptYear, int apptTime)

    //Math test: happens weekly on Friday
    Appointment* mathTest = new Weekly("Take math test", 11, 7, 2025, 2);
    
    //Work: happens daily
    Appointment* work = new Daily("Go to work at the coffee shop", 1, 7, 2025, 4);
    
    //Hike: happens monthly
    Appointment* hike = new Monthly("Go on a hike with friends", 17, 8, 2025, 2);
    
    //Special meeting: happens only once
    Appointment* meeting = new OneTime("Meet with executive", 20, 7, 2025, 2);
    
    Planner.push_back(mathTest);
    Planner.push_back(work);
    Planner.push_back(hike);
    Planner.push_back(meeting);
    
    // ============================
    //ASSERT STATEMENTS:
    // ============================
    
    assert(mathTest->occurs_on(2025, 7, 25) == true); //testing for same month
    assert(mathTest->occurs_on(2025, 8, 1) == true); //testing for different month
    assert(mathTest->occurs_on(2025, 7, 26) == false); //check if false condition works
    
    assert(work->occurs_on(2027, 12, 12) == true); //should always be true
    assert(work->occurs_on(2029, 3, 16) == true);
    
    assert(hike->occurs_on(2027, 4, 17) == true);
    assert(hike->occurs_on(2027, 11, 17) == true);
    assert(hike->occurs_on(2027, 4, 1) == false); //different day-- should be false
    
    assert(meeting->occurs_on(2025, 7, 20) == true);
    assert(meeting->occurs_on(2025, 3, 20) == false); //month is different-- false
    
    cout << "ALL TESTS PASSED!" << endl;
}
