//
//  main.cpp
//  Project 7.22.2
//
//  Created by Pradnya Kadam on 7/3/25.

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
        string friends;
    
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
    //check if friends is empty, add the first name
    if(friends.empty())
    {
        friends += p.getName();
    }
    // otherwise adds to the list of friends
    else{
        friends = friends + " " + p.getName();
    }
}

//removes person's name from friend string
void Person::unfriend(Person p)
{
    stringstream strm(get_friend_names());
    string name;
    
    string updatedFriendList;
    
    while(strm >> name)
    {
        if(name != p.getName())
        {
            updatedFriendList = updatedFriendList + name + " ";
        }
        
    }
    
    friends = updatedFriendList;
}

//Returns the friend string
string Person::get_friend_names()
{
    return friends;
}


//NEWLY ADDED 9.22.3
int Person::get_friend_count()
{
    int count = 0;
    
    stringstream strm(get_friend_names());
    string name;
    
    //counts each name based off of space separation between friend names
    while(strm >> name)
    {
        count++;
    }
    
    return count;
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
