//
//  main.cpp
//  11.14.8
//
//  Created by Xander Noboa on 7/11/25.
//

#include <iostream>
#include <memory>
#include <string>
using namespace std;

class DiskMover {
public:
    DiskMover(int n, int source, int target)
        : n(n), source(source), target(target), state(BEFORE_LARGEST) {
        if (n > 1) {
            spare = 6 - source - target;
            helper = make_unique<DiskMover>(n - 1, source, spare);
        }
    }

    bool has_more_moves() {
        return state != DONE;
    }

    string next_move() {
        switch (state) {
            case BEFORE_LARGEST:
                if (helper && helper->has_more_moves()) {
                    return helper->next_move();
                } else {
                    helper.reset();
                    state = LARGEST;
                }
                [[fallthrough]];

            case LARGEST:
                state = AFTER_LARGEST;
                return "Move disk from peg " + to_string(source) + " to peg " + to_string(target);

            case AFTER_LARGEST:
                if (!after_helper) {
                    after_helper = make_unique<DiskMover>(n - 1, spare, target);
                }
                if (after_helper->has_more_moves()) {
                    return after_helper->next_move();
                } else {
                    after_helper.reset();
                    state = DONE;
                    return "";
                }

            case DONE:
                return "";
        }
        return "";
    }

private:
    enum State { BEFORE_LARGEST, LARGEST, AFTER_LARGEST, DONE };
    int n;
    int source;
    int target;
    int spare;
    State state;
    unique_ptr<DiskMover> helper;
    unique_ptr<DiskMover> after_helper;
};

int main() {
    DiskMover mover(5, 1, 3);
    while (mover.has_more_moves()) {
        string move = mover.next_move();
        if (!move.empty()) {
            cout << move << endl;
        }
    }
    return 0;
}
