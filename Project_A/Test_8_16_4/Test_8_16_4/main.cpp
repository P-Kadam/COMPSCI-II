//8.16.4//
//Guillermo Chavarin//

//TESTED/CHECKED: Pradnya Kadam

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    
    //==================
    //TESTING - adding more names to the file - unequal number of name
    //==================
    
    ofstream testInput("babynames.txt");
    testInput << "Michael, Jessica\n";
    testInput << "Christopher, Ashley\n";
    testInput << "Matthew, Brittany\n";
    testInput << "Joshua, Amanda\n";
    
    //Added more names
    testInput << "James, Olivia\n";
    
    testInput.close();

    ifstream inputFile("babynames.txt");
    ofstream boysFile("boynames.txt");
    ofstream girlsFile("girlnames.txt");
    

    if (!inputFile || !boysFile || !girlsFile) {
        cerr << "File error.\n";
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string boyName, girlName;

        if (getline(ss, boyName, ',') && getline(ss, girlName)) {
            boyName.erase(0, boyName.find_first_not_of(" \t\r\n"));
            boyName.erase(boyName.find_last_not_of(" \t\r\n") + 1);
            girlName.erase(0, girlName.find_first_not_of(" \t\r\n"));
            girlName.erase(girlName.find_last_not_of(" \t\r\n") + 1);

            boysFile << boyName << endl;
            girlsFile << girlName << endl;
        }
    }

    inputFile.close();
    boysFile.close();
    girlsFile.close();

    ifstream boysOut("boynames.txt");
    ifstream girlsOut("girlnames.txt");

    string name;
    cout << "\nBoy Names:\n";
    while (getline(boysOut, name)) {
        cout << name << endl;
    }

    cout << "\nGirl Names:\n";
    while (getline(girlsOut, name)) {
        cout << name << endl;
    }
    
    
    
    
    
    
    
    return 0;
}
