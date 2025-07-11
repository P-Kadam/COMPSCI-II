//
//  Test.cpp
//  11.14.6
//
//  Created by Xander Noboa on 7/10/25.
//

#include <iostream>
#include <cassert>
using namespace std;

// Battery Class Definition
class Battery {
public:
    Battery(double capacity);
    void drain(double amount);
    void charge();
    double get_remaining_capacity();
private:
    double max_capacity;
    double battery_level;
};

// Constructor
Battery::Battery(double capacity) {
    max_capacity = capacity;
    battery_level = capacity;
}

// Decrease battery_level
void Battery::drain(double amount) {
    battery_level -= amount;
    if (battery_level < 0) battery_level = 0; // Prevent negative level
}

// Restore to max
void Battery::charge() {
    battery_level = max_capacity;
}

// Get remaining capacity
double Battery::get_remaining_capacity() {
    return battery_level;
}

// === ✅ TEST CASES ===
void run_tests() {
    Battery b1(100.0);

    // Test 1: Initial capacity
    assert(b1.get_remaining_capacity() == 100.0);

    // Test 2: Drain battery
    b1.drain(30.5);
    assert(b1.get_remaining_capacity() == 69.5);

    // Test 3: Drain more
    b1.drain(10);
    assert(b1.get_remaining_capacity() == 59.5);

    // Test 4: Over-drain (should not go negative)
    b1.drain(1000);
    assert(b1.get_remaining_capacity() == 0.0);

    // Test 5: Charge back to full
    b1.charge();
    assert(b1.get_remaining_capacity() == 100.0);

    cout << "✅ All Battery tests passed!" << endl;
}

int main() {
    run_tests();
    return 0;
}
