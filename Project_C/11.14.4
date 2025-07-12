//
//  main.cpp
//  11.14.4
//
//  Created by Xander Noboa on 7/11/25.
//

#include <iostream>
#include <string>
#include <memory>
using namespace std;

class PermutationIterator {
public:
    PermutationIterator(string s) : word(s), current_position(0), tail_iterator(nullptr) {
        if (!word.empty()) {
            setup_tail_iterator();
        }
    }

    bool has_more_permutations() {
        return current_position < word.length();
    }

    string next_permutation() {
        if (!has_more_permutations()) return "";

        if (tail_iterator && tail_iterator->has_more_permutations()) {
            string tail = tail_iterator->next_permutation();
            return word[current_position] + tail;
        } else {
            current_position++;
            setup_tail_iterator();
            return next_permutation();
        }
    }

private:
    string word;
    int current_position;
    unique_ptr<PermutationIterator> tail_iterator;

    void setup_tail_iterator() {
        if (current_position >= word.length()) return;

        string tail;
        for (int i = 0; i < word.length(); ++i) {
            if (i != current_position) tail += word[i];
        }

        if (!tail.empty()) {
            tail_iterator = make_unique<PermutationIterator>(tail);
        } else {
            tail_iterator = nullptr;
        }
    }
};


int main() {
    string input = "eat";
    PermutationIterator iter(input);

    while (iter.has_more_permutations()) {
        cout << iter.next_permutation() << endl;
    }

    return 0;
}
