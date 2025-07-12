//
//  main.cpp
//  8.16.8
//
//  Created by Pradnya Kadam on 7/11/25.
//Tested: Pradnya Kadam
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int ALPHABET_SIZE = 26;
const double ENGLISH_FREQ[ALPHABET_SIZE] =
{
    8.2,  // A
    1.0,  // B
    3.0,  // C
    4.0,  // D
    13.0, // E
    3.0,  // F
    2.0,  // G
    4.0,  // H
    7.0,  // I
    0.2,  // J
    0.8,  // K
    4.0,  // L
    3.0,  // M
    8.0,  // N
    7.0,  // O
    3.0,  // P
    0.2,  // Q
    8.0,  // R
    6.0,  // S
    9.0,  // T
    3.0,  // U
    1.0,  // V
    2.0,  // W
    0.2,  // X
    2.0,  // Y
    0.1   // Z
};


int main(int argc, const char * argv[]) {
    
    //==================
    //TEST CASES:
    //==================
    
    string filename = "secretmessage.txt";
    ofstream testInput(filename);
    testInput << "This is a secret message";
    
    testInput.close();
    
//    cin >> filename;
    
    ifstream inputFile(filename);
    
    if(!inputFile)
    {
        cout << "Could not open input file" << endl;
        return 1;
    }
    
    int letterCounts[ALPHABET_SIZE] = {0};
    int totalLetters = 0;
    char ch;
    
    while(inputFile.get(ch))
    {
        //checks whether the character is part of the alphabet
        if(isalpha(ch))
        {
            //converts the character to uppercase if not already
            ch = toupper(ch);
            
            //Adds the character based on the ACSII numbers --> gives pos
            letterCounts[ch - 'A']++;
            totalLetters++;
        }
    }
    
    inputFile.close();
    
    cout << "Table for Letter Frequencies:" << endl;
    cout << endl;
    cout << left  << "     Letter"
                  << "     Count"
                  << "     Actual(%)"
                  << "     Expected(%)" << endl;
    cout << "---------------------------------------------------" << endl;
    
    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        char letter = 'A' + i;
        int count = letterCounts[i];
        //        double actualPercent = (totalLetters > 0) ? (100.0 * count / totalLetters) : 0.0;
        
        cout << setw(6) << letter
        << setw(8) << count
        << fixed << setprecision(2)
        //         << setw(10) << actualPercent
        << setw(12) << ENGLISH_FREQ[i] << endl;
    }
    
    
    
    return 0;
}
