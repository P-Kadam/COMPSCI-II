//
//  main.cpp
//  10.13.1
//
//  Created by Pradnya Kadam on 7/9/25.
//

#include <iostream>
#include <ctime>
#include <string>

using namespace std;


//BASE CLASS
class Clock
{
public:
    virtual int get_hours();
    int get_minutes();
    string get_time();
};

int Clock::get_hours()
{
    time_t current_time = time(0);
    tm* local_time = localtime(&current_time);
    int hours = local_time->tm_hour;
    
    //formats the hours as a 12 hours clock
    if(hours > 12)
    {
        hours = hours - 12;
    }
    
    return hours;
}

int Clock::get_minutes()
{
    time_t current_time = time(0);
    tm* local_time = localtime(&current_time);
    int minutes = local_time->tm_min;
    
    return minutes;
}

string Clock::get_time()
{
    string minutes = to_string(get_minutes());
    
    
    if(minutes.size() == 1)
    {
        minutes.insert(0, 1, '0'); //formats minutes less than 10
    }
    else if(minutes.size() < 1)
    {
        minutes.insert(0, 2, '0'); //formats the minutes when clock strikes a new hour
    }
    
    
    string time = to_string(get_hours()) + ":" + minutes;
    return time;
}



//DERIVED CLASS
class WorldClock : public Clock
{
public:
    WorldClock(int userOffset);
    int get_hours() override;
private:
    int timeOffset;
};


//Constructor for derived class
WorldClock::WorldClock(int userOffset)
{
    timeOffset = userOffset;
}

//overriden get_hours() function to add the timeOffset
int WorldClock::get_hours()
{
    int hours = Clock::get_hours() + timeOffset;
    
    //formats the hours as a 12 hours clock
    if(hours > 12)
    {
        hours = hours - 12;
    }
    
    return hours;
}


int main(int argc, const char * argv[]) {
    
    Clock c1;
    
    cout << c1.get_time() << endl;
    
    Clock* NY = new WorldClock(3);
    
    cout << NY->get_time() << endl;
}
