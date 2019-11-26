/*
A0181059A
Abhijit Ravichandran
Lab Group 13
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int cases; cin >> cases;
    for (int i = 0; i < cases; i++) {
        int number; cin >> number;
        int max_counter = 0;
        vector<pair<string, string>> people;
        vector<int> counters;
        for (int j = 0; j < number; j++) {
            int counter = 0;
            string person, status, discard;
            cin >> person >> status >> discard;
            person.pop_back();
            stringstream ss(status);
            string dummy;
            while (getline(ss, dummy, '-')) {
                counter++;
            }
            if (counter > max_counter) {
                max_counter = counter;
            }
            counters.push_back(counter);
            people.push_back(make_pair(person, status));
        }
        for (int k = 0; k < people.size(); k++) {
            if (counters[k] != max_counter) {
                while (counters[k] != max_counter) {
                    people[k].second.insert(0, "middle-");
                    counters[k]++;
                }
            }
        }
        sort(people.begin(), people.end(), [](pair<string, string> p1, pair<string, string> p2) {
            stringstream ss1(p1.second);
            stringstream ss2(p2.second);
            string dummy;
            int counter = 0;
            int counter1 = 0, counter2 = 0;
            while (getline(ss1, dummy, '-')) {
                if (dummy == "lower") {
                    counter1 += (1 * pow(10, counter));
                }
                else if (dummy == "middle") {
                    counter1 += (2 * pow(10, counter));
                }
                else if (dummy == "upper") {
                    counter1 += (3 * pow(10, counter));
                }
                counter++;
            }
            counter = 0;
            while (getline(ss2, dummy, '-')) {
                if (dummy == "lower") {
                    counter2 += (1 * pow(10, counter));
                }
                else if (dummy == "middle") {
                    counter2 += (2 * pow(10, counter));
                }
                else if (dummy == "upper") {
                    counter2 += (3 * pow(10, counter));
                }
                counter++;
            }
            if (counter1 != counter2) {
                return counter1 > counter2;
            }
            else {
                return p1.first < p2.first;
            }
        });
        for (int m = 0; m < people.size(); m++) {
            cout << people[m].first << endl;
        }
        for (int n = 0; n < 30; n++) {
            cout << "=";
        }
        cout << endl;
    }
}
