/*
A0181059A
Abhijit Ravichandran
(no lab group assigned yet)
(no TA)
*/

#include <bits/stdc++.h>
using namespace std;

int max(vector<int> &colour_seg) {
    int maximum = 0;
    for (int i = 0; i < colour_seg.size(); i++) {
        if (colour_seg.at(i) > maximum) {
            maximum = colour_seg.at(i);
        }
    }
    return maximum;
}

int main() {
    int cases;
    cin >> cases;
    vector<int> results;
    for (int i = 0; i < cases; i++) {
        vector<int> blue_seg{};
        vector<int> red_seg{};
        int seg_number;
        cin >> seg_number;
        for (int j = 0; j < seg_number; j++) {
            string input;
            cin >> input;
            if (input.back() == 'B') {
                input.pop_back();
                blue_seg.push_back(stoi(input));
            }
            else {
                input.pop_back();
                red_seg.push_back(stoi(input));
            }
        }
        int sum = 0;
        int knots = 0;
        sort(blue_seg.begin(), blue_seg.end()); reverse(blue_seg.begin(), blue_seg.end());
        sort(red_seg.begin(), red_seg.end()); reverse(red_seg.begin(), red_seg.end());
        int loops = (blue_seg.size() <= red_seg.size()) ? blue_seg.size() : red_seg.size();
        for (int k = 0; k < loops; k++) {
            sum += (blue_seg.at(k) + red_seg.at(k));
            knots++;
        }
        results.push_back(sum - (loops + knots));
    }
    for (int k = 0; k < results.size(); k++) {
        cout << "Case #" << k+1 << ": " << results.at(k) << endl;
    }
}
