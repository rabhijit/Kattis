/*
A0181059A
Abhijit Ravichandran
Lab Group 13
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int researchers, unlock_time; cin >> researchers >> unlock_time;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > arrivals;
    for (int i = 0; i < researchers; i++) {
        int arr_time, duration; cin >> arr_time >> duration;
        arrivals.push(make_pair(arr_time, arr_time+duration));
    }
    priority_queue<int, vector<int>, greater<int> > status;
    int savings = 0;
    while (researchers > 0) {
        pair<int, int> this_pair = arrivals.top();
        arrivals.pop();
        while (status.size() > 0 && this_pair.first > status.top() + unlock_time) {
            status.pop();
        }
        if (status.size() > 0 && this_pair.first >= status.top()) {
          status.pop();
          savings++;
        }
        status.push(this_pair.second);
        researchers--;
    }
    cout << savings << endl;
}
