//
//  main.cpp
//  Project 9.22.4
//
//  Created by Pradnya Kadam on 7/9/25.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Person
{
    public:
        Person(string userName);
        void befriend(Person p);
        void unfriend(Person p);
        string getName() const;
        string get_friend_names();
    
        //newly added function 9.22.3
        int get_friend_count();
    
    private:
        string firstName;
    
        //new implementation of friends into vector - 9.22.4
        vector<string> friends;
    
};

//Constructor
Person::Person(string userName)
{
    firstName = userName;
}

string Person::getName() const
{
    return firstName;
}

//Function to add to friends string
void Person::befriend(Person p)
{
    //stores friend's name in vector
    friends.push_back(p.getName());
}

//removes person's name from friend string
void Person::unfriend(Person p)
{
    //iterates through friend vector to find name
    for(int i = 0; i < friends.size(); i++)
    {
        if(p.getName() == friends[i])
        {
            //ensures that the entire name is removed, rather than the last character
            friends.erase(friends.begin() + i);
        }
    }
}

//Returns the friend string
string Person::get_friend_names()
{
    //Doesn't change the output type
    //simply appends all friends' names to a string and outputs
    string friendsNames;
    
    for(int j = 0; j < friends.size(); j++)
    {
        friendsNames += friends[j] + " ";
    }
    
    return friendsNames;
}


//NEWLY ADDED 9.22.3 - implementation changed 9.22.4
int Person::get_friend_count()
{
    return friends.size();
}


//Main for testing
int main(int argc, const char * argv[]) {
    
    Person p1("Harry");
    
    Person p2("Ron");
    Person p3("Hermione");
    Person p4("Ginny");
    Person p5("Draco");
    
    p1.befriend(p2);
    p1.befriend(p3);
    p1.befriend(p4);
    p1.befriend(p5);
    
    cout << p1.get_friend_names() << endl;
    cout << p1.get_friend_count() << endl;
    
    p1.unfriend(p5);
    
    cout << p1.get_friend_names() << endl;
    cout << p1.get_friend_count() << endl;
}
