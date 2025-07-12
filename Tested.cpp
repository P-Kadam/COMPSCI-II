//
//  main.cpp
//  14.12.1
//
//  Tested by Xander Noboa on 7/11/25.
//
// Created by Guillermo Chavarin

#include <iostream>
using namespace std;

class List {
private:
    struct Node {
        int   data;
        Node* next;
        Node* prev;
    };

    Node* first = nullptr;
    int   size  = 0;

public:
    /*------ basic life-cycle ------*/
    List()  = default;
    ~List() { clear(); }

    /*------ modifiers ------*/
    void add_back(int value) {
        Node* n = new Node{value, nullptr, nullptr};
        if (first == nullptr) {
            n->next = n->prev = n;
            first   = n;
        } else {
            Node* last = first->prev;
            last->next = n;
            n->prev    = last;
            n->next    = first;
            first->prev= n;
        }
        ++size;
    }

    void add_front(int value) {
        add_back(value);
        first = first->prev;
    }

    void remove_front() {
        if (first == nullptr) return;

        if (size == 1) {
            delete first;
            first = nullptr;
        } else {
            Node* victim = first;
            Node* last   = first->prev;
            first        = first->next;

            first->prev = last;
            last->next  = first;

            delete victim;
        }
        --size;
    }

    void remove_back() {
        if (first == nullptr) return;

        if (size == 1) {
            delete first;
            first = nullptr;
        } else {
            Node* victim = first->prev;
            Node* newLast = victim->prev;

            newLast->next = first;
            first->prev   = newLast;

            delete victim;
        }
        --size;
    }

    
    void clear() {
        while (size > 0) remove_front();
    }

   
    void print_forward() const {
        if (first == nullptr) return;
        Node* cur = first;
        for (int i = 0; i < size; ++i) {
            cout << cur->data << ' ';
            cur = cur->next;
        }
        cout << '\n';
    }

    void print_backward() const {
        if (first == nullptr) return;
        Node* cur = first->prev;          // last node
        for (int i = 0; i < size; ++i) {
            cout << cur->data << ' ';
            cur = cur->prev;
        }
        cout << '\n';
    }

    int get_size() const { return size; }
};

/*------(unchanged) ------*/
int main() {
    List clist;

    clist.add_back(10);
    clist.add_back(20);
    clist.add_back(30);
    clist.add_front(5);

    cout << "Forward: ";
    clist.print_forward();

    cout << "Backward: ";
    clist.print_backward();

    clist.remove_front();
    clist.remove_back();

    cout << "After removal - Forward: ";
    clist.print_forward();

    cout << "After removal - Backward: ";
    clist.print_backward();

    return 0;
}
