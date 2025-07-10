//
//  Test.h
//  11.14.6
//
//  Created by Xander Noboa on 7/10/25.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert> // For assert()

using namespace std;

class Person {
public:
    Person(string userName);
    void befriend(Person& p);
    void unfriend(Person& p);
    string getName() const;
    string get_friend_names() const;
    int get_friend_count() const;

private:
    string firstName;
    vector<string> friendList;
};

// Constructor
Person::Person(string userName) : firstName(userName) {}

string Person::getName() const {
    return firstName;
}

void Person::befriend(Person& p) {
    if (find(friendList.begin(), friendList.end(), p.getName()) == friendList.end()) {
        friendList.push_back(p.getName());
    }
}

void Person::unfriend(Person& p) {
    auto it = remove(friendList.begin(), friendList.end(), p.getName());
    if (it != friendList.end()) {
        friendList.erase(it, friendList.end());
    }
}

string Person::get_friend_names() const {
    string result;
    for (const auto& name : friendList) {
        result += name + " ";
    }
    if (!result.empty()) result.pop_back(); // Remove trailing space
    return result;
}

int Person::get_friend_count() const {
    return friendList.size();
}

// === ✅ TEST CASES ===
void run_tests() {
    Person harry("Harry");
    Person ron("Ron");
    Person hermione("Hermione");
    Person ginny("Ginny");
    Person draco("Draco");
    Person duplicate("Ron");

    // Test 1: Initial friend count
    assert(harry.get_friend_count() == 0);
    assert(harry.get_friend_names() == "");

    // Test 2: Add one friend
    harry.befriend(ron);
    assert(harry.get_friend_count() == 1);
    assert(harry.get_friend_names() == "Ron");

    // Test 3: Add multiple friends
    harry.befriend(hermione);
    harry.befriend(ginny);
    assert(harry.get_friend_count() == 3);
    assert(harry.get_friend_names() == "Ron Hermione Ginny");

    // Test 4: Prevent duplicate friend
    harry.befriend(duplicate); // same name as Ron
    assert(harry.get_friend_count() == 3); // No duplicate added

    // Test 5: Unfriend someone
    harry.unfriend(ron);
    assert(harry.get_friend_count() == 2);
    assert(harry.get_friend_names() == "Hermione Ginny");

    // Test 6: Unfriend non-friend (should do nothing)
    harry.unfriend(draco);
    assert(harry.get_friend_count() == 2);
    assert(harry.get_friend_names() == "Hermione Ginny");

    // Test 7: Unfriend all
    harry.unfriend(hermione);
    harry.unfriend(ginny);
    assert(harry.get_friend_count() == 0);
    assert(harry.get_friend_names() == "");

    cout << "✅ All test cases passed successfully!" << endl;
}

int main() {
    run_tests();
    return 0;
}
