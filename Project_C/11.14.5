//
//  main.cpp
//  11.14.5
//
//  Created by Xander Noboa on 7/11/25.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Swaps two integers
void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

// Reverses part of the array from i to j
void reverse(vector<int>& a, int i, int j) {
    while (i < j) {
        swap(a[i], a[j]);
        i++;
        j--;
    }
}

// Computes the next lexicographical permutation of a vector of integers
bool next_permutation(vector<int>& a) {
    for (int i = a.size() - 1; i > 0; i--) {
        if (a[i - 1] < a[i]) {
            int j = a.size() - 1;
            while (a[i - 1] > a[j]) {
                j--;
            }
            swap(a[i - 1], a[j]);
            reverse(a, i, a.size() - 1);
            return true;
        }
    }
    return false;
}

// ✅ Generates all permutations of a string (no recursion)
vector<string> generate_permutations(const string& s) {
    int n = s.length();
    vector<int> indices(n);
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }

    vector<string> permutations;

    do {
        string perm = "";
        for (int i = 0; i < n; i++) {
            perm += s[indices[i]];
        }
        permutations.push_back(perm);
    } while (next_permutation(indices));

    return permutations;
}

// ✅ Main function to test
int main() {
    string input = "eat";
    vector<string> perms = generate_permutations(input);

    for (const string& p : perms) {
        cout << p << endl;
    }

    return 0;
}
