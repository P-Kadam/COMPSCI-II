//10.13.1//
//Programmer: Guillermo Chavarin//
//Tester: Guillermo Chavarin & Pradnya Kadam

#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>


using namespace std;

class Clock {
public:
    
    virtual int get_hours() const {
        time_t current_time = time(0);
        tm* local_time = localtime(&current_time);
        return local_time->tm_hour;
    }

    
    virtual int get_minutes() const {
        time_t current_time = time(0);
        tm* local_time = localtime(&current_time);
        return local_time->tm_min;
    }

    
    string get_time() const {
        stringstream ss;
        ss << setfill('0') << setw(2) << get_hours() << ":"
           << setfill('0') << setw(2) << get_minutes();
        return ss.str();
    }
};

class WorldClock : public Clock {
private:
    int offset;

public:
    WorldClock(int time_offset) {
        offset = time_offset;
    }

    
    int get_hours() const override {
        int local_hour = Clock::get_hours();
        int adjusted_hour = (local_hour + offset) % 24;
        if (adjusted_hour < 0) adjusted_hour += 24;
        return adjusted_hour;
    }
    
    
};


//TEST CASE FUNCTION: Pradnya Kadam
void print_time(Clock* clock)
{
    if(clock->get_hours() >= 12)
    {
        cout << "Time:      " << clock->get_hours() - 12 << ":" << clock->get_minutes() << " PM" << endl;
    }
    else{
        cout << "Time:      " << clock->get_hours() << ":" << clock->get_minutes() << " AM" << endl;
    }
}






int main() {
    Clock local_clock;
    WorldClock ny_clock(3);
    WorldClock london_clock(8);

    cout << "Local Time:      " << local_clock.get_time() << endl;
    cout << "New York Time:   " << ny_clock.get_time() << endl;
    cout << "London Time:     " << london_clock.get_time() << endl;
    
    //MORE TEST CASES: Pradnya Kadam
    cout << endl;
    
    WorldClock india_clock(13);
    WorldClock singapore_clock(15);
    cout << "India Time:     " << india_clock.get_time() << endl;
    
    cout << endl;

    
    Clock* local_clock_ptr = &local_clock;
    Clock* ny_clock_ptr = &ny_clock;
    Clock* london_clock_ptr = &london_clock;
    Clock* india_clock_ptr = &india_clock;
    Clock* singapore_clock_ptr = &singapore_clock;
    
    print_time(local_clock_ptr);
    print_time(ny_clock_ptr);
    print_time(london_clock_ptr);
    print_time(india_clock_ptr);
    print_time(singapore_clock_ptr);



    
    
    
    return 0;
}
