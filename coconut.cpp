/*
A0181059A
Abhijit Ravichandran
Lab Group 13
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int syllables, number;
    cin >> syllables >> number;
    vector<string> all_players;
    for (int i = 1; i <= number; i++) {
        all_players.push_back(to_string(i));
    }
    int selector = 0;
    while (all_players.size() > 1) {
        //cout << "*" << all_players[selector] << endl;
        for (int j = 0; j < syllables - 1; j++) {
            selector++;
            if (selector > all_players.size() - 1) {
                selector = 0;
            }
        }
        if (all_players[selector].back() != 'F' && all_players[selector].back() != 'P')
        {
            string new_s = "";
            new_s += all_players[selector];
            new_s += 'F';
            all_players[selector] = new_s;
            all_players.insert(all_players.begin()+selector+1, new_s);
        }
        else if (all_players[selector].back() == 'F') {
            all_players[selector].back() = 'P';
            selector++;
            if (selector > all_players.size() - 1) {
                selector = 0;
            }
        }
        else if (all_players[selector].back() == 'P') {
            all_players.erase(all_players.begin()+selector);
            if (selector > all_players.size() - 1) {
                selector = 0;
            }
        }
        
        for (int i = 0; i < all_players.size(); i++)
        {
            cout << all_players[i] << endl;
        }
        cout << "======" << endl;
        
    }
    if (all_players[0].back() == 'P' || all_players[0].back() == 'F') {
        all_players[0].pop_back();
    }
    cout << all_players[0] << endl;
}
