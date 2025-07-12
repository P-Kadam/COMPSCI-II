//
//  main.cpp
//  12.17.1
//
//  Created by Xander Noboa on 7/11/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

// Function to perform the QuickSelect algorithm
int quickselect(vector<int>& data, int k, int a, int b) {
    if (b - a <= 1) return data[a];

    // Pick a pivot randomly
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(a, b - 1);
    int pivot = data[dis(gen)];

    // Partition the data into < pivot, = pivot, > pivot
    vector<int> less, equal, greater;
    for (int i = a; i < b; ++i) {
        if (data[i] < pivot)
            less.push_back(data[i]);
        else if (data[i] == pivot)
            equal.push_back(data[i]);
        else
            greater.push_back(data[i]);
    }

    int n1 = less.size();
    int n2 = equal.size();

    if (k < n1)
        return quickselect(less, k, 0, n1);
    else if (k < n1 + n2)
        return pivot;
    else
        return quickselect(greater, k - n1 - n2, 0, greater.size());
}

// Function to compute the median using QuickSelect
int median_quickselect(vector<int> data) {
    int n = data.size();
    return quickselect(data, n / 2, 0, n);
}

// Function to compute the median by sorting
int median_sort(vector<int> data) {
    sort(data.begin(), data.end());
    return data[data.size() / 2];
}

int main() {
    const int SIZE = 1'000'000;
    vector<int> sequence(SIZE);

    // Generate random sequence
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1'000'000);

    for (int i = 0; i < SIZE; ++i) {
        sequence[i] = dis(gen);
    }

    // Copy for both methods
    vector<int> copy1 = sequence;
    vector<int> copy2 = sequence;

    // Time QuickSelect median
    auto start1 = chrono::high_resolution_clock::now();
    int median1 = median_quickselect(copy1);
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> time1 = end1 - start1;

    // Time sort + median
    auto start2 = chrono::high_resolution_clock::now();
    int median2 = median_sort(copy2);
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double> time2 = end2 - start2;

    // Results
    cout << "Median (QuickSelect): " << median1 << " | Time: " << time1.count() << " seconds\n";
    cout << "Median (Sort):        " << median2 << " | Time: " << time2.count() << " seconds\n";

    return 0;
}
