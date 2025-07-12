//
//  main.cpp
//  Project 7.20.8
//
//  Created by Pradnya Kadam on 7/2/25.
//

#include <iostream>
#include <string>
#include <sstream>


using namespace std;

//Student Structure
struct Student
{
    //Student structure stores student first/last name & grade
    string firstName;
    string lastName;
    
    char courseGrade;
};


//Print function
void PrintInfo(vector<Student*> students)
{
    char grades[5] = {'A', 'B', 'C', 'D', 'F'};
    
    //for each grade letter of interest...
    for (int j = 0; j < 5; j++)
    {
        //for each student...
        for (int k = 0; k < students.size(); k++)
        {
            //if the student's grade matches the grade of interest, print the student's info
            if(students[k]->courseGrade == grades[j])
            {
                cout << students[k]->firstName << " "
                << students[k]->lastName << " "
                << students[k]->courseGrade << endl;
            }
        }
    }
    
    
};

int main(int argc, const char * argv[]) {
    
    //storing input ofr
    string input;
   
    //requests user input-- defines termination case
    cout << "Please enter the Student's (1) first name (2) last name (3) grade!" << endl;
    cout << "Enter '-1' when complete!" << endl;
    
    //vector to store Students
    vector<Student*> students;
    
    //continues taking user input
    while (true)
    {
        //getting entire line of user input
        getline(cin, input);
        
        //exit criteria -- user enters "-1"
        if(input == "-1")
        {
            break;
        }
        
        //converts user input to a stringstream to be parsed
        stringstream strm(input);
        
        string fName; //first name
        string lName; // last name
        char grade; //grade
        
        //separates the three components
        strm >> fName >> lName >> grade;
        
        //check to see if all courseGrade is valid input
        if(!isalpha(grade))
        {
            cout << "ERROR: invalid grade" << endl;
            break;
        }
        else
        {
            //array containing all valid grade entries
            //not including lowercase entries
            char grades[5] = {'A', 'B', 'C', 'D', 'F'};
        
            bool isValid = false;
            
            //loop through each grade letter
            for (int i = 0; i < 5; i++)
            {
                //verifies whether entered courseGrade is contained within valid courseGrades array
                if(grades[i] == grade)
                {
                    isValid = true;
                }
            }
            
            //if the grade is not valid, throw error
            if(!isValid)
            {
                cout << "ERROR: invalid grade" << endl;
                break;
            }
                
        }
        
        //allocates a new student structure
        Student* ptr = new Student;
        
        //assigns values to data members
        ptr->firstName = fName;
        ptr->lastName = lName;
        ptr->courseGrade = grade;
        
        students.push_back(ptr);
    }
    
    PrintInfo(students);
}
