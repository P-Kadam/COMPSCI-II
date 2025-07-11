//
//  main.cpp
//  Project 9.22.5
//
//  Created by Pradnya Kadam on 7/9/25.
//


//Battery Class
class Battery
{
public:
    Battery(double capacity);
    
    //drains the capacity of the battery by the given amount
    void drain(double amount);
    
    //charges the battery to its original capacity
    void charge();
    
    //gets the remaining capacity of the battery
    double get_remaining_capacity();
private:
    
    //helps class remember what the max_capacity of the battery is
    double max_capacity;
    
    //changes as the battery is charged/drained
    double battery_level;
};

//Constructor
Battery::Battery(double capacity)
{
    max_capacity = capacity;
    battery_level = capacity;
}

//decreases battery_level by specified amount
void Battery::drain(double amount)
{
    battery_level -= amount;
}

//recharges battery_level to max_capacity value
void Battery::charge()
{
    battery_level = max_capacity;
}

//returns the battery level
double Battery::get_remaining_capacity()
{
    return battery_level;
}

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
