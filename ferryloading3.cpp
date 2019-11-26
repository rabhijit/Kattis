/*
A0181059A
Abhijit Ravichandran
Lab Group 13
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int cases; cin >> cases;
    vector<vector<int>> all_timings;
    for (int i = 0; i < cases; i++) {
        int capacity, travel_time, number;
        cin >> capacity >> travel_time >> number;
        vector<int> timings(number, 0);
        vector<int> full_queue(10007, 0);
        queue<int> left_queue;
        queue<int> right_queue;
        int arr_time;
        string side;
        for (int j = 0; j < number; j++) {
            cin >> arr_time >> side;
            full_queue.at(j) = arr_time;
            if (side == "left") {
                left_queue.push(j);
            }
            else {
                right_queue.push(j);
            }
        }

        int timer = 0;
        int ship_side = 0;
        while (!(left_queue.size() == 0 && right_queue.size() == 0)) {
            int new_time;
            int ship_carrying = 0;
            if (left_queue.size() == 0) {
                new_time = full_queue.at(right_queue.front());
            }
            else if (right_queue.size() == 0) {
                new_time = full_queue.at(left_queue.front());
            }
            else {
                new_time = min(full_queue.at(left_queue.front()), full_queue.at(right_queue.front()));;
            }
            timer = max(timer, new_time);
            int counter = 0;
            if (ship_side == 0) {
                while (!(left_queue.size() == 0) && full_queue.at(left_queue.front()) <= timer && ship_carrying < capacity) {
                    timings.at(left_queue.front()) = timer + travel_time;
                    ship_carrying++;
                    left_queue.pop();
                }
            }
            else if (ship_side == 1) {
                while (!(right_queue.size() == 0) && full_queue.at(right_queue.front()) <= timer && ship_carrying < capacity) {
                    timings.at(right_queue.front()) = timer + travel_time;
                    ship_carrying++;
                    right_queue.pop();
                }
            }
            timer += travel_time;
            ship_side = (ship_side + 1) % 2;
        }
        all_timings.push_back(timings);
    }
    for (int k = 0; k < all_timings.size(); k++) {
        for (int m = 0; m < all_timings.at(k).size(); m++) {
            cout << (all_timings.at(k).at(m)) << endl;
        }
        if (k < all_timings.size() - 1) {
            cout << endl;
        }
    }
}
